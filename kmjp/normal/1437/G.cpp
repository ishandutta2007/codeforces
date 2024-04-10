#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int NUMC=26;
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

int tid;
class ACmatch_enum {
public:
	Trie t;
	vector<multiset<int> > acc;
	vector<int> po;
	vector<int> ev;
	int ma;
	void create(vector<string> S) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		ev.resize(t.V.size());
		po.resize(ma);
		
		FOR(i,S.size()) {
			po[i]=t.find(S[i]);
			acc[po[i]].insert(0);
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
			}
		}
	}

	int match(string S) {
		int ret=-1;
		tid++;
		int cur=0;
		FORR(c,S) {
			c-='a';
			while(cur && t.V[cur][c+1]==0) cur=t.V[cur][0];
			cur=t.V[cur][c+1];
			int tmp=cur;
			while(tmp&&ev[tmp]<tid) {
				ev[tmp]=tid;
				if(acc[tmp].size()) ret=max(ret,*acc[tmp].rbegin());
				tmp=t.V[tmp][0];
			}
		}
		return ret;
	}
};

int N,M;
vector<string> S;
string T;
int V[303030];
ACmatch_enum ac;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		S.push_back(s);
	}
	ac.create(S);
	
	FOR(i,M) {
		cin>>j;
		if(j==1) {
			cin>>x>>y;
			x--;
			ac.acc[ac.po[x]].erase(ac.acc[ac.po[x]].find(V[x]));
			V[x]=y;
			ac.acc[ac.po[x]].insert(y);
		}
		else {
			cin>>T;
			cout<<ac.match(T)<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}