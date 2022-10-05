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
string H;
int C[101][26];

vector<string> ask(int L,int R) {
	vector<string> V;
	cout<<"? "<<L<<" "<<R<<endl;
	int len=R-L+1;
	int i;
	if(H.size()) {
		for(int l=L;l<=R;l++) for(int r=l;r<=R;r++) V.push_back(H.substr(l-1,r-l+1));
		FORR(v,V) sort(ALL(v));
		random_shuffle(ALL(V));
	}
	else {
		FOR(i,len*(len+1)/2) {
			string S;
			cin>>S;
			sort(ALL(S));
			V.push_back(S);
		}
	}
	
	return V;
}
string ans(string S) {
	cout<<"! "<<S<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	if(H.size()) {
		N=H.size();
	}
	else {
		cin>>N;
	}
	if(N==1) {
		auto a=ask(1,1);
		ans(a[0]);
	}
	else {
		auto A=ask(1,N);
		auto B=ask(2,N);
		map<string,int> M;
		FORR(a,A) M[a]++;
		FORR(a,B) M[a]--;
		FORR(m,M) if(m.second) {
			FORR(c,m.first) C[m.first.size()][c-'a']++;
		}
		string S;
		FOR(i,N) {
			FOR(x,26) if(C[i][x]!=C[i+1][x]) {
				S+='a'+x;
			}
		}
		ans(S);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}