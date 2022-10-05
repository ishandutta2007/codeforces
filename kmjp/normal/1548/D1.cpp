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
int X[10101],Y[10101];
int P[4][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]/=2;
		Y[i]/=2;
		X[i]%=2;
		Y[i]%=2;
		P[X[i]][Y[i]]++;
	}
	ll ret=0;
	FOR(i,N) {
		P[X[i]][Y[i]]--;
		for(j=i+1;j<N;j++) {
			P[X[j]][Y[j]]--;
			
			FOR(x,2) FOR(y,2) {
				int dx1=x-X[i];
				int dy1=y-Y[i];
				int dx2=X[j]-X[i];
				int dy2=Y[j]-Y[i];
				int s=abs(dx1*dy2-dx2*dy1)%2;
				int b=((X[i]==X[j])&&(Y[i]==Y[j]))^((X[i]==x)&&(Y[i]==y))^((X[j]==x)&&(Y[j]==y));
				s=0;
				if((s^b)) ret+=P[x][y];
				
				
				
			}
		}
		for(j=i+1;j<N;j++) P[X[j]][Y[j]]++;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}