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

int N,M;
int V[505];
int A[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<pair<int,int>> C;
	FOR(i,M) {
		cout<<"? ";
		FOR(j,M) cout<<(i==j);
		cout<<endl;
		cin>>V[i];
		C.push_back({V[i],i});
	}
	sort(ALL(C));
	int pre=0;
	FORR2(a,b,C) {
		A[b]=1;
		cout<<"? ";
		FOR(j,M) cout<<A[j];
		cout<<endl;
		cin>>x;
		
		if(pre+a==x) {
			pre+=a;
		}
		else {
			A[b]=0;
		}
	}
	cout<<"! "<<pre<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}