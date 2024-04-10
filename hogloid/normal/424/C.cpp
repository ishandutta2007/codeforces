#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n;
int xorsum[1000005];
int main(){
    cin>>n;
    xorsum[0]=0;
    REP(i,n) xorsum[i+1]=(xorsum[i]^(i+1));
    
    int res=0;
    REP(i,n){
        int a;scanf("%d",&a);
        res^=a;
    }
    for(int i=1;i<=n;++i){
        int repe=n/i;
        if(repe&1) res^=xorsum[i-1];
        int rest=n%i;
        res^=xorsum[rest];
    }
    cout<<res<<endl;
    
    
	return 0;
}