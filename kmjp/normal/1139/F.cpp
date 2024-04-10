#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll P[101010],S[101010],B[101010],inc[101010],pref[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> btp,btm;
vector<pair<int,int>> ev;

int ret[101010];
int num;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<ll> CP,CM;
	CP.push_back(-1LL<<40);
	CM.push_back(-1LL<<40);
	
	FOR(i,N) {
		cin>>P[i];
		ev.push_back({P[i],i});
	}
	FOR(i,N) {
		cin>>S[i];
		ev.push_back({S[i],200000+i});
	}
	FOR(i,N) {
		cin>>B[i];
		CP.push_back(B[i]+P[i]);
		CM.push_back(P[i]-B[i]);
	}
	FOR(i,M) {
		cin>>inc[i];
		ev.push_back({inc[i],100000+i});
	}
	FOR(i,M) {
		cin>>pref[i];
		CP.push_back(inc[i]+pref[i]);
		CM.push_back(inc[i]-pref[i]);
	}
	sort(ALL(CP));
	sort(ALL(CM));
	CP.erase(unique(ALL(CP)),CP.end());
	CM.erase(unique(ALL(CM)),CM.end());
	sort(ALL(ev));
	FORR(e,ev) {
		x=e.second;
		if(x<100000) {
			num++;
			y=lower_bound(ALL(CP),B[x]+P[x])-CP.begin();
			btp.add(y,1);
			y=lower_bound(ALL(CM),P[x]-B[x])-CM.begin();
			btm.add(y,1);
		}
		else if(x<200000) {
			x-=100000;
			y=lower_bound(ALL(CP),inc[x]+pref[x])-CP.begin();
			ret[x]+=btp(y);
			y=lower_bound(ALL(CM),inc[x]-pref[x])-CM.begin();
			ret[x]+=btm(y);
			ret[x]-=num;
		}
		else {
			x-=200000;
			num--;
			y=lower_bound(ALL(CP),B[x]+P[x])-CP.begin();
			btp.add(y,-1);
			y=lower_bound(ALL(CM),P[x]-B[x])-CM.begin();
			btm.add(y,-1);
		}
	}
	FOR(i,M) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}