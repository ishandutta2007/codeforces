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

int T;
int N,K;
vector<int> E[404040];
int D[404040];
int del[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			E[i].clear();
			D[i]=1<<20;
			del[i]=0;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
			del[x-1]++;
			del[y-1]++;
		}
		queue<int> Q;
		int num=0;
		FOR(i,N) if(E[i].size()<=1) {
			D[i]=0;
			Q.push(i);
		}
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(D[e]==1<<20) {
				del[e]--;
				if(del[e]<=1) {
					D[e]=D[x]+1;
					if(D[e]>=K) num++;
					Q.push(e);
				}
			}
		}
		cout<<num<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}