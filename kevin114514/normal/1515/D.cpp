#include<bits/stdc++.h>
using namespace std;
int cntl[200200],cntr[200200];
int L[200200],R[200200];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        for(int i=1;i<=n;i++)
            cntl[i]=cntr[i]=0;
        if(l>r)
        {
            for(int i=0;i<l;i++)
                cin>>R[i];
            for(int i=0;i<r;i++)
                cin>>L[i];
            swap(l,r);
        }
        else
        {
            for(int i=0;i<l;i++)
                cin>>L[i];
            for(int i=0;i<r;i++)
                cin>>R[i];
        }
        int delta=r-l;
        delta/=2;
        for(int i=0;i<l;i++)
            cntl[L[i]]++;
        for(int i=0;i<r;i++)
            cntr[R[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++)
        if(cntr[i]>cntl[i])
        {
            int mn=min(delta,(abs(cntr[i]-cntl[i]))/2);
            if(cntr[i]>=cntl[i])
            {
            	cntr[i]-=mn+mn;
            	r-=mn+mn;
			}
			else
			{
				cntl[i]-=mn+mn;
				l-=mn+mn;
			}
            delta-=mn;
            ans+=mn;
        }
        for(int i=1;i<=n;i++)
        {
            int mn=min(cntl[i],cntr[i]);
            cntl[i]-=mn;
            cntr[i]-=mn;
            l-=mn;
            r-=mn;
        }
        ans+=(abs(l-r))/2;
        ans+=(l+r)/2;
        cout<<ans<<endl;
    }
    return 0;
}