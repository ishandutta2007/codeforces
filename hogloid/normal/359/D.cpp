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

int n;
int ar[300005];

struct segtree{
	int val[20][300000],gcd[20][300000];
	int loga[300005];
	int n;
	void init(int n_,int* ar){
		n=n_;
		REP(i,n){
			val[0][i]=gcd[0][i]=ar[i];
		}
		REP(i,19) REP(j,n){
			if(j+(1<<i)<n){
				val[i+1][j]=min(val[i][j],val[i][j+(1<<i)]);
				gcd[i+1][j]=__gcd(gcd[i][j],gcd[i][j+(1<<i)]);
			}else{
				val[i+1][j]=val[i][j];
				gcd[i+1][j]=gcd[i][j];
			}
		}
		REP(i,n+1){
			REP(j,20) if((1<<j)<=i) loga[i]=j;
		}
	}
	bool query(int a,int b){
		int log=loga[b-a];
		return min(val[log][a],val[log][b-(1<<log)])==
			__gcd(gcd[log][a],gcd[log][b-(1<<log)]);
	}
};
segtree seg;


bool able(int len,bool flag=false){
	int cnt=0;
	vector<int> cont;
	REP(i,n-len+1){
		if(seg.query(i,i+len)){
			if(!flag) return true;
			++cnt;
			cont.pb(i+1);
		}
	}
	if(flag){
		printf("%d %d\n",cnt,len-1);
		REP(i,cont.size()) printf("%d\n",cont[i]);
	}

	return false;


}

int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];

	seg.init(n,ar);
	
	int lb=1,ub=n+1;
	
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(able(md)) lb=md;
		else ub=md;
	}
	
	able(lb,true);



	return 0;
}