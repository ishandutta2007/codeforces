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
int cnt[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		cnt[x]++;
		cnt[y]++;
	}
	
	if(cnt[N]!=N-1) return _P("NO\n");
	if(cnt[N-1]==0) return _P("NO\n");
	
	vector<pair<int,int>> V;
	vector<int> cand;
	for(i=1;i<=N-1;i++) {
		if(cnt[i]==0) cand.push_back(i);
		else {
			if(cand.size()<cnt[i]-1) return _P("NO\n");
			int pre=N;
			FOR(j,cnt[i]-1) {
				V.push_back({cand.back(),pre});
				pre=cand.back();
				cand.pop_back();
			}
			V.push_back({i,pre});
		}
	}
	cout<<"YES"<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}