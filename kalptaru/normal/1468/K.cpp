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
pair<int,int>find(char s)
{
    if(s=='L')
        return {-1,0};
    else if(s=='R')
        return {1,0};
    else if(s=='D')
        return {0,-1};
    else
        return {0,1};
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
        string a;
        cin>>a;
        int n=a.length();
        int x=0,y=0;
        map<pair<int,int>,int>mm;
        pair<int,int>ans={0,0};
        for(int i=0;i<n;i++)
        {
            pair<int,int>z=find(a[i]);
            pair<int,int>temp={x+z.first,y+z.second};

            if(mm[temp]==0)
            {
                int xx=x;
                int yy=y;

                for(int j=i+1;j<n;j++)
                {
                    pair<int,int>pp=find(a[j]);
                    if(make_pair(xx+pp.first,yy+pp.second)==temp)
                        continue;
                    xx+=pp.first;
                    yy+=pp.second;
                }
                if(xx==0&&yy==0)
                {
                    ans=temp;
                    break;
                }
            }
            
            mm[temp]=1;
            x+=z.first;
            y+=z.second;
        }
        cout<<ans.first<<" "<<ans.second<<'\n';
    }

}