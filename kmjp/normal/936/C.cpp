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
string S,T;

map<string,int> M;
vector<int> R;
string rev(char a) {
	if(a=='a') return "a";
	if(a=='X') return "x";
	if(a=='Y') return "y";
	if(a=='Z') return "z";
	if(a=='x') return "X";
	if(a=='y') return "Y";
	if(a=='z') return "Z";
	assert(0);
}

string turn(int a,string S) {
	string A=S.substr(0,N-a);
	string B=S.substr(N-a);
	reverse(ALL(B));
	R.push_back(a);
	return B+A;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	string ss=S,tt=T;
	sort(ALL(ss));
	sort(ALL(tt));
	if(ss!=tt) return _P("-1\n");
	
	/*
	XaYZ -> zyXa
	zyXa -> azyX
	azyX -> xYZa
	*/


	FOR(i,N) {
		FOR(j,N) if(S[j]==T[i]) break;
		S=turn(N-1-j,S);
		S=turn(1,S);
		S=turn(N,S);
	}
	
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
	
	/*
	queue<string> Q;
	M["XaYZ"]=0;
	Q.push("XaYZ");
	while(Q.size()) {
		string S=Q.front();
		Q.pop();
		if(S[2]=='a' && S[3]=='Z') cout<<S<<" "<<M[S]<<endl;
		if(S[2]=='Z' && S[3]=='a') cout<<S<<" "<<M[S]<<endl;
		FOR(i,4) {
			string T;
			if(i==0) T=rev(S[3])+S.substr(0,3);
			if(i==1) T=rev(S[3])+rev(S[2])+S.substr(0,2);
			if(i==2) T=rev(S[3])+rev(S[2])+rev(S[1])+S.substr(0,1);
			if(i==3) T=rev(S[3])+rev(S[2])+rev(S[1])+rev(S[0]);
			
			if(M.count(T)==0) {
				cout<<S<<" -> "<<T<<endl;
				M[T]=M[S]+1;
				Q.push(T);
			}
		}
	}
	*/
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}