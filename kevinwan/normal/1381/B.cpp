#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e3+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        for(int i=0;i<2*n;i++)cin>>a[i];
        vector<int>v;
        int l=a[0],in=0;
        for(int i=1;i<2*n;i++){
            if(a[i]>l){
                l=a[i];
                v.push_back(i-in);
                in=i;
            }
        }
        v.push_back(2*n-in);
        bitset<2010>b;
        b.reset();
        b[0]=1;
        for(int x:v)b|=b<<x;
        if(b[n])printf("YES\n");
        else printf("NO\n");
    }
}