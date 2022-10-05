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

int N;
ll K,M;
deque<pair<int,int>> V;
ll A[101010];

ll hoge(deque<pair<int,int>>& V, ll M) {
	if(V.empty()) return 0;
	if(V.size()==1) {
		ll tot=V[0].second*M;
		return tot%K;
	}
	if(V.front().first!=V.back().first) {
		ll tot=0;
		FORR(c,V) tot += c.second;
		return tot*M;
	}
	
	ll a=V.front().second;
	ll b=V.back().second;
	ll ab=a+b;
	
	V.pop_front();
	V.pop_back();
	if(ab%K==0) {
		ll x=hoge(V,M);
		if(x==0) return ab%K;
		else return ab+x;
	}
	else {
		ll x=hoge(V,1);
		if(x==0) {
			return ab*M%K;
		}
		else {
			return ab+(ab%K)*(M-1)+x*M;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	FOR(i,N) {
		cin>>x;
		if(V.empty() || V.back().first!=x) V.push_back({x,0});
		V.back().second++;
		if(V.back().second==K) V.pop_back();
	}
	
	cout<<hoge(V,M)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}