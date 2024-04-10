#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m,mdiv;
int num[200];
int able[10][200];
const int mod=1000000007;
inline int fix(int a){
    if(a>=m) return a-m;
    return a;
}
inline int fix2(int a){
    if(a<0) return a+m;
    return a;
}
vector<int> got;
int dfs(int dep,int back){
    if(dep<5){
        int res=1;
        int j;
        REPN(i,mdiv,back+1) if(!able[dep][i] && num[i]){
            for(j=0;j<m;++j) able[dep+1][j]=0;
            for(j=0;j<m;++j) if(able[dep][j]){
                able[dep+1][j]=able[dep+1][fix(i+j)]=able[dep+1][fix2(j-i)]=1;
            }
            got.pb(i);
            res+=dfs(dep+1,i)*(lint)num[i]%mod;
            got.pop_back();
            if(res>=mod) res-=mod;
        }
        return res;
    }else{
        int res=1;
        REPN(i,mdiv,back+1) if(!able[dep][i] && num[i]){
            res+=num[i];
        }
        if(res>=mod) res-=mod;
        return res;
    }
}
int main(){
    scanf("%*d%d%d",&m,&n);
    REP(i,n){
        int a;scanf("%d",&a);a%=m;
        a=min(a,m-a);
        num[a]++;
    }
    mdiv=m/2;++mdiv;
    able[0][0]=1;
    printf("%d\n",dfs(0,0));

    return 0;
}