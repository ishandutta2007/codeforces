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
string L,R,X;

string inc(string S) {
	int i;
	for(i=S.size()-1;i>=0;i--) {
		if(S[i]=='1') {
			S[i]='0';
		}
		else {
			S[i]++;
			return S;
		}
	}
	S="2";
	return S;
}
string dec(string S) {
	int i;
	for(i=S.size()-1;i>=0;i--) {
		if(S[i]=='0') {
			S[i]='1';
		}
		else {
			S[i]--;
			return S;
		}
	}
	S="0";
	S[0]--;
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>L>>R;
	
	N+=2;
	L="00"+L;
	R="00"+R;
	X=R;
	
	int cx=(L[N-2]-'0')*2+L[N-1]-'0';
	int cy=(R[N-2]-'0')*2+R[N-1]-'0';
	FOR(x,4) FOR(y,4) {
		string L2=L.substr(0,N-2);
		string R2=R.substr(0,N-2);
		if(x<cx) L2=inc(L2);
		if(y>cy) R2=dec(R2);
		if(L2>R2) continue;
		// same
		if(y>=x) {
			r=0;
			int par=0;
			for(i=x;i<=y;i++) r^=i,par^=1;
			string T;
			if(par) T=R2;
			else T=string(N-2,'0');
			T.push_back('0'+r/2);
			T.push_back('0'+r%2);
			X=max(X,T);
		}
		
		if(L2<R2) {
			r=0;
			int p1=0,p2=0;
			for(i=x;i<=3;i++) r^=i,p1^=1;
			for(i=0;i<=y;i++) r^=i,p2^=1;
			string T;
			
			if(p1==0&&p2==0) {
				T=string(N-2,'0');
			}
			else if(p1==1&&p2==0) {
				T=dec(R2);
			}
			else if(p1==0&&p2==1) {
				T=R2;
			}
			else {
				int ok=0;
				FOR(i,N-2) {
					if(R2[i]=='1'&&L2[i]=='0') ok=1;
					T.push_back('0'+ok);
				}
			}
			
			T.push_back('0'+r/2);
			T.push_back('0'+r%2);
			X=max(X,T);
		}
		
	}
	cout<<X.substr(2)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}