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
int R[3],C[3],Y,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,3) {
			cin>>R[i]>>C[i];
			R[i]--,C[i]--;
		}
		cin>>Y>>X;
		Y--,X--;
		
		FOR(i,3) if(R[i]==Y&&C[i]==X) break;
		if(i<3) {
			cout<<"YES"<<endl;
			continue;
		}
		
		int CY,CX;
		if(R[0]==R[1]) CY=R[0];
		if(R[1]==R[2]) CY=R[1];
		if(R[0]==R[2]) CY=R[0];
		if(C[0]==C[1]) CX=C[0];
		if(C[1]==C[2]) CX=C[1];
		if(C[0]==C[2]) CX=C[0];
		
		if(CX==X||CY==Y) {
			cout<<"YES"<<endl;
			continue;
		}
		if((CX==0||CX==N-1)&&(CY==0||CY==N-1)) {
			cout<<"NO"<<endl;
			continue;
		}
		if((CX+CY)%2!=(X+Y)%2) {
			cout<<"YES"<<endl;
			continue;
		}
		else if((CX)%2==X%2&&CY%2==Y%2) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}