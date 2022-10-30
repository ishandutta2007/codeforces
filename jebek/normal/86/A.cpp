#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long a[20];

bool check(int s1,int s2,int x)
{
   // cout<<s1<<" "<<s2<<" "<<a[x]<<" "<<x<<endl;
    if(s1/a[x]==s2/a[x])
        return true;
    return false;
}

long long javab(long long c)
{
    long long d=c,q=0;
    int i=0;
    while(d)
    {
        q+=(9-d%10)*a[i];
        d/=10;
        i++;
    }
    return q*c;
}

long long l,r,MAX,l2,r2;
vector<long long>ans,ans1,v1,v2;

int main()
{
    cin>>l>>r;
    l2=l;r2=r;
    while(l>0)
    {
        v1.push_back(l%10);
        l/=10;
    }
    while(r>0)
    {
        v2.push_back(r%10);
        r/=10;
    }
    l=l2;r=r2;
    int x=v2.size();
    while(v1.size()<v2.size())
        v1.push_back(0);
    a[0]=1;
    for(int i=1;i<11;i++)
        a[i]=a[i-1]*10;
    ans.push_back(0);
    for(int i=x-1;i>-1;i--)
    {
        MAX=0;
        for(int j=0;j<ans.size();j++)
        {
            int l1=0,r1=9;
            if(check(ans[j],l,i+1))
                l1=v1[i];
           // cout<<l1<<" "<<r1<<" "<<l<<" "<<r<<endl;
            if(check(ans[j],r,i+1))
                r1=v2[i];
            long long y=ans[j]+a[i]*l1;
            //    cout<<l1<<" "<<r1<<endl;
            for(int u=l1;u<=r1;u++)
            {
                long long ans2=javab(y);
                if(MAX==ans2)
                    ans1.push_back(y);
                else if(MAX<ans2)
                {
                    ans1.clear();
                    MAX=ans2;
                    ans1.push_back(y);
                }
                y+=a[i];
            }
        }
        ans=ans1;
        ans1.clear();
    }
    cout<<javab(ans.back())<<endl;
}