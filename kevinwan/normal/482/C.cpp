#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=50;
string s[mn];
bitset<1<<20>fin[mn];
int n,m;
ll ms[mn];
ll num[256];
double ch[mn][mn];
double pro[mn];
void ini(int x,int i){
    if(i>=0&&((x>>i)&1)){
        memset(num,0,sizeof(num));
        for(int j=0;j<n;j++)num[s[j][i]]|=(1LL<<j);
        for(int j=0;j<n;j++)ms[j]&=num[s[j][i]];
        for(int j=0;j<n;j++)if(!(ms[j]&(ms[j]-1))){
            int num=__builtin_popcount(x);
            pro[num]+=1./n/ch[m][num];
        }
    }
    if(i==m-1)return;
    ll mem[mn];
    memcpy(mem,ms,sizeof(ms));
    ini(x,i+1);
    memcpy(ms,mem,sizeof(ms));
    ini(x|(1LL<<i+1),i+1);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    ch[0][0]=1;
    for(int i=1;i<mn;i++){
        ch[i][0]=1;
        for(int j=1;j<=i;j++)ch[i][j]=ch[i-1][j-1]+ch[i-1][j];
    }
    m=s[0].size();
    memset(ms,-1,sizeof(ms));
    ini(0,-1);
    double ans=0;
    for(int i=1;i<=m;i++)ans+=(pro[i]-pro[i-1])*i;
    if(n==1)ans=0;
    printf("%.20lf",ans);
}