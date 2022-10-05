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
int L;
int num[10];

void out(int x) { while(num[x]-->0) _P("%d",x);}
void outT() { _P("%s",T.c_str()); T="";}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	FORR(r,S) num[r-'0']++;
	FORR(r,T) num[r-'0']--;
	x=S.size();
	y=1;
	for(i=1;i<=7;i++) {
		if(x-i>=y && x-i<y*10) {
			L=x-i;
			break;
		}
		y*=10;
	}
	x=L;
	while(x) num[x%10]--, x/=10;
	
	if(T[0]=='0') {
		for(i=1;i<=9;i++) if(num[i]) {
			num[i]--;
			_P("%d",i);
			break;
		}
		out(0);
		outT();
		for(i=1;i<=9;i++) out(i);
	}
	else {
		if(num[0]) {
			stringstream ss;
			FOR(i,T.size()) {
				FOR(x,10) if((i!=0 || x!=0) && num[x]) {
					num[x]--;
					ss << x;
					break;
				}
			}
			string U;
			U=ss.str();
			FORR(c,U) num[c-'0']++;
			if(T+U<U+T) {
				outT();
			}
			else {
				for(i=1;i<=9;i++) if(num[i] && i<=T[0]-'0') {
					num[i]--;
					_P("%d",i);
					break;
				}
				if(i==10) outT();
			}
			out(0);
		}
		for(i=1;i<=9;i++) if(num[i]) {
			if(T.size() && i==T[0]-'0') {
				int small=0;
				for(j=1;j<T.size();j++) {
					if(T[j]<T[0]) break;
					if(T[j]>T[0]) j=T.size();
				}
				if(j<T.size()) outT();
				out(i);
				outT();
			}
			else {
				out(i);
			}
		}
		_P("%s",T.c_str());
	}
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}