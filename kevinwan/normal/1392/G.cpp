//#pragma comment(linker, "/STACK:2000000000")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1<<20;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn],b[mn];
int o[mn][20],tt[20];
int v[mn],w[mn];
int d1[mn],d2[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k,m;
    cin>>n>>m>>k;
    string s,t;
    cin>>s>>t;
    iota(o[0],o[0]+k,0);
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i],a[i]--,b[i]--;
    for(int i=1;i<=n;i++){
        memcpy(o[i],o[i-1],sizeof(o[i]));
        swap(o[i][a[i]],o[i][b[i]]);
    }
    memset(d1,0x3f,sizeof(d1));
    memset(d2,0xc0,sizeof(d2));
    for(int i=0;i<=n;i++){
        int aa=0,bb=0;
        for(int j=0;j<k;j++){
            aa+=(s[j]-'0'+0)<<o[i][j];
            bb+=(t[j]-'0'+0)<<o[i][j];
        }
        d1[aa]=min(d1[aa],i);
        d2[bb]=max(d2[bb],i);
    }
    for(int i=1;i<1<<k;i<<=1){
        for(int j=0;j<1<<k;j++)if(j&i){
            d1[j-i]=min(d1[j-i],d1[j]);
            d2[j-i]=max(d2[j-i],d2[j]);
        }
    }
    int a1=0,b1=0;
    for(char c:s)a1+=c=='1';
    for(char c:t)b1+=c=='1';
    int v=0,l=0;
    for(int i=0;i<1<<k;i++){
        if(d2[i]-d1[i]>=m&&__builtin_popcount(i)>l)l=__builtin_popcount(i),v=i;
    }
    printf("%d\n%d %d",k-a1-b1+2*l,d1[v]+1,d2[v]);
}