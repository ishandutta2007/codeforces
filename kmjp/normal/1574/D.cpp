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
vector<ll> A[10];
set<vector<int>> invalid;
set<vector<int>> did;
int M;

int score(vector<int> B) {
	int ret=0;
	int i;
	FOR(i,N) {
		if(B[i]<0) return -1;
		ret+=A[i][B[i]];
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	vector<int> F;
	FOR(i,N) {
		scanf("%d",&k);
		FOR(j,k) {
			scanf("%d",&x);
			A[i].push_back(x);
		}
		F.push_back(k-1);
	}
	scanf("%d",&M);
	FOR(i,M) {
		vector<int> B(N);
		FOR(j,N) {
			scanf("%d",&B[j]);
			B[j]--;
		}
		invalid.insert(B);
	}
	x=score(F);
	priority_queue<pair<int,vector<int>>> Q;
	Q.push({x,F});
	did.insert(F);
	while(Q.size()) {
		int sc=Q.top().first;
		auto F=Q.top().second;
		Q.pop();
		
		if(invalid.count(F)==0) {
			FORR(c,F) cout<<c+1<<" ";
			cout<<endl;
			return;
		}
		FOR(i,N) {
			F[i]--;
			x=score(F);
			if(x>=0&&did.count(F)==0) {
				did.insert(F);
				Q.push({x,F});
			}
			
			F[i]++;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}