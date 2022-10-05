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

const int NUMC=11;
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
			R += acc[cur];
		}
		return R;
	}
};


int N,X;
string S;
ACmatch_num ac;

int from[6060];
int to[6060];
vector<string> NG;

void hoge(string& T,int ok) {
	int sum=0;
	int i;
	FOR(i,T.size()) {
		sum+=T[T.size()-1-i];
		if(sum<X&&X%sum==0) ok=1;
	}
	if(sum>X) return;
	if(sum==X) {
		if(ok==0) NG.push_back(T);
		return;
		
	}
	T.push_back(0);
	for(i=1;i<=9;i++) {
		T.back()=i;
		hoge(T,ok);
	}
	T.pop_back();
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>S>>X;
	string T;
	hoge(T,0);
	ac.create(NG);
	
	FOR(i,6000) from[i]=202020;
	from[0]=0;
	FORR(c,S) {
		c-='0';
		FOR(i,6000) to[i]=from[i]+1;
		
		FOR(i,ac.acc.size()) {
			int cur=i;
			while(cur && ac.t.V[cur][c+1]==0) cur=ac.t.V[cur][0];
			cur=ac.t.V[cur][c+1];
			to[cur]=min(to[cur],from[i]);
		}
		FOR(i,ac.acc.size()) if(ac.acc[i]) to[i]=202020;
		swap(from,to);
	}
	
	int mi=202020;
	FOR(i,ac.acc.size()) mi=min(mi,from[i]);
	if(mi>1000) mi=-1;
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}