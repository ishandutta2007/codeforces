#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
const ll mod=1e9+7;
struct query{
    int p,x,ind;
};
int a[mn];
int basis[20];
ll pro=1;
ll ans[mn];
void add(int x){
    for(int i=19;i>=0;i--)if((x>>i)&1){
        if(basis[i])x^=basis[i];
        else {basis[i]=x;return;}
    }
    pro*=2,pro%=mod;
}
bool check(int x){
    for(int i=19;i>=0;i--)if((x>>i)&1){
        if(basis[i])x^=basis[i];
        else return 0;
    }
    return 1;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    vector<query>v;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=0;i<q;i++){
        int p,x;
        scanf("%d%d",&p,&x);
        v.push_back({p,x,i});
    }
    sort(v.begin(),v.end(),[](query a,query b){return a.p<b.p;});
    int cur=0;
    for(query q:v){
        while(cur<q.p)add(a[++cur]);
        ans[q.ind]=check(q.x)*pro;
    }
    for(int i=0;i<q;i++)printf("%lld\n",ans[i]);
}