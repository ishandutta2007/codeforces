#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
vector<int>g[mn],v[mn];
int a[mn],mu[mn];
bool p[mn];
int pa[mn],s[mn];
int f(int x){return x==pa[x]?x:(pa[x]=f(pa[x]));}
void u(int a,int b){
    a=f(a),b=f(b);
    if(a==b)return;
    if(s[a]<s[b])swap(a,b);
    s[a]+=s[b];
    pa[b]=a;
}
ll ans[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(p,p+mn,1);
    fill(mu,mu+mn,1);
    for(int i=2;i<mn;i++)if(p[i]){
        for(int j=i;j<mn;j+=i){
            if(j/i%i==0)mu[j]=0;
            else mu[j]*=-1;
            p[j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                v[j].push_back(i);
                if(j*j!=a[i])v[a[i]/j].push_back(i);
            }
        }
    }
    iota(pa,pa+mn,0);
    for(int i=1;i<mn;i++){
        for(int x:v[i])s[x]=1;
        for(int x:v[i])for(int y:g[x])if(s[f(y)])u(x,y);
        for(int x:v[i])ans[i]+=s[f(x)]+1;
        ans[i]>>=1;
        for(int x:v[i])s[x]=0,pa[x]=x;
    }
    for(int i=1;i<mn;i++){
        ll pr=0;
        for(int j=1;j*i<mn;j++)pr+=ans[i*j]*mu[j];
        if(pr)printf("%d %lld\n",i,pr);
    }
}