#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[101010];

vector<int> C[3];
int Y[101010];
vector<pair<int,int>> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int nex=N;
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	for(x=N;x>=1;x--) {
		if(A[x]==0) continue;
		if(A[x]==1) {
			R.push_back({x,x});
			C[1].push_back(x);
		}
		else if(A[x]==2) {
			if(C[1].empty()) return _P("-1\n");
			y=C[1].back();
			C[1].pop_back();
			R.push_back({x,y});
			C[2].push_back(x);
		}
		else if(A[x]==3) {
			if(C[2].size()) {
				y=C[2].back();
				C[2].pop_back();
				R.push_back({x,x});
				R.push_back({y,x});
				C[2].push_back(x);
			}
			else if(C[1].size()) {
				y=C[1].back();
				C[1].pop_back();
				R.push_back({x,x});
				R.push_back({y,x});
				C[2].push_back(x);
			}
			else {
				return _P("-1\n");
			}
		}
	}
	
	sort(ALL(R));
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r.second<<" "<<r.first<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}