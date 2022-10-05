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
pair<int,vector<int>> P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		P[x-1].second.push_back(y);
	}
	FOR(i,M) {
		sort(ALL(P[i].second));
		reverse(ALL(P[i].second));
		x=0;
		FORR(p,P[i].second) {
			x+=p;
			p=x;
		}
		P[i].first=P[i].second.size();
	}
	
	sort(P,P+M);
	reverse(P,P+M);
	
	ll ma=0;
	for(int i=1;i<=N;i++) {
		ll ret=0;
		FOR(j,M) {
			if(P[j].first<i) break;
			ret+=max(0,P[j].second[i-1]);
		}
		ma=max(ma,ret);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}