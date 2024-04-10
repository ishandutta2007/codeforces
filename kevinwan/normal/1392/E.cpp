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
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
ll a[25][25],l[25][25],h[25][25],lar[26][26];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    scanf("%d",&n);
    for(int i=n-2;i>=0;i--){
        l[n-1][i]=h[n-1][i]=l[n-1][i+1];
        for(int j=n-2;j>=0;j--){
            a[j+1][i]=h[j][i+1]+1-l[j+1][i];
            l[j+1][i]+=a[j+1][i];
            h[j+1][i]+=a[j+1][i];
            l[j][i]=l[j][i+1];
            h[j][i]=h[j+1][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%lld ",a[i][j]);
        printf("\n");
    }
    fflush(stdout);
    int q;
    scanf("%d",&q);
    while(q--){
        ll k;
        scanf("%lld",&k);
        vector<pii>v;
        int i=0,j=0;
        while(i!=n-1||j!=n-1){
            v.push_back({i,j});
            k-=a[i][j];
            if(j!=n-1&&k<=h[i][j+1])j++;
            else i++;
        }
        v.push_back({n-1,n-1});
        for(pii p:v)printf("%d %d\n",p.first+1,p.second+1);
        fflush(stdout);
    }
}