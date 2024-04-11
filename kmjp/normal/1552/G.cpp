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
ll active[55],sum[55];
int newbit[55];
ll mask[55][55];

void dfs(ll cur,int i) {
	if(i==K) {
		ll shift=((~cur)>>1)&((1LL<<(N-1))-1);
		if(cur&shift) {
			cout<<"REJECTED"<<endl;
			exit(0);
		}
		return;
	}
	int cur_ones = __builtin_popcountll(cur&active[i]);
	cur &= ~active[i];
	for(int add=0;add<=newbit[i];add++) {
		dfs(cur | mask[i][cur_ones+add], i+1);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>x;
		vector<int> Q;
		FOR(j,x) {
			cin>>y;
			y--;
			Q.push_back(y);
			active[i] |= 1LL<<y;
		}
		reverse(ALL(Q));
		FOR(j,x) {
			mask[i][j+1]=mask[i][j] | (1LL<<Q[j]);
		}
		
		newbit[i]=__builtin_popcountll(active[i]&~sum[i]);
		sum[i+1]=sum[i] | active[i];
	}
	
	if(N==1) {
		cout<<"ACCEPTED"<<endl;
		return;
	}
	
	if(sum[K]!=(1LL<<N)-1) {
		cout<<"REJECTED"<<endl;
		return;
	}
	
	dfs(0,0);
	cout<<"ACCEPTED"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}