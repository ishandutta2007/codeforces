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
int L[2020];

int ask(int w) {
	cout<<"? "<<w<<endl;
	cin>>w;
	return w;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	// get total
	int ma=1<<24;
	for(i=23;i>=0;i--) if(ask(ma-(1<<i))==1) ma-=1<<i;
	int ret=ma;
	for(i=2;i<=N;i++) {
		int w=(ma+i-1)/i;
		w--;
		if(w>0&&ask(w)==i) ret=min(ret,i*w);
	}
	cout<<"! "<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}