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


int K;
vector<string> T;
vector<int> C;
string S;
int N;

ll dp[1<<14][1010];
ll dp2[1<<14][1010];
vector<int> cand[15];

const int NUMC=14;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][*c+1]=V.size()-1;
				cur=V[cur][*c+1];
			}
		}
	}
};

class ACmatch_num {
public:
	Trie t;
	vector<int> acc;
	int ma;
	void create(vector<string> S,vector<int> C) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		FOR(i,S.size()) acc[t.find(S[i])]+=C[i];
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
};
ACmatch_num ac;
const int CH=14;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) {
		cin>>s>>x;
		FORR(c,s) c-='a';
		T.push_back(s);
		C.push_back(x);
	}
	ac.create(T,C);
	cin>>S;
	N=S.size();
	
	
	FOR(i,1<<CH) cand[__builtin_popcount(i)].push_back(i);
	
	int table[1010];
	ll add[1010];
	
	FOR(i,1<<CH) FOR(j,1005) dp[i][j]=-1LL<<60;
	dp[0][0]=0;
	int did=0;
	int cur=0;
	while(cur<N) {
		int tar=cur;
		while(tar<N&&S[tar]!='?') tar++;
		if(cur!=tar) {
			FOR(i,ac.t.V.size()) {
				int cn=i;
				ll sc=0;
				for(x=cur;x<tar;x++) {
					int p=cn;
					while(cn&&ac.t.V[cn][S[x]-'a'+1]==0) cn=ac.t.V[cn][0];
					cn=ac.t.V[cn][S[x]-'a'+1];
					ac.t.V[p][S[x]-'a'+1]=cn;
					sc+=ac.acc[cn];
				}
				table[i]=cn;
				add[i]=sc;
			}
			FORR(d,cand[did]) {
				FOR(i,ac.t.V.size()) dp2[d][i]=dp[d][i],dp[d][i]=-1LL<<60;
			}
			FORR(d,cand[did]) {
				FOR(i,ac.t.V.size()) {
					x=table[i];
					dp[d][x]=max(dp[d][x],dp2[d][i]+add[i]);
				}
			}
		}
		cur=tar;
		if(cur==N) break;
		
		FORR(d,cand[did]) {
			FOR(i,ac.t.V.size()) {
				FOR(j,CH) if((d&(1<<j))==0) {
					x=y=i;
					while(x&&ac.t.V[x][j+1]==0) x=ac.t.V[x][0];
					x=ac.t.V[x][j+1];
					ac.t.V[y][j+1]=x;
					dp[d|(1<<j)][x]=max(dp[d|(1<<j)][x],dp[d][i]+ac.acc[x]);
					//cout<<d<<" "<<i<<" "<<j<<" "<<x<<" "<<dp[d][i]<<"+"<<ac.acc[x]<<endl;
				}
			}
		}
		
		cur++;
		did++;
	}
	
	
	ll ret=-1LL<<60;
	FOR(j,1<<CH) if(__builtin_popcount(j)==did) {
		FOR(i,ac.t.V.size()) ret=max(ret,dp[j][i]);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}