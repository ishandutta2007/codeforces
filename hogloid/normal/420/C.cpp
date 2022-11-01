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

int n,p;
pi coder[300005];

static const int MAX_N=300005;
struct BIT{
	int val[MAX_N*2+2];
	int n;
	int all;
	void init(int n_){
		n=1;
		all=0;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		all+=a;
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){	//[0,k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return all-res;
	}
};
BIT bit;

int sum[300005];
vector<int> opp[300005];
int main(){
	cin>>n>>p;
	bit.init(n);

	REP(i,n){
		scanf("%d%d",&coder[i].fr,&coder[i].sc);
		--coder[i].fr;
		--coder[i].sc;
		++sum[coder[i].fr];
		++sum[coder[i].sc];
		opp[coder[i].fr].pb(coder[i].sc);
		opp[coder[i].sc].pb(coder[i].fr);
	}
	lint res=0;
	REP(i,n) bit.add(sum[i],1);

	REP(i,n){
		REP(j,opp[i].size()){
			int a=opp[i][j];
			bit.add(sum[a],-1);
			--sum[a];
			bit.add(sum[a],1);
		}
		bit.add(sum[i],-1);
		int elem=sum[i];
		res+=bit.query(p-elem);

		bit.add(sum[i],1);

		REP(j,opp[i].size()){
			int a=opp[i][j];
			bit.add(sum[a],-1);
			++sum[a];
			bit.add(sum[a],1);
		}
	}
	res/=2;
	cout<<res<<endl;





	return 0;
}