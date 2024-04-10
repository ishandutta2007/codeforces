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
typedef pair<lint,lint> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
//const int INF=5e8;

const int MX=1000000;
int prm[1000005];
vector<int> g[1000005];


const int STEP=15;

int m;
vector<pi> range[1000005];

lint init[1000005];

lint res[1000005];
int main(){

	memset(prm,1,sizeof(prm));
	prm[0]=prm[1]=0;
	for(int i=2;i*i<=MX;++i) if(prm[i]){
		for(int j=i+i;j<=MX;j+=i) prm[j]=0;
	}
	for(int i=2;i<=MX;++i) if(prm[i]){
		for(int j=i;j<=MX;j+=i){
			int tmp=j,cnt=0;
			while(tmp%i==0){
				tmp/=i;
				++cnt;
			}
			REP(hoge,cnt) g[j+1].pb(i);
		}
	}
	
	cin>>m;
	REP(hoge,m){
		int p;
		lint a;
		scanf("%d",&p);
		scanf("%lld",&a);
		init[p]=a;
		range[p].pb(mp(0,a));
	}
	lint k;
	cin>>k;
	
	{
		for(int i=MX;i>=0;--i) if(!range[i].empty()){
			dump(i);
			sort(ALL(range[i]));
			lint till=range[i][0].fr,st=range[i][0].fr;
			for(auto r:range[i]){
				if(till<r.fr){
					if(st+1<min(k+1,till+1)){
						for(auto to:g[i]){
							range[to].pb(mp(st+1,min(k+1,till+1)));
						}
					}
					st=r.fr;
					till=r.fr;
				}
				till+=r.sc-r.fr;
			}
			if(st+1<min(k+1,till+1)){
				for(auto to:g[i]){
					range[to].pb(mp(st+1,min(k+1,till+1)));
				}
			}
			if(till<k){
				;
			}else{
				res[i]=till-k;
			}
		}


		int line=0;
		REP(i,MX+1) if(res[i]>0){
			++line;
		}
		cout<<line<<endl;
		REP(i,MX+1) if(res[i]>0){
			printf("%d %lld\n",i,res[i]);
		}
	}

	return 0;
}