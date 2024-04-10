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
int C[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0,id=-1;
	FOR(i,N) {
		cin>>A[i];
		C[A[i]]++;
		if(C[A[i]]>C[ma]) ma=A[i],id=i;
	}
	
	vector<vector<int>> V;
	
	for(j=id-1;j>=0;j--) {
		if(A[j]<A[id]) {
			V.push_back({1,j+1,j+2});
		}
		if(A[j]>A[id]) {
			V.push_back({2,j+1,j+2});
		}
		A[j]=A[id];
	}
	for(j=id+1;j<N;j++) {
		if(A[j]<A[id]) {
			V.push_back({1,j+1,j});
		}
		if(A[j]>A[id]) {
			V.push_back({2,j+1,j});
		}
		A[j]=A[id];
	}
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}