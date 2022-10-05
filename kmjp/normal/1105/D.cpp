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

int H,W,P;
int S[10];
string T[1010];
queue<int> Q[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>P;
	FOR(i,P) cin>>S[i];
	FOR(y,H) {
		cin>>T[y];
		FOR(x,W) {
			if(T[y][x]>='1' && T[y][x]<='9') Q[T[y][x]-'0'].push({y*1000+x});
		}
	}
	
	for(i=1;i<=1000000;i++) {
		for(j=1;j<=P;j++) {
			FOR(y,S[j-1]) {
				if(Q[j].empty()) break;
				queue<int> Q2;
				while(Q[j].size()) {
					int cy=Q[j].front()/1000;
					int cx=Q[j].front()%1000;
					Q[j].pop();
					FOR(x,4) {
						int d[4]={0,-1,0,1};
						int ty=cy+d[x];
						int tx=cx+d[x^1];
						if(ty<0||ty>=H||tx<0||tx>=W||T[ty][tx]!='.') continue;
						T[ty][tx]='0'+j;
						Q2.push(ty*1000+tx);
					}
				}
				swap(Q2,Q[j]);
			}
		}
	}
	
	int cnt[10]={};
	FOR(y,H) FOR(x,W) {
		if(T[y][x]>='1'&&T[y][x]<='9') cnt[T[y][x]-'1']++;
	}
	
	FOR(i,P) cout<<cnt[i]<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}