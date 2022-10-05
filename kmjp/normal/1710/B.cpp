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

int T;
int N,M;
int X[202020],P[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> btm,bts;

vector<int> cand[606060];
int ok[606060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<ll> Xs;
		Xs.push_back(-(1LL<<30));
		Xs.push_back((3LL<<30));
		
		FOR(i,N) {
			cin>>X[i]>>P[i];
			Xs.push_back(X[i]);
			Xs.push_back(X[i]-P[i]);
			Xs.push_back(X[i]+P[i]);
			ok[i]=1;
		}
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		FOR(i,Xs.size()) cand[i].clear();
		
		FOR(i,N) {
			int a,b,c;
			a=lower_bound(ALL(Xs),X[i]-P[i])-Xs.begin();
			b=lower_bound(ALL(Xs),X[i])-Xs.begin();
			c=lower_bound(ALL(Xs),X[i]+P[i])-Xs.begin();
			cand[b].push_back(i);
			btm.add(a,1);
			bts.add(a,-(X[i]-P[i]));
			btm.add(b,-2);
			bts.add(b,(X[i]-P[i]));
			bts.add(b,(X[i]+P[i]));
			btm.add(c,1);
			bts.add(c,-(X[i]+P[i]));
		}
		ll cur=-1LL<<60;
		FOR(i,Xs.size()) {
			ll v=btm(i)*Xs[i]+bts(i);
			if(v>M) {
				cur=max(cur,v-M-Xs[i]);
			}
			FORR(e,cand[i]) {
				if(P[e]<cur+X[e]) ok[e]=0;
			}
		}
		cur=-1LL<<60;
		for(i=Xs.size()-1;i>=0;i--) {
			ll v=btm(i)*Xs[i]+bts(i);
			if(v>M) {
				cur=max(cur,v-M+Xs[i]);
			}
			FORR(e,cand[i]) {
				if(P[e]<cur-X[e]) ok[e]=0;
			}
		}
		FOR(i,N) {
			int a,b,c;
			a=lower_bound(ALL(Xs),X[i]-P[i])-Xs.begin();
			b=lower_bound(ALL(Xs),X[i])-Xs.begin();
			c=lower_bound(ALL(Xs),X[i]+P[i])-Xs.begin();
			cand[b].push_back(i);
			btm.add(a,-1);
			bts.add(a,(X[i]-P[i]));
			btm.add(b,2);
			bts.add(b,-(X[i]-P[i]));
			bts.add(b,-(X[i]+P[i]));
			btm.add(c,-1);
			bts.add(c,(X[i]+P[i]));
			cout<<ok[i];
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}