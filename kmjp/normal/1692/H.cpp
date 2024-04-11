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


int T,N,X[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,vector<int>> M;
		FOR(i,N) {
			cin>>x;
			M[x].push_back(i);
		}
		int ma=0;
		int A=0,L=0,R=0;
		FORR2(a,b,M) {
			int pre=-1<<20,PL=-1<<20;
			int num=0;
			FORR(x,b) {
				num-=x-pre-1;
				if(num<0) {
					num=0;
					PL=x;
				}
				num++;
				if(num>ma) {
					A=a;
					ma=num;
					L=PL;
					R=x;
				}
				pre=x;
			}
		}
		
		cout<<A<<" "<<(L+1)<<" "<<(R+1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}