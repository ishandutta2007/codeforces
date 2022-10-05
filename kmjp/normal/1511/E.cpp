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

int H,W;
int TW;
string S[303030];
const ll mo=998244353;
ll p2[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,301010) p2[i+1]=p2[i]*2%mo;
	
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='o') TW++;
	}
	ll ret=0;
	FOR(y,H) {
		ll p[2]={1,0};
		int lef=TW;
		FOR(x,W) {
			if(S[y][x]=='*') {
				p[0]=(p[0]+p[1])%mo;
				p[1]=0;
			}
			else {
				ll t[2]={0,0};
				lef--;
				// blue
				t[1]+=p[0];
				t[0]+=p[1];
				(ret+=p[1]*p2[lef])%=mo;
				//red
				t[0]+=p[0]+p[1];
				
				p[0]=t[0]%mo;
				p[1]=t[1]%mo;
			}
		}
	}
	FOR(x,W) {
		ll p[2]={1,0};
		int lef=TW;
		FOR(y,H) {
			if(S[y][x]=='*') {
				p[0]=(p[0]+p[1])%mo;
				p[1]=0;
			}
			else {
				ll t[2]={0,0};
				lef--;
				// blue
				t[1]+=p[0];
				t[0]+=p[1];
				(ret+=p[1]*p2[lef])%=mo;
				//red
				t[0]+=p[0]+p[1];
				
				p[0]=t[0]%mo;
				p[1]=t[1]%mo;
			}
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}