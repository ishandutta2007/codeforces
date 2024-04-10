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

const int INF=5e8;
//

int n,m;
pi ps[100005];


int main(){
	cin>>n>>m;
	REP(i,m){
		scanf("%d%d",&ps[i].fr,&ps[i].sc);
		--ps[i].fr;--ps[i].sc;
	}
	sort(ps,ps+m);
	
	int cur=0;
	
	set<pi> seg,nxt;
	seg.insert(mp(0,1));

	vector<int> x;
	REP(i,m){
		int j=i;
		if(seg.empty()){
			puts("-1");
			return 0;
		}
		if(cur<ps[i].fr){
			int left=seg.begin()->fr;
			seg.clear();
			seg.insert(mp(left,n));
		}

		
		dump(ps[i].fr);
		debug(ALL(seg));
		x.clear();

		x.pb(-1);
		while(j<m && ps[j].fr==ps[i].fr){
			x.pb(ps[j].sc);
			++j;
		}
		x.pb(n);

		REP(k,x.size()-1){
			int l=x[k]+1,r=x[k+1];
			if(l>=r) continue;

			dump(mp(l,r));
			
			auto it=seg.lower_bound(mp(l,INF));
			if(it!=seg.begin()){
				--it;
				if(it->sc>l){
					nxt.insert(mp(l,r));
					continue;
				}
			}
			it=seg.lower_bound(mp(l,INF));
			if(it!=seg.end() && it->fr<r) nxt.insert(mp(it->fr,r));
		}

		cur=ps[i].fr+1;
		i=j-1;
		seg=nxt;
		nxt.clear();
	}
	debug(ALL(seg));
	if(cur==n){
		if(!seg.empty()) {
			auto it=seg.end();--it;
			if(it->sc==n){
				printf("%d\n",n*2-2);
				return 0;
			}
		}
		puts("-1");
	}else{
		prl;
		if(!seg.empty()){
			if(seg.begin()->fr<n){
				printf("%d\n",n*2-2);
				return 0;
			}
		}
		puts("-1");
	}
	return 0;
}