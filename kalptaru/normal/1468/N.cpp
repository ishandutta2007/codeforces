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
        int c[4];
        for(int i=1;i<=3;i++)
            cin>>c[i];
        int a[6];
        for(int i=1;i<=5;i++)
        {
            cin>>a[i];
            if(i<=3)
                c[i]-=a[i];
        }
        if(c[1]>0)
        {
            int z=min(a[4],c[1]);
            c[1]-=z;
            a[4]-=z;
        }
        if(c[2]>0)
        {
            int z=min(a[5],c[2]);
            c[2]-=z;
            a[5]-=z;
        }
        c[3]-=(a[4]+a[5]);
        if(c[1]<0||c[2]<0||c[3]<0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }

}