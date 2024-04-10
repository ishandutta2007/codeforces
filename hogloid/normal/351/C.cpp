#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

const int INF=2e9+20;

typedef vector<int> vi;
typedef vector<vi> vii;

int n,m;
int ar1[25],ar2[25];

vii merge(const vii& a,const vii& b){

	vii res(n*2+1,vi(n+1,INF));
	REP(i,a.size()) REP(j,a[i].size()) if(a[i][j]<INF){
		REP(k,b.size()){
			int sum=i-n+k;
			if(sum<0 || sum>2*n) continue;
			REP(l,b[k].size()) if(b[k][l]<INF){
				int mini=min(j-n,i-n+l-n)+n;
				if(mini<0) continue;

				chmin(res[sum][mini],a[i][j]+b[k][l]);
			}
		}
	}
	return res;
}

vii mpow(vii a,int k){
	vii res(n*2+1,vi(n+1,INF));
	res[n][n]=0;

	while(k){
		if(k&1) res=merge(res,a);
		a=merge(a,a);
		k>>=1;
	}
	return res;
}

int main(){
	cin>>n>>m;
	REP(i,n) cin>>ar1[i];
	REP(i,n) cin>>ar2[i];

	vii mat(n*2+1,vi(n+1,INF));
	REP(bit,(1<<n)){
		int sum=0,evermin=0;
		int cost=0;
		REP(i,n){
			if(bit>>i&1){
				++sum;
				cost+=ar1[i];
			}else{
				--sum;
				cost+=ar2[i];
			}
			chmin(evermin,sum);
		}
		chmin(mat[sum+n][evermin+n],cost);
	}

	vii ans=mpow(mat,m);
	int res=ans[n][n];
	cout<<res<<endl;
	return 0;
}