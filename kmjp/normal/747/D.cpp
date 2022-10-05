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

int N,K;
int T[202020];
multiset<int> S;
int NN;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int first=1;
	y=0;
	int flip=0;
	FOR(i,N) {
		cin>>x;
		if(x>=0 && first) continue;
		if(x<0) {
			if(first||y) {
				first=0;
				if(y) S.insert(y);
				flip+=2;
			}
			K--;
			y=0;
		}
		else {
			y++;
		}
	}
	if(first) return _P("0\n");
	if(K<0) return _P("-1\n");
	while(S.size()) {
		if(K>=*S.begin()) {
			K -= *S.begin();
			flip-=2;
			S.erase(S.begin());
		}
		else break;
	}
	if(K>=y) flip--;
	cout<<flip<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}