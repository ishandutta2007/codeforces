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

int T;
string S;
int N;

int ok(string S) {
	int cur=0;
	FORR(c,S) {
		if(c=='(') cur++;
		else cur--;
		if(cur<0) return 0;
	}
	return cur==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		if(N%2) {
			cout<<"NO"<<endl;
			continue;
		}
		int a=N/2,b=N/2;
		vector<int> V;
		FOR(i,N) {
			if(S[i]=='(') a--;
			if(S[i]==')') b--;
			if(S[i]=='?') V.push_back(i);
		}
		if(a<0||b<0) {
			cout<<"NO"<<endl;
		}
		else if(a==0||b==0) {
			FOR(i,V.size()) {
				if(a) S[V[i]]='(';
				else S[V[i]]=')';
			}
			if(ok(S)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else {
			string A=S,B=S;
			FOR(i,V.size()) {
				if(i<a) {
					A[V[i]]='(';
				}
				else {
					A[V[i]]=')';
				}
				if(i<a-1||i==a) {
					B[V[i]]='(';
				}
				if(i==a-1||i>a) {
					B[V[i]]=')';
				}
			}
			if(ok(A)&&!ok(B)) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
		}
			
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}