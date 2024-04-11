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
int A[151515];

int D[32768];
const int mo=32768;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,mo) D[i]=1<<30;
	D[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		vector<int> cand={(x+mo-1)%mo};
		if(x%2==0) cand.push_back(x/2),cand.push_back(x/2+mo/2);
		FORR(c,cand) {
			if(D[c]==1<<30) {
				D[c]=D[x]+1;
				Q.push(c);
			}
		}
	}
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		cout<<D[x]<<" ";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}