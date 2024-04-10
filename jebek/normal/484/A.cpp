#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long l,r,ans,n,p,f[80];
vector<int>v1,v;

int main()
{
    cin>>n;
    f[0]=1;
    for(int i=1;i<=70;i++)
        f[i]=f[i-1]*2;
    for(int i=0;i<n;i++)
    {
        v1.clear();v.clear();
        cin>>l>>r;
        r++;
        while(l>0){
            v.push_back(l%2);
            l/=2;
        }
        while(r>0)
        {
            v1.push_back(r%2);
            r/=2;
        }
        ans=0;
        if(v1.size()>v.size())
        {
            for(int i=0;i<v1.size()-1;i++)
                ans+=f[i];
        }
        else
        {
            for(int i=0;i<v.size();i++)
                if(v[i]==0 && v1[i]==1)
                    p=i;
            for(int i=0;i<p;i++)
                ans+=f[i];
            for(int i=p+1;i<v.size();i++)
                if(v[i]==1)
                    ans+=f[i];
               // if(v[i]==1)
        //    cout<<p<<endl;
        }
        cout<<ans<<endl;
    }
}