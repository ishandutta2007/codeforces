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

int P[202020];

void hoge(int a,int b,int turn=0) {
	if(P[a]&&P[b]) return;
	if(P[b]) swap(a,b);
	if(P[a]) {
		int v;
		
		if(P[a]==N) {
			cout<<"? 2 "<<(b+1)<<" "<<(a+1)<<" "<<1<<endl;
			cin>>P[b];
			return;
		}
		cout<<"? 1 "<<(a+1)<<" "<<(b+1)<<" "<<P[a]<<endl;
		cin>>v;
		if(v==P[a]+1) {
			cout<<"? 1 "<<(a+1)<<" "<<(b+1)<<" "<<(N-1)<<endl;
			cin>>P[b];
			return;
		}
		cout<<"? 2 "<<(b+1)<<" "<<(a+1)<<" "<<1<<endl;
		cin>>P[b];
		return;
	}
	
	int ma;
	cout<<"? 1 "<<(a+1)<<" "<<(b+1)<<" "<<(N-1)<<endl;
	cin>>ma;
	int mi;
	cout<<"? 2 "<<(a+1)<<" "<<(b+1)<<" "<<1<<endl;
	cin>>mi;
	int v;
	if(ma==N) {
		P[b]=N;
		P[a]=mi;
	}
	else if(mi==1) {
		P[a]=1;
		P[b]=ma;
	}
	else if(ma!=N-1&&mi!=2) {
		cout<<"? 2 "<<(a+1)<<" "<<(b+1)<<" "<<mi<<endl;
		cin>>v;
		if(v==mi) {
			P[a]=mi;
			P[b]=ma;
		}
		else {
			P[a]=ma;
			P[b]=mi;
		}
	}
	else {
		if(turn==0) hoge(b,a,1);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+1) P[i]=0;
		
		if(N<=5) {
			FOR(y,N) FOR(x,y) hoge(x,y,0);
		}
		else {
			for(i=0;i<N;i+=2) {
				if(i==N-1) {
					hoge(i-1,i);
				}
				else {
					hoge(i,i+1);
				}
			}
		}
			vector<int> Q[2];
			FOR(i,N) Q[P[i]!=0].push_back(i);
			FORR(c,Q[0]) {
				FORR(r,Q[1]) {
					if(P[c]) break;
					hoge(c,r,0);
				}
				Q[1].push_back(c);
			}
		
		cout<<"!";
		FOR(i,N) cout<<" "<<P[i];
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}