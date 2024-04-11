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

int T,K;
ll C[101];
ll F[100],S[100];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=F[1]=1;
	S[0]=1;
	S[1]=2;
	for(i=2;i<=60;i++) {
		F[i]=F[i-1]+F[i-2];
		S[i]=S[i-1]+F[i];
	}
	
	cin>>T;
	while(T--) {
		cin>>K;
		ll sum=0;
		set<pair<ll,int>> M;
		FOR(i,K) {
			cin>>C[i];
			sum+=C[i];
			M.insert({C[i],i});
		}
		int tar;
		FOR(tar,60) if(S[tar]==sum) break;
		if(tar==60) {
			cout<<"NO"<<endl;
			continue;
		}
		pair<ll,int> pre={-1,-1};
		while(tar>=0) {
			if(M.empty()) break;
			pair<ll,int> a=*M.rbegin();
			
			if(a.first<F[tar]) break;
			M.erase(a);
			if(pre.first>=0) M.insert(pre);
			pre=a;
			pre.first-=F[tar];
			tar--;
		}
		if(tar==-1) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}