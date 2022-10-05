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
int V[101010];
int C[101010]={0,0,1,0,1,0};
int ask(int a,int b,int c) {
	cout<<"? "<<(a+1)<<" "<<(b+1)<<" "<<(c+1)<<endl;
//	return C[a]+C[b]+C[c]>=2;
	cin>>a;
	return a;
}

void ans() {
	int i,n=0;
	FOR(i,N) n+=1-P[i];
	cout<<"! "<<n;
	
	FOR(i,N) if(P[i]==0) cout<<" "<<(i+1);
	cout<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(P);
		
		FOR(i,N-2) {
			V[i]=ask(i,i+1,i+2);
		}
		FOR(i,N-3) {
			if(V[i]!=V[i+1]) {
				x=i;
				P[i]=V[i];
				P[i+3]=V[i+1];
				break;
			}
		}
		FOR(i,N) if(i!=x&&i!=x+3) {
			P[i]=ask(x,x+3,i);
		}
		ans();
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}