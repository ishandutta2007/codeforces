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
pair<int,int> seg[2000005];
int lz[2000005];

void build(int ver,int tl,int tr)
{
    if(tl>tr)
        return ;
    else if(tl==tr)
    {
        seg[ver]={0,0};
        lz[ver]=0;
    }
    else
    {
        int tm=(tl+tr)/2;
        build(2*ver,tl,tm);
        build(2*ver+1,tm+1,tr);
        seg[ver]={0,0};
        lz[ver]=0;
    }
}


void push(int ver)
{
    lz[2*ver]=1;
    lz[2*ver+1]=1;
    seg[2*ver].second=1;
    seg[2*ver+1].second=1;
    lz[ver]=0;
}


void upd(int ver,int tl,int tr,int pos,int val)
{
    if(tl>tr)
        return ;
    else if(tl==tr)
    {
        seg[ver]={val,0};
    }
    else
    {
        int tm=(tl+tr)/2;
        if(lz[ver])
            push(ver);
        if(tm>=pos)            
            upd(2*ver,tl,tm,pos,val);
        else 
            upd(2*ver+1,tm+1,tr,pos,val);

        if(seg[2*ver].first>seg[2*ver+1].first)
        {
            seg[ver]=seg[2*ver];
        }
        else if(seg[2*ver].first<seg[2*ver+1].first)
        {
            seg[ver]=seg[2*ver+1];
        }
        else
            seg[ver]=max(seg[2*ver],seg[2*ver+1]);
    }
}


void upd2(int ver,int tl,int tr,int l,int r)
{
    if(tl>tr||l>r||tr<l||r<tl)
        return;
    else if(tl==l&&tr==r)
    {
        seg[ver].second=1;
        lz[ver]=1;
    }
    else
    {
        int tm=(tl+tr)/2;
        upd2(2*ver,tl,tm,l,min(tm,r));
        if(lz[ver])
            push(ver);
        upd2(2*ver+1,tm+1,tr,max(tm+1,l),r);
        if(seg[2*ver].first>seg[2*ver+1].first)
        {
            seg[ver]=seg[2*ver];
        }
        else if(seg[2*ver].first<seg[2*ver+1].first)
        {
            seg[ver]=seg[2*ver+1];
        }
        else
            seg[ver]=max(seg[2*ver],seg[2*ver+1]);

    }
}

int get(int ver,int tl,int tr,int l,int r)
{
    if(tl>tr||l>r||tr<l||r<tl)
        return 0;
    else if(tl==l&&tr==r)
    {
        return seg[ver].first+seg[ver].second;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(lz[ver])
            push(ver);
        int z=max(get(2*ver,tl,tm,l,min(tm,r)),get(2*ver+1,tm+1,tr,max(tm+1,l),r));
        if(seg[2*ver].first>seg[2*ver+1].first)
        {
            seg[ver]=seg[2*ver];
        }
        else if(seg[2*ver].first<seg[2*ver+1].first)
        {
            seg[ver]=seg[2*ver+1];
        }
        else
            seg[ver]=max(seg[2*ver],seg[2*ver+1]);
        return z;
    }
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
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int z=get(1,1,n,1,a[i]);
            upd(1,1,n,a[i],z+1);
            upd2(1,1,n,1,a[i]-1);
        }
        cout<<seg[1].first+seg[1].second<<'\n';
    }

}