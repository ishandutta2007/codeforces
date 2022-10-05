#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,21> bt;

ll C[1<<20];
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<pair<int,pair<int,ll>>> S;
	
	scanf("%d%d",&N,&Q);
	S.insert({0,{1,0LL}});
	S.insert({N+1,{1,0LL}});
	while(Q--) {
		char buf[10];
		scanf("%s",buf);
		s=buf;
		if(s=="Add") {
			scanf("%d%d",&x,&y);
			C[x]+=y;
		}
		else if(s=="Query") {
			scanf("%d",&x);
			ll ret=bt(x);
			auto it=S.lower_bound({x+1,{-2,0LL}});
			it--;
			auto p=it->second;
			ret+=C[p.first]-p.second;
			_P("%lld\n",ret);
		}
		else {
			int L,R;
			scanf("%d%d%d",&L,&R,&r);
			auto it=S.lower_bound({L,{-2,0LL}});
			if(it->first>L) {
				it--;
				S.insert({L,it->second});
			}
			it=S.lower_bound({R+1,{-2,0}});
			if(it->first!=R+1) {
				it--;
				S.insert({R+1,it->second});
			}
			x=L;
			while(x<=R) {
				auto it=S.lower_bound({x,{-2,0LL}});
				y=next(it)->first;
				ll a=C[it->second.first]-it->second.second;
				bt.add(x,a);
				bt.add(y,-a);
				S.erase(it);
				x=y;
			}
			S.insert({L,{r,C[r]}});
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}