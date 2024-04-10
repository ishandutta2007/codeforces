#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=200;
int v[mn];
string s[mn];
int ind[mn];
ll a[mn][mn],t[mn][mn],ans[mn][mn];
void mult(ll c[mn][mn],ll a[mn][mn],ll b[mn][mn]){
    memset(t,0xc0,sizeof(t));
    for(int i=0;i<mn;i++)for(int j=0;j<mn;j++)for(int k=0;k<mn;k++)t[i][k]=max(t[i][k],a[i][j]+b[j][k]);
    memcpy(c,t,sizeof(t));
}
int main(){
    int n;
    ll q;
    scanf("%d%lld",&n,&q);
    for(int i=0;i<n;i++)scanf("%d",v+i);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<i;j++)if(s[i]==s[j]){
            v[j]+=v[i];
            for(int k=i;k<n-1;k++)v[k]=v[k+1];
            n--,i--;
            break;
        }
    }
    for(int i=1;i<n;i++){
        ind[i]=ind[i-1]+s[i-1].size();
    }

    memset(a,0xc0,sizeof(a));
    for(int i=0;i<n;i++){
        for(int j=0;j+1<s[i].size();j++){
            a[ind[i]+j][ind[i]+j+1]=0;
            for(int k=0;k<n;k++)if(s[k].size()<=j+2){
                bool b=1;
                for(int l=0;l<s[k].size();l++){
                    b&=s[k][l]==s[i][l+j-s[k].size()+2];
                }
                if(b)a[ind[i]+j][ind[i]+j+1]+=v[k];
            }
        }
    }
    for(int i=0;i<n;i++){
        vector<pii>vec;
        for(int k=0;k<n;k++)for(int l=0;l<s[k].size();l++){
                bool b=1;
                for(int m=0;m<l;m++){
                    b&=s[i][s[i].size()-l+m]==s[k][m];
                }
                if(!b)continue;
                vec.push_back({k,l}),a[ind[i]+s[i].size()-1][ind[k]+l]=0;
            }
        for(pii j:vec){
            for(pii k:vec){
                if(s[j.first][j.second]==s[k.first][k.second]&&k.second==s[k.first].size()-1)
                    a[ind[i]+s[i].size()-1][ind[j.first]+j.second]+=v[k.first];
            }
        }
    }
    memset(ans,0xc0,sizeof(ans));
    for(int i=0;i<mn;i++)ans[i][i]=0;
    q--;
    for(;q;q>>=1,mult(a,a,a))if(q&1)mult(ans,ans,a);
    ll pr=0xc0c0c0c0c0c0c0c0;
    memset(a,0xc0,sizeof(a));
    for(int i=0;i<n;i++){
        if(s[i].size()==1)a[0][ind[i]]=v[i];
        else a[0][ind[i]]=0;
    }
    mult(ans,a,ans);
    for(int i=0;i<mn;i++)pr=max(pr,ans[0][i]);
    printf("%lld\n",pr);
}