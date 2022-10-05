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


ll N,M;
ll L,R;
ll A[202020],B[202020];
vector<int> D[202020];
deque<int> cand[202020];
set<int> CD;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>L>>R;
	
	for(x=1;x<=200000;x++) {
		A[x]=max(1LL,(L+x-1)/x);
		B[x]=min(M,R/x);
		for(y=x;y<=200000;y+=x) D[y].push_back(x);
	}
	int LY=M+1,RY=M+1;
	for(x=1;x<=N;x++) {
		
		if(A[x]>B[x]) {
			cout<<-1<<endl;
			continue;
		}
		
		
		while(A[x]<LY) {
			LY--;
			FORR(d,D[LY]) {
				if(cand[d].empty()) CD.insert(d);
				cand[d].push_front(LY);
			}
		}
		while(B[x]<RY-1) {
			RY--;
			FORR(d,D[RY]) {
				cand[d].pop_back();
				if(cand[d].empty()) CD.erase(d);
			}
		}
			
		vector<int> ret;
		FORR(a,D[x]) {
			auto it=CD.lower_bound(a+1);
			if(it!=CD.end()) {
				int b=*it;
				y=cand[b][0];
				if(1LL*x/a*b<=N) {
					ret={x,y,1LL*x/a*b,1LL*y/b*a};
					break;
				}
			}
		}
		
		if(ret.empty()) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<" "<<ret[3]<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}