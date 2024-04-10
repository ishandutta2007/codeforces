#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e5+10;
const int thres=350;
const int mnum=mn/thres+10;
ll v[mn];
vector<int>se[mn];
vector<int>big;
int rbig[mn];
ll sh[mnum][mn],ad[mn],del[mn];
bool b[mn];
int main(){
    //freopen("//Users//kevinwan//Desktop//wtf.txt","r",stdin);
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)scanf("%lld",v+i);
    for(int i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        se[i].resize(k);
        for(int j=0;j<k;j++)scanf("%d",se[i].begin()+j);
        if(k>=thres){
            big.push_back(i),rbig[i]=big.size()-1;
            for(int ind:se[i])ad[i]+=v[ind];
        }
    }
    for(int i=0;i<big.size();i++){
        for(int ind:se[big[i]])b[ind]=1;
        for(int j=0;j<m;j++){
            for(int ind:se[j])if(b[ind])sh[i][j]++;
        }
        for(int ind:se[big[i]])b[ind]=0;
    }
    while(q--){
        string s;
        cin>>s;
        if(s=="+"){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            if(se[a].size()>=thres)del[a]+=b;
            else{
                for(int ind:se[a])v[ind]+=b;
                for(int i=0;i<big.size();i++)ad[big[i]]+=1LL*b*sh[i][a];
            }
        }
        else{
            int a;
            scanf("%d",&a);
            a--;
            ll ans=0;
            for(int i=0;i<big.size();i++)ans+=sh[i][a]*del[big[i]];
            if(se[a].size()>=thres){
                ans+=ad[a];
            }else{
                for(int ind:se[a])ans+=v[ind];
            }
            printf("%lld\n",ans);
        }
    }
}