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

int N;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	reverse(ALL(S));
	while(S.size()&&S.back()=='0') S.pop_back();
	reverse(ALL(S));
	if(S.empty()) {
		cout<<0<<endl;
		return;
	}
	vector<int> C,D;
	
	N=S.size();
	T=S;
	
	FOR(i,N) {
		if(S[i]=='0') C.push_back(i);
		else if(C.empty()) D.push_back(i);
	}
	int pre=-1;
	FORR(c,C) {
		if(pre==-1) {
			S[c]='1';
		}
		else {
			vector<int> E;
			FORR(d,D) {
				if(d+c-pre<N&&T[d+c-pre]=='1') E.push_back(d+c-pre);
			}
			if(E.empty()) continue;
			S[c]='1';
			swap(D,E);
		}
		pre=c;
	}
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}