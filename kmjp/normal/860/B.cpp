#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[70707];
int num[70707][10][10];
map<int,int> M[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		for(int l=1;l<=9;l++) {
			for(x=0;x+l<=9;x++) {
				num[i][x][l]=stoi(S[i].substr(x,l).c_str());
				M[l][num[i][x][l]]++;
			}
		}
	}
	
	FOR(i,N) {
		for(int l=1;l<=9;l++) {
			int ret=-1;
			for(x=0;x+l<=9;x++) if(--M[l][num[i][x][l]]==0) ret=x;
			for(x=0;x+l<=9;x++) ++M[l][num[i][x][l]];
			
			if(ret>=0) {
				cout<<S[i].substr(ret,l)<<endl;
				break;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}