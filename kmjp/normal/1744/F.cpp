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
int rev[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			rev[P[i]]=i;
		}
		ll ret=1;
		int L=N,R=-1;;
		FOR(i,N-1) {
			L=min(L,rev[i]);
			R=max(R,rev[i]);
			if(L<=rev[i+1]&&rev[i+1]<=R) continue;
			int len=R-L+1;
			int les=i+1;
			les-=len-les;
			if(les<0) continue;
			int TL=0,TR=N-1;
			if(rev[i+1]<L) TL=rev[i+1]+1;
			if(rev[i+1]>R) TR=rev[i+1]-1;
			TL=min(les,L-TL);
			TR=min(les,TR-R);
			
			ret+=1LL*(TL+1)*(TR+1);
			int over=TL+TR-les;
			if(over>0) ret-=1LL*over*(over+1)/2;
			
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}