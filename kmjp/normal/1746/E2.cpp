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
int T[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> A,B;
	FOR(i,N) A.push_back(i+1);
	while(A.size()+B.size()>2) {
		int a1=min(A.size(),A.size()/2+B.size()%2);
		int b1=B.size()/2;
		int c=a1+b1;
		cout<<"? "<<c<<endl;
		FOR(i,a1) cout<<A[i]<<" ";
		FOR(i,b1) cout<<B[i]<<" ";
		cout<<endl;
		cin>>s;
		vector<int> PA=A,PB=B;
		A.clear(),B.clear();
		if(s=="YES") {
			FOR(i,PA.size()) {
				if(i<a1) A.push_back(PA[i]);
				else B.push_back(PA[i]);
			}
			FOR(i,b1) A.push_back(PB[i]);
		}
		else {
			FOR(i,PA.size()) {
				if(i<a1) B.push_back(PA[i]);
				else A.push_back(PA[i]);
			}
			for(i=b1;i<PB.size();i++) A.push_back(PB[i]);
		}
	}
	FORR(b,B) A.push_back(b);
	
	cout<<"! "<<A[0]<<endl;
	cin>>s;
	if(s==":(") {
		cout<<"! "<<A[1]<<endl;
		cin>>s;
		assert(s==":)");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}