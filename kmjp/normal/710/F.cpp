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

class ACmatch_num {
public:
	Trie t;
	vector<int> acc;
	int ma;
	void create(vector<string> S) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		FOR(i,S.size()) acc[t.find(S[i])]++;
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
	int match(string S) {
		int R=0;
		int cur=0;
		ITR(it,S) {
			while(cur && t.V[cur][*it+1]==0) cur=t.V[cur][0];
			cur=t.V[cur][*it+1];
			R+=acc[cur];
		}
		return R;
	}
};

int M;

vector<string> V[2];
ACmatch_num acm[2][20];

void build(int id,string s) {
	V[id].push_back(s);
	int cn=V[id].size(), pn=V[id].size()-1, tot=0;
	int i,j;
	for(i=19;i>=0;i--) if(cn&(1<<i)) {
		if((pn&(1<<i))==0) {
			vector<string> S;
			FOR(j,1<<i) S.push_back(V[id][tot+j]);
			acm[id][i].create(S);
		}
		tot+=1<<i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	while(M--) {
		cin>>i>>s;
		FORR(c,s) c-='a';
		if(i<=2) build(i-1,s);
		else {
			ll ret=0;
			for(i=19;i>=0;i--) {
				if(V[0].size()&(1<<i)) ret+=acm[0][i].match(s);
				if(V[1].size()&(1<<i)) ret-=acm[1][i].match(s);
			}
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}