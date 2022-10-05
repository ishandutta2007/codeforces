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

string S,T;
int A[2],N;
int AS[505050][2];

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	FORR(c,S) A[c=='1']++;
	N=T.size();
	FOR(i,N) {
		AS[i+1][0]=AS[i][0]+(T[i]=='0');
		AS[i+1][1]=AS[i][1]+(T[i]=='1');
	}
	string R;
	
	auto V=Zalgo(T);
	
	if(A[0]>=AS[N][0]&&A[1]>=AS[N][1]) {
		R=T;
		A[0]-=AS[N][0];
		A[1]-=AS[N][1];
		
		for(i=1;i<N;i++) if(V[i]==N-i) {
			while(A[0]>=AS[i][0] && A[1]>=AS[i][1]) {
				A[0]-=AS[i][0];
				A[1]-=AS[i][1];
				R+=T.substr(N-i);
			}
		}
		while(A[0]>=AS[N][0]&&A[1]>=AS[N][1]) {
			R+=T;
			A[0]-=AS[N][0];
			A[1]-=AS[N][1];
		}
	}
	FOR(i,A[0]) R+='0';
	FOR(i,A[1]) R+='1';
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}