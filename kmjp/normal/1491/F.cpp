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
int R[2020];

int ask(int a,int L,int R) {
	cout<<"? 1 "<<(R-L+1)<<endl;
	cout<<a<<endl;
	int i;
	for(i=L;i<=R;i++) cout<<i<<" ";
	cout<<endl;
	cin>>i;
	return i;
}

vector<int> hoge() {
	int i;
	
	int tar=-1;
	ZERO(R);
	for(i=2;i<=N;i++) {
		if(tar==-1) {
			R[i]=ask(i,1,i-1);
			if(R[i]) tar=i;
		}
		else {
			R[i]=ask(i,tar,tar);
		}
	}
	int A=1,B=tar;
	while(A+1<B) {
		int M=(A+B)/2;
		if(ask(tar,A,M-1)) {
			B=M;
		}
		else {
			A=M;
		}
	}
	R[A]=1;
	
	
	vector<int> cand;
	for(i=1;i<=N;i++) if(R[i]==0) cand.push_back(i);
	return cand;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		auto a=hoge();
		cout<<"!"<<" "<<a.size();
		FORR(v,a) cout<<" "<<v;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}