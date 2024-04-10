#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
#define ll long long
#define ld long double
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
long long powm(long long a, long long b,long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %mod;
        a = a * a %mod;
        b >>= 1;
    }
    return res;
}
 
 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);      
}

const int mod=1e9+7;
int parent[200005];
int sz[200005];
int find_parent(int ver)
{
    if(ver==parent[ver])
        return ver;
    return parent[ver]=find_parent(parent[ver]);
}

bool merge(int a,int b)
{
    a=find_parent(a);
    b=find_parent(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
            sz[a]+=sz[b];
        parent[b]=a;
        return 1;
    }
    return 0;
}


signed main()
{
 
ios_base::sync_with_stdio(false); 
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
        freopen("INPUT.txt","r",stdin);
        freopen("OUTPUT.txt","w",stdout);
    }
#endif          

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,pair<int,int>> >pp,lol;
        int x,y,z;
        int kad=1e17;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            if(z<=k)
                pp.push_back({z,{x,y}});
            else
            {
                kad=min(kad,z-k);
                lol.push_back({z,{x,y}});
            }
        }

        int mx=0;

        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }

        int cnt=n;
        for(auto i:pp)
        {
            cnt-=merge(i.second.first,i.second.second);
            mx=max(mx,i.first);
        }
        int mn=1e17;
        if(cnt==1)
        {
            mn=min(mn,k-mx);
            mn=min(mn,kad);
            cout<<mn<<'\n';
            continue;
        }

        sort(lol.begin(),lol.end());
        int ans=0;
        for(auto i:lol)
        {
            if(merge(i.second.first,i.second.second))
                ans+=(i.first-k);
        }

        cout<<ans<<'\n';

    }

}