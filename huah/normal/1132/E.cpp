#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace IOfactory
{
    template<typename T> 
    void read(vector<T>&a,int l=0,int r=-1)
    {
        if(r==-1) r=a.size()-1;
        for(int i=l;i<=r;++i) cin>>a[i];
    }
    template<typename T> 
    void println(vector<T>&a,int l=0,int r=-1)
    {
        if(r==-1) r=a.size()-1;
        for(int i=l;i<=r;++i) cout<<a[i]<<" \n"[i==r];
    }
    template<typename T> 
    void println(T x)
    {
        cout<<x<<'\n';
    }
}
using namespace IOfactory;
#define inf 0x3f3f3f3f
int main()
{
    vector<vector<vector<pair<int,int>>>>vc(9);
    vector<pair<int,int>>g;
    function<void(int,int)>dfs=[&](int sum,int val)
    {
        if(val==0)
        {
            vc[sum].push_back(g);
            return;
        }
        for(int i=0;i*val<sum;++i)
        {
            if(i) g.push_back({val,-i});
            dfs(sum-i*val,val-1);
            if(i) g.pop_back();
        }
    };
    for(int i=1;i<=8;++i)
    {
        g.push_back({i,1});
        dfs(i,i-1);
        g.pop_back();
    }

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll h;cin>>h;
        vector<ll>a(9);
        for(int i=1;i<=8;++i) cin>>a[i];
        ll sum=0;
        for(int i=1;i<=8;++i) sum+=a[i]*i;
        if(sum<=h) cout<<sum<<'\n';
        else
        {
            vector<ll>b(9);
            sum=0;
            for(int i=1;i<=8;++i)
            {
                if(sum+a[i]*i<=h) b[i]=a[i],sum+=a[i]*i,a[i]=0;
                else
                {
                    b[i]=(h-sum)/i;
                    sum+=b[i]*i;
                    a[i]-=b[i];
                }
            }
            bool flag=true;
            while(flag)
            {
                flag=false;
                for(int i=h-sum;i>=1&&!flag;--i)
                    for(auto &c:vc[i])
                    {
                        bool ok=true;
                        for(auto &[val,i]:c)
                            if(i>0)
                            {
                                if(a[val]<i) ok=false;
                            }
                            else
                            {
                                if(b[val]<-i) ok=false;
                            }
                        if(ok)
                        {
                            sum+=i;
                            for(auto &[val,i]:c)
                                if(i>0)
                                {
                                    a[val]-=i;
                                    b[val]+=i;
                                }
                                else
                                {
                                    a[val]+=-i;
                                    b[val]-=-i;
                                }
                            flag=true;
                            break;
                        }
                    }
            }
            cout<<sum<<'\n';
        }
    }
}