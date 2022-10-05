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

int N,P;
int A[101010];
int num[202030];
set<int> cand[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	map<int,int> num;
	FOR(i,N) {
		cin>>A[i];
	}
	sort(A,A+N);
	FOR(i,N) {
		if(A[i]<A[N-1]-N) A[i]=A[N-1]-N;
		num[A[i]]++;
	}
	
	for(i=A[N-1]-N;i<=A[N-1]+N;i++) {
		num[i+1]+=num[i];
		cand[((num[i]-i)%P+P)%P].insert(i);
	}
	
	vector<int> R;
	for(x=A[N-1]-N;x<=A[N-1];x++) if(x>=1) {
		y=(P-x%P)%P;
		auto it=cand[y].lower_bound(x);
		if(it!=cand[y].end() && *it<x+N) continue;
		R.push_back(x);
	}
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}