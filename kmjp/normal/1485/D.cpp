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

int H,W;
int A[505][505];
int cand[17];
int B[505][505];

vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=16;i++) {
		for(j=1;j<=100;j++) {
			if((720720-j*j*j*j)%i==0) {
				cand[i]=720720-j*j*j*j;
				break;
			}
		}
		
	}
	
	
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) {
			cin>>i;
			if((y+x)%2==0) j=720720;
			else j=cand[i];
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}