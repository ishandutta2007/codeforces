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
int N,D12,D23,D31;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>D12>>D23>>D31;
		int L=D12+D23+D31;
		if(L%2) {
			cout<<"NO"<<endl;
			continue;
		}
		L/=2;
		int C1=L-D23;
		int C2=L-D31;
		int C3=L-D12;
		if(C1+C2+C3+1>N) {
			cout<<"NO"<<endl;
			continue;
		}
		if(C1>L||C2>L||C3>L||C1<0||C2<0||C3<0) {
			cout<<"NO"<<endl;
			continue;
		}
		int nex=4;
		vector<pair<int,int>> V;
		int center;
		if(C1==0||C2==0||C3==0) {
			if(C1==0) center=1;
			if(C2==0) center=2;
			if(C3==0) center=3;
			nex=4;
		}
		else {
			center=4;
			nex=5;
		}
		int pre=center;
		int n;
		FOR(i,C1) {
			if(i==C1-1) n=1;
			else n=nex++;
			V.push_back({pre,n});
			pre=n;
		}
		pre=center;
		FOR(i,C2) {
			if(i==C2-1) n=2;
			else n=nex++;
			V.push_back({pre,n});
			pre=n;
		}
		pre=center;
		FOR(i,C3) {
			if(i==C3-1) n=3;
			else n=nex++;
			V.push_back({pre,n});
			pre=n;
		}
		while(nex<=N) {
			V.push_back({1,nex});
			nex++;
		}
		cout<<"YES"<<endl;
		FORR2(a,b,V) cout<<a<<" "<<b<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}