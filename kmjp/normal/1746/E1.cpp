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
	
	int mask;
	
	FOR(T[0],32) 
	FOR(T[1],32) 
	FOR(T[2],32) 
	FOR(T[3],32) {
		int ok=1;
		FOR(mask,1<<5) {
			int sum=0;
			
			FOR(i,4) {
				int d=mask^T[i];
				if((d&(d>>1))==0) sum++;
			}
			
			if(sum>2) ok=0;
			
		}
		
		if((T[0]|T[1]|T[2])!=31) ok=0;
		if(ok) goto start;
	}
	
	return;
	start:
	cerr<<T[0]<<" "<<T[1]<<" "<<T[2]<<" "<<T[3]<<endl;
	cin>>N;
	vector<int> C;
	FOR(i,N) C.push_back(i+1);
	while(C.size()>2) {
		vector<int> X[4];
		FOR(i,C.size()) X[i%4].push_back(C[i]);
		
		int ret=0;
		FOR(i,5) {
			vector<int> V;
			FOR(j,4) if(T[j]&(1<<i)) {
				FORR(v,X[j]) V.push_back(v);
			}
			sort(ALL(V));
			cout<<"? "<<V.size();
			FORR(v,V) cout<<" "<<v;
			cout<<endl;
			cin>>s;
			if(s=="YES") ret|=1<<i;
		}
		C.clear();
		FOR(i,4) {
			int d=ret^T[i];
			if((d&(d>>1))==0) {
				FORR(v,X[i]) C.push_back(v);
			}
		}
		
		
	}
	
	cout<<"! "<<C[0]<<endl;
	cin>>s;
	if(s==":(") {
		cout<<"! "<<C[1]<<endl;
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