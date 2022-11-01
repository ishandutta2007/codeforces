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

int n,x;
int n1[2];

vector<pi> cand[2],back[2];
const int INF=5e8;
int main(){
	cin>>n>>x;
	REP(i,n){
		int t,h,m;cin>>t>>h>>m;
		cand[t].pb(mp(h,m));
	}
	
	int res=0;
	REP(t,2){
		REP(i,2) back[i]=cand[i];

		
		int hei=x;
		int cur=0;
		REP(i,n){
			int ind,maxi=-1;
			REP(j,cand[t^(i&1)].size()) if(maxi<cand[t^(i&1)][j].sc &&
						cand[t^(i&1)][j].fr<=hei){
				maxi=cand[t^(i&1)][j].sc;
				ind=j;
			}
			if(maxi==-1) break;
			hei+=maxi;
			cand[t^(i&1)].erase(cand[t^(i&1)].begin()+ind);
			++cur;
		}

		REP(i,2) cand[i]=back[i];
		chmax(res,cur);
	}
	cout<<res<<endl;



	return 0;
}