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
int A[101010],H[101010],P[101010];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(i) {
			auto it=M.lower_bound(A[i]);
			if(it==M.end()) {
				it--;
			}
			else if(it!=M.begin()) {
				auto it2=it;
				it--;
				if(it->second<it2->second) swap(it,it2);
			}
			H[i]=it->second+1;
			P[i]=it->first;
		}
		M[A[i]]=H[i];
	}
	
	for(i=1;i<N;i++) _P("%d%s",P[i],(i==N-1)?"\n":" ");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}