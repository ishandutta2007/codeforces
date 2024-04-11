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

string E;
int P,M;
int cur;

vector<pair<int,int>> hoge() {
	vector<pair<int,int>> R;
	int S=min(P,M);
	int i;
	FOR(i,S+1) R.push_back({-1<<20,1<<20});
	
	
	if(E[cur]=='(') {
		cur++;
		vector<pair<int,int>> A,B;
		A=hoge();
		assert(E[cur]=='?');
		cur++;
		B=hoge();
		assert(E[cur]==')');
		cur++;
		
		int x,y;
		if(P<=M) {
			FOR(x,P+1) FOR(y,P+1) {
				if(x+y<=P) {
					R[x+y].first=max(R[x+y].first,A[x].first-B[y].second);
					R[x+y].second=min(R[x+y].second,A[x].second-B[y].first);
					if(x+y+1<=P) {
						R[x+y+1].first=max(R[x+y+1].first,A[x].first+B[y].first);
						R[x+y+1].second=min(R[x+y+1].second,A[x].second+B[y].second);
					}
				}
			}
		}
		else {
			FOR(x,M+1) FOR(y,M+1) {
				if(x+y<=M) {
					R[x+y].first=max(R[x+y].first,A[x].first+B[y].first);
					R[x+y].second=min(R[x+y].second,A[x].second+B[y].second);
					if(x+y+1<=M) {
						R[x+y+1].first=max(R[x+y+1].first,A[x].first-B[y].second);
						R[x+y+1].second=min(R[x+y+1].second,A[x].second-B[y].first);
					}
				}
			}
		}
	}
	else {
		R[0]={(int)(E[cur]-'0'),(int)(E[cur]-'0')};
		cur++;
	}
	return R;
	
}

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>E;
	cin>>P>>M;
	auto r=hoge();
	cout<<r[min(P,M)].first<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}