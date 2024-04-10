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

lint n;

int main(){
    cin>>n;
    vector<lint> ans;
     REP(i,60){
        
        lint lb=0,ub=1e10;
        while(ub-lb>1){
            lint md=(lb+ub)>>1;
            
            if(2*n%md==0 && (md&1)){
                lint tmp=n*2/md;
                tmp+=3-md;
                
                if(tmp==(1ll<<(i+1))){
                    ans.pb(md<<i);
                    goto exi;
                }
            }
            lint tmp=n*2/md;
            tmp+=3-md;
            if(tmp>=(1ll<<(i+1))){
                lb=md;
            }else ub=md;
        }
        
        
    exi:;
    }
    sort(ALL(ans));
    if(ans.empty()) ans.pb(-1);
    REP(i,ans.size()) cout<<ans[i]<<endl;
    
    
	return 0;
}