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
int X[252525],Y[252525];

map<int,int> memo[2020220];
pair<int,int> F[252525];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d%d",&X[i],&Y[i]);
		X[i]+=1010101;
		Y[i]+=1010101;
		memo[X[i]][Y[i]]=i;
	}
	MINUS(F);
	queue<pair<pair<int,int>,pair<int,int>>> Q;
	FOR(i,N) {
		int d[4]={0,1,0,-1};
		FOR(j,4) {
			int ty=Y[i]+d[j];
			int tx=X[i]+d[j^1];
			if(memo[tx].count(ty)) continue;
			Q.push({{ty,tx},{ty,tx}});
		}
	}
	while(Q.size()) {
		int cy=Q.front().first.first;
		int cx=Q.front().first.second;
		pair<int,int> f=Q.front().second;
		Q.pop();
		int d[4]={0,1,0,-1};
		FOR(j,4) {
			int ty=cy+d[j];
			int tx=cx+d[j^1];
			if(memo[tx].count(ty)) {
				r=memo[tx][ty];
				if(F[r].first==-1) {
					F[r]=f;
					Q.push({{ty,tx},f});
				}
			}
		}
	}
	
	FOR(i,N) {
		F[i].first-=1010101;
		F[i].second-=1010101;
		cout<<F[i].second<<" "<<F[i].first<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}