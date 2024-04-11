#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
string S;

string gen(string S,string V) {
	if(V.empty()) return "";
	string T;
	FORR(c,S) if(c!=V[0]) T+=c;
	
	return S+gen(T,V.substr(1));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		int C[256]={},D[256]={};
		FORR(c,S) C[c]++;
		string V;
		FOR(i,N) {
			if(D[S[N-1-i]]==0) {
				D[S[N-1-i]]=1;
				V+=S[N-1-i];
			}
		}
		reverse(ALL(V));
		int tot=0;
		FOR(i,V.size()) {
			x=V[i];
			if(C[x]%(i+1)) break;
			C[x]/=(i+1);
			tot+=C[x];
		}
		if(i<V.size()) {
			cout<<-1<<endl;
			continue;
		}
		string W=gen(S.substr(0,tot),V);
		if(W==S) {
			cout<<S.substr(0,tot)<<" "<<V<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}