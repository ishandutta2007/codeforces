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
int N;
int A[202020];
int B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(x,T) {
		
		cin>>N;
		int num=0;
		FOR(i,N) {
			cin>>A[i];
			num^=A[i];
		}
		/*
		
		if(T>100) {
			if(x!=67) continue;
			FOR(i,N) cout<<A[i];
			cout<<endl;
		}
		*/
		if(num) {
			cout<<"NO"<<endl;
			continue;
		}
		vector<int> ret;
		
		if(N%2) {
			for(i=0;i<N-1;i+=2) ret.push_back(i+1);
			for(i=N-5;i>=0;i-=2) ret.push_back(i+1);
		}
		else {
			num=0;
			for(i=0;i<N;i++) {
				num^=A[i];
				if(num==0&&i%2==0) {
					for(j=0;j<i;j+=2) ret.push_back(j+1);
					for(j=i-4;j>=0;j-=2) ret.push_back(j+1);
					FOR(j,i+1) A[j]=0;
					
					for(j=N-3;j>=i;j-=2) ret.push_back(j+1);
					for(j=i+1;j<N-2;j+=2) ret.push_back(j+1);
					for(j=i;j<N;j++) A[j]=0;
					break;
				}
			}
			
			FOR(i,N) if(A[i]) break;
			if(i<N) {
				cout<<"NO"<<endl;
				continue;
			}
			
		}
		cout<<"YES"<<endl;
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r<<" ";
		cout<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}