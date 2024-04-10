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

int n,w;
pair<pi,int> take[300005];

bool cmp(const pair<pi,int>& a,const pair<pi,int>& b){
	return mp(a.fr.sc,a.fr.fr)<mp(b.fr.sc,b.fr.fr);
}
const int INF=1e9+5;
set<pi> pool,have;

char str[300005];
void solve(int & L,lint& res,int flag=0){
	pool.clear();have.clear();
	REP(i,n) pool.insert(mp(take[i].fr.fr,take[i].sc*2));
	lint cost=0;

	REP(i,n+1){	//pos- i-1 is the last 2
		while(!have.empty() && have.size()+i>w){
			auto it=have.end();--it;
			cost-=it->fr;
			pool.insert(*it);
			have.erase(it);
		}
		while(have.size()+i<w && !pool.empty()){
			cost+=pool.begin()->fr;
			have.insert(*pool.begin());
			pool.erase(pool.begin());
		}
		while(have.size()+i==w && !have.empty() && !pool.empty()){
			auto it=have.end();--it;
			if(it->fr>pool.begin()->fr){
				cost+=pool.begin()->fr-it->fr;
				pool.insert(*it);
				have.erase(it);
				have.insert(*pool.begin());
				pool.erase(pool.begin());
			}else break;
		}
		dump(cost);
		
		if(flag && L==i){
			REP(j,n) str[j]='0';
			REP(j,i) str[take[j].sc]='1';
			dump(i);
			for(auto it:have){
				dump(it);
				str[it.sc/2]='1'+(it.sc&1);
			}
			str[n]='\0';
			printf("%s\n",str);
			return;
		}

		if(have.size()+i==w && res>cost){
			L=i;
			res=cost;
		}
		if(i==n) break;

		cost+=take[i].fr.fr;
		pi ers=mp(take[i].fr.fr,take[i].sc*2);
		if(pool.count(ers)) pool.erase(ers);
		if(have.count(ers)){
			have.erase(ers);
			cost-=take[i].fr.fr;
		}

		
		pool.insert(mp(take[i].fr.sc-take[i].fr.fr,take[i].sc*2+1));
		dump(have.size());dump(pool.size());

	}
}
int main(){
	cin>>n>>w;
	REP(i,n){
		scanf("%d%d",&take[i].fr.fr,&take[i].fr.sc);
		take[i].sc=i;
	}
	sort(take,take+n,cmp);
	
	int L;
	lint res=1e18;
	solve(L,res);

	cout<<res<<endl;
	solve(L,res,1);	




	return 0;
}