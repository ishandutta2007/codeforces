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
ll M[505050];

ll L[505050],R[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>M[i+1];
	
	vector<pair<int,int>> V;
	V.push_back({0,0});
	ll S=0;
	for(i=1;i<=N;i++) {
		int num=1;
		while(V.back().first>=M[i]) {
			S-=1LL*V.back().first*V.back().second;
			num+=V.back().second;
			V.pop_back();
		}
		S+=M[i]*num;
		V.push_back({M[i],num});
		L[i]=S;
	}
	V.clear();
	S=0;
	V.push_back({0,0});
	for(i=N;i>=1;i--) {
		int num=1;
		while(V.back().first>=M[i]) {
			S-=1LL*V.back().first*V.back().second;
			num+=V.back().second;
			V.pop_back();
		}
		S+=M[i]*num;
		V.push_back({M[i],num});
		R[i]=S;
	}
	ll ma=0;
	int id=0;
	for(i=1;i<=N;i++) {
		if(L[i]+R[i]-M[i]>ma) {
			ma=L[i]+R[i]-M[i];
			id=i;
		}
	}
	for(i=id+1;i<=N;i++) M[i]=min(M[i],M[i-1]);
	for(i=id-1;i>=1;i--) M[i]=min(M[i],M[i+1]);
	for(i=1;i<=N;i++) cout<<M[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}