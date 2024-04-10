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

vector<int> A,B;
int N;
int id[101010];
int cur[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) {
		cin>>x;
		A.push_back(x);
	}
	cin>>N;
	FOR(i,N) {
		cin>>x;
		B.push_back(x);
	}
	sort(ALL(A));
	sort(ALL(B));
	A.erase(unique(ALL(A)),A.end());
	B.erase(unique(ALL(B)),B.end());
	
	N=B.size();
	multiset<int> M;
	vector<pair<int,int>> cand;
	FOR(i,N) {
		cur[i]=B[i]-A[0];
		FOR(j,A.size()-1) cand.push_back({B[i]-A[j],i});
		M.insert(cur[i]);
	}
	int ret=*M.rbegin()-*M.begin();
	sort(ALL(cand));
	reverse(ALL(cand));
	FORR(c,cand) {
		x=c.second;
		M.erase(M.find(cur[x]));
		id[x]++;
		cur[x]=B[x]-A[id[x]];
		M.insert(cur[x]);
		ret=min(ret,*M.rbegin()-*M.begin());
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}