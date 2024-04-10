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

int T,N;
int E[101][101];

int ask(int a,int b) {
	int x;
	cout<<"1 "<<a<<" "<<b<<endl;
	cin>>x;
	return x;
}

int ask2(int a,vector<int> b) {
	cout<<"2 "<<a<<" "<<b.size();
	sort(ALL(b));
	FORR(c,b) cout<<" "<<c;
	cout<<endl;
	cin>>a;
	return a;
	
}

vector<int> merge(vector<int> A,vector<int> B) {
	vector<int> R;
	reverse(ALL(A));
	reverse(ALL(B));
	while(A.size()&&B.size()) {
		if(ask(A.back(),B.back())) {
			R.push_back(A.back());
			A.pop_back();
		}
		else {
			R.push_back(B.back());
			B.pop_back();
		}
	}
	while(A.size()) R.push_back(A.back()), A.pop_back();
	while(B.size()) R.push_back(B.back()), B.pop_back();
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		queue<vector<int>> V;
		FOR(i,N) V.push({i});
		while(V.size()>=2) {
			auto a=V.front();
			V.pop();
			auto b=V.front();
			V.pop();
			
			V.push(merge(a,b));
		}
		vector<int> W=V.front();
		
		ZERO(E);
		int cur=N-1;
		for(i=N-1;i>=0;i--) {
			cur=min(cur,i);
			while(cur) {
				vector<int> C;
				FOR(j,cur) C.push_back(W[j]);
				if(ask2(W[i],C)==0) break;
				cur--;
			}
			for(j=cur;j<N;j++) E[W[i]][W[j]]=1;
		}
		FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]|=E[x][k]&E[k][y];
		
		cout<<3<<endl;
		FOR(y,N) {
			FOR(x,N) cout<<E[y][x];
			cout<<endl;
		}
		cin>>x;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}