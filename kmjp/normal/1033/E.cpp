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

int N;
vector<int> E[601];
int P[601];


int ask(vector<int> V) {
	static map<vector<int>,int> M;

	sort(ALL(V));
	if(V.size()<=1) return 0;
	if(M.count(V)) return M[V];
	
	cout<<"? "<<V.size()<<endl;
	FORR(v,V) cout<<(v+1)<<" ";
	cout<<endl;
	cout.flush();
	int ret;
	cin>>ret;
	return M[V]=ret;
}

int cross(vector<int> A,vector<int> B) {
	vector<int> C;
	FORR(x,A) C.push_back(x);
	FORR(x,B) C.push_back(x);
	return ask(C)-ask(A)-ask(B);
}

pair<int,int> dfs(vector<int> S,vector<int> T) {
	int i;
	if(S.size()==1) {
		if(T.size()==1) {
			return {S[0],T[0]};
		}
		else {
			vector<int> T2[2];
			FOR(i,T.size()) T2[i%2].push_back(T[i]);
			if(cross(S,T2[0])) return dfs(S,T2[0]);
			else return dfs(S,T2[1]);
		}
	}
	else {
		vector<int> S2[2];
		FOR(i,S.size()) S2[i%2].push_back(S[i]);
		if(cross(S2[0],T)) return dfs(S2[0],T);
		else return dfs(S2[1],T);
	}
}

void dfs2(int cur,int pre,int id) {
	P[cur]=id;
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,id+1);
}

void dfs3(int cur,int tar,vector<int>& T) {
	if(cur==tar) {
		cout<<"N "<<T.size()+1<<endl;
		FORR(t,T) cout<<(t+1)<<" ";
		cout<<(tar+1)<<endl;
		exit(0);
	}
	
	FORR(e,E[cur]) if(T.empty() || e!=T.back()) {
		T.push_back(cur);
		dfs3(e,tar,T);
		T.pop_back();
	}
}

void check(vector<int> S) {
	if(ask(S)==0) return;
	int i;
	vector<int> S2[2];
	FOR(i,S.size()) S2[i%2].push_back(S[i]);
	
	check(S2[0]);
	check(S2[1]);
	pair<int,int> p=dfs(S2[0],S2[1]);
	vector<int> T;
	dfs3(p.first,p.second,T);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> S,T;
	S.push_back(0);
	for(i=1;i<N;i++) T.push_back(i);
	
	while(T.size()) {
		pair<int,int> p=dfs(S,T);
		
		E[p.first].push_back(p.second);
		E[p.second].push_back(p.first);
		S.push_back(p.second);
		T.erase(find(ALL(T),p.second));
	}
	
	dfs2(0,0,0);
	S.clear();
	T.clear();
	FOR(i,N) {
		if(P[i]%2==0) S.push_back(i);
		else T.push_back(i);
	}
	
	check(S);
	check(T);
	
	
	cout<<"Y "<<S.size()<<endl;
	FORR(s,S) cout<<(s+1)<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	solve(); return 0;
}