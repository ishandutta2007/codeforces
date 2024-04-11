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
int C[1010];
string S[2020];

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		FORR(c,s) if((cur=V[cur][c+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		FORR(s,S) {
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][c+1]=V.size()-1;
				cur=V[cur][c+1];
			}
		}
	}
};

class ACmatch_sum {
public:
	Trie t;
	
	vector<ll> acc;
	map<pair<int,int>,int> memo;
	int ma;
	void create(vector<string> S,vector<int> C) { //
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		memo.clear();
		FOR(i,S.size()) {
			int cur=t.find(S[i]);
			acc[cur]+=C[i];
		}
		queue<int> Q;
		FOR(i,NUMC) if(t.V[0][i+1]) t.V[t.V[0][i+1]][0]=0, Q.push(t.V[0][i+1]);
		
		while(!Q.empty()) {
			int k=Q.front(); Q.pop();
			FOR(i,NUMC) if(t.V[k][i+1]) {
				Q.push(t.V[k][i+1]);
				int pre=t.V[k][0];
				while(pre && t.V[pre][i+1]==0) pre=t.V[pre][0];
				t.V[t.V[k][i+1]][0]=t.V[pre][i+1];
				acc[t.V[k][i+1]] += acc[t.V[pre][i+1]];
			}
		}
	}
	int nex(int cur,int c) {
		if(memo.count({cur,c})) return memo[{cur,c}];
		if(cur && t.V[cur][c+1]==0) return memo[{cur,c}]=nex(t.V[cur][0],c);
		return memo[{cur,c}]=t.V[cur][c+1];
	}
	ll match(string S) {
		ll R=0;
		int cur=0;
		FORR(c,S) {
			cur=nex(cur,c);
			R += acc[cur];
		}
		return R;
	}
};

vector<string> Ss;
vector<int> Cs;
ACmatch_sum ac;

map<int,pair<ll,string>> dp[1<<12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i]>>S[i];
		int cur=1;
		string T;
		T=S[i].substr(0,2);
		for(j=2;j<S[i].size();j++) {
			if(cur&&S[i][j]==T[cur-1]) {
				cur--;
				continue;
			}
			if(cur+1<T.size()&&S[i][j]==T[cur+1]) {
				cur++;
				continue;
			}
			if(cur==0) {
				T=S[i].substr(j,1)+T;
			}
			else if(cur==T.size()-1) {
				T+=S[i][j];
				cur++;
			}
			else {
				break;
			}
		}
		if(j==S[i].size()) {
			set<int> CC;
			int ok=1;
			FORR(c,T) {
				c-='a';
				if(CC.count(c)) ok=0;
				CC.insert(c);
			}
			if(ok) {
				Ss.push_back(T);
				reverse(ALL(T));
				Ss.push_back(T);
				Cs.push_back(C[i]);
				Cs.push_back(C[i]);
			}
		}
	}
	ac.create(Ss,Cs);
	dp[0][0]={0LL,""};
	int mask;
	pair<ll,string> ret;
	FOR(mask,1<<12) {
		FORR2(cur,sc,dp[mask]) {
			if(mask==(1<<12)-1) {
				ret=max(ret,sc);
				continue;
			}
			FOR(i,12) if((mask&(1<<i))==0) {
				auto sc2=sc;
				int ncur=ac.nex(cur,i);
				sc2.first+=ac.acc[ncur];
				sc2.second.push_back(i);
				dp[mask|(1<<i)][ncur]=max(dp[mask|(1<<i)][ncur],sc2);
				
			}
		}
	}
	FORR(c,ret.second) cout<<(char)('a'+c);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}