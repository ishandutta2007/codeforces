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

int N,M,K;
string A[101010];
string B[101010];
int C[101010];
int tar[26][26][26][26];
vector<int> TB[101010];
int id[27][27][27][27];
int in[101010];
vector<int> ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(tar);
	MINUS(id);
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i];
		A[i]+="aaaa";
		A[i]=A[i].substr(0,4);
		FORR(c,A[i]) {
			if(c=='_') c=26;
			else c-='a';
		}
		id[A[i][0]][A[i][1]][A[i][2]][A[i][3]]=i;
	}
	int mask;
	FOR(i,M) {
		cin>>B[i]>>C[i];
		C[i]--;
		B[i]+="aaaa";
		B[i]=B[i].substr(0,4);
		FORR(c,B[i]) c-='a';
		FOR(j,4) if(A[C[i]][j]!=26&&A[C[i]][j]!=B[i][j]) return _P("NO\n");
		if(tar[B[i][0]][B[i][1]][B[i][2]][B[i][3]]==-1) tar[B[i][0]][B[i][1]][B[i][2]][B[i][3]]=C[i];
		if(tar[B[i][0]][B[i][1]][B[i][2]][B[i][3]]!=C[i]) return _P("NO\n");
		FOR(mask,16) {
			int D[4];
			FOR(j,4) {
				if(mask&(1<<j)) D[j]=26;
				else D[j]=B[i][j];
			}
			x=id[D[0]][D[1]][D[2]][D[3]];
			if(x>=0&&x!=C[i]) {
				in[x]++;
				TB[C[i]].push_back(x);
			}
		}
	}
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		ret.push_back(cur+1);
		FORR(r,TB[cur]) if(--in[r]==0) Q.push(r);
	}
	if(ret.size()==N) {
		cout<<"YES"<<endl;
		FORR(r,ret) cout<<r<<" ";
		cout<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}