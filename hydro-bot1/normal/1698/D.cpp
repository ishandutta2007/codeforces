// Hydro submission #62d29c6a75c677124c8ecae2@1657969771285
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,l,r,m,s,a,i; 
    cin>>t;
    while(t--)
	{
        cin>>n;
        l=1,r=n;
        while(l<r)
		{ 
            m=(l+r)/2;
            printf("? %d %d",l,m);
			cout<<endl;s=0;
            for(i=l;i<=m;i++)
			{
                cin>>a;
                if(a>=l&&a<=m) s++;
            } 
            if(s%2) r=m;
            else l=m+1;
        }
        printf("! %d",l);
		cout<<endl;
    }
}