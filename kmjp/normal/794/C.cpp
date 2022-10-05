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

string S,T,R;
deque<int> A[2];
int N;
deque<int> lef;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	sort(ALL(S));
	sort(ALL(T));
	reverse(ALL(T));
	S.resize((N+1)/2);
	T.resize(N/2);
	FORR(c,S) A[0].push_back(c);
	FORR(c,T) A[1].push_back(c);
	FOR(i,N) lef.push_back(i);
	R=string(N,'.');
	
	FOR(i,N) {
		
		if(i%2==0) {
			if(A[1].empty() || A[0].front()<A[1].front()) {
				R[lef.front()]=A[0].front();
				lef.pop_front();
				A[0].pop_front();
			}
			else {
				R[lef.back()]=A[0].back();
				lef.pop_back();
				A[0].pop_back();
			}
		}
		else {
			if(A[0].empty() || A[1].front()>A[0].front()) {
				R[lef.front()]=A[1].front();
				lef.pop_front();
				A[1].pop_front();
			}
			else {
				R[lef.back()]=A[1].back();
				lef.pop_back();
				A[1].pop_back();
			}
		}
	}
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}