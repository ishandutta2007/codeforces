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

int T;
int N,S;
int X[1001];
bitset<1<<18> HB[501];

vector<vector<int>> hoge() {
	vector<int> R[2];
	int i;
	cin>>N;
	FOR(i,N) cin>>X[i];
	if(N>500) return {};
	
	HB[0][0]=1;
	S=0;
	FOR(i,N) {
		S+=X[i];
		HB[i+1]=HB[i] | (HB[i]<<X[i]);
	}
	if(S%2) return {};
	S/=2;
	if(HB[N][S]==0) return {};
	for(i=N-1;i>=0;i--) {
		if(S>=X[i]&&HB[i][S-X[i]]) {
			R[0].push_back(X[i]);
			S-=X[i];
		}
		else R[1].push_back(X[i]);
	}
	sort(ALL(R[0]));
	sort(ALL(R[1]));
	if(R[0].size()<R[1].size()) swap(R[0],R[1]);
	
	return {R[0],R[1]};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		auto A=hoge();
		auto B=hoge();
		
		if(A.empty()||B.empty()) {
			cout<<"No"<<endl;
			continue;
		}
		if(A[0].size()+A[1].size()!=B[0].size()+B[1].size()) {
			cout<<"No"<<endl;
			continue;
		}
		
		x=y=0;
		cout<<"Yes"<<endl;
		if(A[0].size()<=B[0].size()) {
			reverse(ALL(A[0]));
			reverse(ALL(B[1]));
			while(A[1].size()) A[0].push_back(-A[1].back()), A[1].pop_back();
			while(B[1].size()) B[0].push_back(-B[1].back()), B[1].pop_back();
			FOR(i,A[0].size()) {
				x+=A[0][i];
				cout<<x<<" "<<y<<endl;
				y+=B[0][i];
				cout<<x<<" "<<y<<endl;
			}
		}
		else {
			reverse(ALL(A[1]));
			reverse(ALL(B[0]));
			while(A[1].size()) A[0].push_back(-A[1].back()), A[1].pop_back();
			while(B[1].size()) B[0].push_back(-B[1].back()), B[1].pop_back();
			FOR(i,A[0].size()) {
				y+=B[0][i];
				cout<<x<<" "<<y<<endl;
				x+=A[0][i];
				cout<<x<<" "<<y<<endl;
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}