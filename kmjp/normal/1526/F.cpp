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
int P[101010];
int A[101010];


int ask(int a,int b,int c) {
	cout<<"? "<<(a+1)<<" "<<(b+1)<<" "<<(c+1)<<endl;
	cin>>a;
	return a;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int C[3]={-1,-1};
		
		FOR(i,13) FOR(y,i) FOR(x,y) if(C[0]==-1) {
			k=ask(x,y,i);
			if(k<=(N-4)/6) {
				C[0]=x;
				C[1]=y;
			}
		}
		assert(C[0]>=0);
		vector<pair<int,int>> V;
		FOR(i,N) if(i!=C[0]&&i!=C[1]) V.push_back({-ask(i,C[0],C[1]),i});
		sort(ALL(V));
		
		if(V[0].first==V[1].first) {
			assert(V[1].first!=V[2].first);
			swap(V[1],V[2]);
			swap(V[2],V[3]);
		}
		if(V[1].first==V[2].first) {
			FOR(i,N) if(i!=V[0].second&&i!=V[1].second&&i!=V[2].second&&i!=V[3].second) break;
			x=ask(V[0].second,V[1].second,i);
			y=ask(V[0].second,V[2].second,i);
			if(y<x) swap(V[1],V[2]);
		}
		
		x=V[0].second;
		P[x]=1;
		y=V[1].second;
		P[y]=2;
		FOR(i,N) if(i!=x&&i!=y) P[i]=ask(i,x,y)+2;
		
		if(P[0]>P[1]) {
			FOR(i,N) P[i]=N+1-P[i];
		}
		
		
		cout<<"!";
		FOR(i,N) cout<<" "<<P[i];
		cout<<endl;
		cin>>x;
		assert(x==1);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}