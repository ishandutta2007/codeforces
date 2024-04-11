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
int N,M;
int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&N,&M,&K);
		vector<int> Vs,Hs;
		FOR(i,N) {
			scanf("%d",&x);
			Vs.push_back(x);
		}
		FOR(i,M) {
			scanf("%d",&y);
			Hs.push_back(y);
		}
		vector<pair<int,int>> onV,onH;
		FOR(i,K) {
			scanf("%d%d",&x,&y);
			j=lower_bound(ALL(Vs),x)-Vs.begin();
			k=lower_bound(ALL(Hs),y)-Hs.begin();
			if(Vs[j]==x&&Hs[k]==y) continue;
			if(Vs[j]==x) onV.push_back({y,x});
			else onH.push_back({x,y});
		}
		
		ll ret=0;
		sort(ALL(onH));
		sort(ALL(onV));
		int sum=0;
		map<int,int> Xs,Ys;
		queue<pair<int,int>> Q;
		FORR2(x,y,onH) {
			k=lower_bound(ALL(Vs),x)-Vs.begin()-1;
			while(Q.size()&&Q.front().first<=Vs[k]) {
				sum--;
				Ys[Q.front().second]--;
				Q.pop();
			}
			
			ret+=sum-Ys[y];
			
			sum++;
			Ys[y]++;
			Q.push({x,y});
		}
		sum=0;
		while(Q.size()) Q.pop();
		
		FORR2(y,x,onV) {
			k=lower_bound(ALL(Hs),y)-Hs.begin()-1;
			while(Q.size()&&Q.front().first<=Hs[k]) {
				sum--;
				Xs[Q.front().second]--;
				Q.pop();
			}
			
			ret+=sum-Xs[x];
			
			sum++;
			Xs[x]++;
			Q.push({y,x});
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