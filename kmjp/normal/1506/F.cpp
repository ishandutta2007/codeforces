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

int T,N;
pair<int,int> P[202020];

ll hoge(int R1,int C1,int R2,int C2) {
	
	int left=(R2-R1)-(C2-C1);
	
	if(left==0) {
		if((R1+C1)%2) return 0;
		else return R2-R1;
	}
	else {
		if((R1+C1)%2==0) return left/2;
		else return (left+1)/2;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		P[0]={1,1};
		FOR(i,N) cin>>P[i+1].first;
		FOR(i,N) cin>>P[i+1].second;
		sort(P,P+N+1);
		ll ret=0;
		FOR(i,N) {
			ret+=hoge(P[i].first,P[i].second,P[i+1].first,P[i+1].second);
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