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
int A[202020];
int num[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int pre=-1;
	FOR(i,N) {
		cin>>A[i];
		if(pre==-1 || A[pre]!=A[i]) pre=i;
		num[pre]++;
	}
	set<int> P;
	set<pair<int,int>> cand;
	FOR(i,N) if(num[i]) {
		P.insert(i);
		cand.insert({-num[i],i});
	}
	
	int step=0;
	while(P.size()) {
		step++;
		x=cand.begin()->second;
		cand.erase(cand.begin());
		
		P.erase(x);
		auto it=P.lower_bound(x);
		if(it==P.begin()||it==P.end()) continue;
		y=*it;
		it--;
		x=*it;
		if(A[x]==A[y]) {
			P.erase(y);
			cand.erase({-num[y],y});
			cand.erase({-num[x],x});
			num[x]+=num[y];
			cand.insert({-num[x],x});
		}
	}
	
	cout<<step<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}