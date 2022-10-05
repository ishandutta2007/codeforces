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

ll pat[101];
ll p10[12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,11) p10[i+1]=p10[i]*10;
	
	
	cin>>T;
	while(T--) {
		cin>>S>>N;
		
		reverse(ALL(S));
		FORR(c,S) c-='0';
		
		while(1) {
			int sum=0;
			FORR(c,S) sum+=c;
			if(sum>=N) break;
			for(i=1;i<S.size();i++) if(S[i]) {
				S[i]--;
				S[i-1]+=10;
				break;
			}
		}
		
		ZERO(pat);
		int cur=0;
		FOR(i,S.size()) {
			while(S[i]) {
				pat[cur]+=p10[i];
				cur=(cur+1)%N;
				S[i]--;
			}
		}
		
		FOR(i,N) cout<<pat[i]<<" ";
		cout<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}