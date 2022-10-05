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

int T,L,R;
vector<int> V[202020],W[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=200000;i++) {
		for(j=2*i;j<=200000;j+=i) {
			
			V[j].push_back(i);
			if(j%(2*i)) W[j].push_back(2*i);
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		ll ret=1LL*(R-L+1)*(R-L)*(R-L-1)/6;
		
		for(i=L;i<=R;i++) {
			x=V[i].end()-lower_bound(ALL(V[i]),L);
			y=W[i].end()-lower_bound(ALL(W[i]),L);
			// LCM(i,j,k)==k;
			ret-=1LL*x*(x-1)/2;
			// LCM(i,j,k)==2*k;
			// (3:4:6)->13>6*2
			if(i%6==0&&i/2>=L) ret--;
			// (6:10:15)->31>15*2
			if(i%15==0&&i/5*2>=L) ret--;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}