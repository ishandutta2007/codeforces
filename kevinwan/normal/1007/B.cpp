#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e5+10;
vector<int>fac[mn];
vector<int>v;
vector<int>w;
int num[8];
bool gud[8][8][8];
int main(){
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<mn;i++)for(int j=i;j<mn;j+=i)fac[j].push_back(i);
    for(int i=0;i<8;i++)for(int j=i;j<8;j++)for(int k=j;k<8;k++){
                if((i&1)&&((j>>1)&1)&&((k>>2)&1))gud[i][j][k]=1;
                if((i&1)&&((k>>1)&1)&&((j>>2)&1))gud[i][j][k]=1;
                if((j&1)&&((i>>1)&1)&&((k>>2)&1))gud[i][j][k]=1;
                if((j&1)&&((k>>1)&1)&&((i>>2)&1))gud[i][j][k]=1;
                if((k&1)&&((i>>1)&1)&&((j>>2)&1))gud[i][j][k]=1;
                if((k&1)&&((j>>1)&1)&&((i>>2)&1))gud[i][j][k]=1;
    }
    while(tc--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        w.resize(fac[a].size()+fac[b].size());
        v.resize(fac[a].size()+fac[b].size()+fac[c].size());
        merge(fac[a].begin(),fac[a].end(),fac[b].begin(),fac[b].end(),w.begin());
        merge(w.begin(),w.end(),fac[c].begin(),fac[c].end(),v.begin());
        v.erase(unique(v.begin(),v.end()),v.end());
        w.resize(v.size());
        fill(w.begin(),w.end(),0);
        memset(num,0,sizeof(num));
        for(int i=0;i<v.size();i++){
            if(a%v[i]==0)w[i]++;
            if(b%v[i]==0)w[i]+=2;
            if(c%v[i]==0)w[i]+=4;
            num[w[i]]++;
        }
        ll ans=0;
        for(int i=0;i<8;i++)for(int j=i;j<8;j++)for(int k=j;k<8;k++)if(gud[i][j][k]){
            if(i==j&&j==k)ans+=1LL*num[i]*(num[i]+1)*(num[i]+2)/6;
            else if(i==j)ans+=1LL*num[i]*(num[i]+1)/2*num[k];
            else if(i==k)ans+=1LL*num[i]*(num[i]+1)/2*num[j];
            else if(j==k)ans+=1LL*num[i]*num[j]*(num[j]+1)/2;
            else ans+=1ll*num[i]*num[j]*num[k];
        }
        printf("%lld\n",ans);
    }
}