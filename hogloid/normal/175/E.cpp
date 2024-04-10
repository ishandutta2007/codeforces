#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int nf,ne,ns;
int rf,re,rs;
int df,de;
long double sf,se,ss;
int n;
long double ans;
int ever[25];
void calc(){
    long double res=0;
    REP(i,n) if(ever[i]<=1){
        long double seg;
        int deg;
        if(ever[i]==0) seg=sf,deg=df;
        else if(ever[i]==1) seg=se,deg=de;
        res+=seg*deg;
        REP(j,n) if(ever[j]==2){
            int x=i/2,x2=j/2;
            res+=max((long double)0.0,min(x+seg/2,x2+ss/2)-max(x-seg/2,x2-ss/2))*deg;
        }
    }
    ans=max(ans,res);
}
void dfs(int dep){
    if(dep==n){
        calc();
        return;
    }
    if(nf>0 && (dep%2==0 || ever[dep-1]<=0)){
        --nf;
        ever[dep]=0;
        dfs(dep+1);
        ++nf;
    }
    if(ne>0 && (dep%2==0 || ever[dep-1]<=1)){
        --ne;
        ever[dep]=1;
        dfs(dep+1);
        ++ne;
    }
    if(ns>0 && (dep%2==0 || ever[dep-1]<=2)){
        --ns;
        ever[dep]=2;
        dfs(dep+1);
        ++ns;
    }
}
long double getseg(int len){
    return sqrt((long double)len*len-1)*2;
}
int main(){
    scanf("%d%d%d",&nf,&ne,&ns);
    n=nf+ne+ns;
    scanf("%d%d%d",&rf,&re,&rs);
    scanf("%d%d",&df,&de);
    sf=getseg(rf);se=getseg(re);ss=getseg(rs);
    ans=0;
    dfs(0);
    printf("%.8f\n",(double)ans);
    return 0;
}