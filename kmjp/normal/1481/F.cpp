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

int N,K;
int leaf[101010];
vector<int> E[101010];
vector<int> C[101010];
vector<int> num[101010];

int mad;
bitset<101010> cur,add;
int tar[101010];

void dfs(int cur,int d) {
	mad=max(mad,d);
	C[d].push_back(cur);
	FORR(e,E[cur]) dfs(e,d+1);
	leaf[cur]=(E[cur].empty());
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(i=1;i<N;i++) {
		cin>>x;
		E[x-1].push_back(i);
	}
	dfs(0,0);
	
	MINUS(tar);
	cur[0]=1;
	FOR(i,N+1) if(C[i].size()) {
		add=cur<<C[i].size();
		bitset<101010> dif=add&(~cur);
		cur|=add;
		for(j=dif._Find_first();j<dif.size();j=dif._Find_next(j)) {
			tar[j]=i;
		}
	}
	string S(N,'b');
	if(cur[K]==1) {
		while(K) {
			x=tar[K];
			FORR(v,C[x]) S[v]='a', K--;
		}
		
		cout<<mad+1<<endl;
		cout<<S<<endl;
	}
	else {
		int X=K,Y=N-K;
		vector<int> lef;
		FOR(i,N+1) if(C[i].size()) {
			if(C[i].size()<=X) {
				FORR(v,C[i]) S[v]='a';
				X-=C[i].size();
			}
			else if(C[i].size()<=Y) {
				FORR(v,C[i]) S[v]='b';
				Y-=C[i].size();
			}
			else {
				vector<int> V;
				FORR(v,C[i]) {
					if(leaf[v]) lef.push_back(v);
					else V.push_back(v);
				}
				if(V.size()<=X) {
					FORR(v,V) S[v]='a';
					X-=V.size();
				}
				else if(V.size()<=Y) {
					FORR(v,V) S[v]='b';
					Y-=V.size();
				}
				else assert(0);
			}
		}
		FORR(v,lef) {
			if(X) S[v]='a', X--;
			else if(Y) S[v]='b', Y--;
			
		}
		
		cout<<mad+2<<endl;
		cout<<S<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}