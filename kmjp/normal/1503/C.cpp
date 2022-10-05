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
int A[101010],C[101010];
pair<int,int> P[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<pair<int,int>> H;
	set<int> lef;
	set<pair<int,int>> best;
	FOR(i,N) {
		cin>>A[i]>>C[i];
		H.insert({A[i],i});
	}
	
	int first=H.begin()->second;
	int cur=first;
	H.erase(H.begin());
	best.insert({A[cur]+C[cur],cur});
	vector<int> order;
	while(H.size()) {
		int cur=best.rbegin()->second;
		int num=best.rbegin()->first;
		order.push_back(cur);
		best.erase(*best.rbegin());
		
		int add=0;
		int better=0;
		while(H.size()&&H.begin()->first<=num) {
			x=H.begin()->second;
			H.erase(H.begin());
			best.insert({A[x]+C[x],x});
			if(A[x]+C[x]>num) better=1;
			add++;
		}
		if(better) continue;
		if(H.empty()) break;
		x=H.begin()->second;
		H.erase(H.begin());
		best.insert({A[x]+C[x],x});
	}
	
	FORR(b,best) H.insert({A[b.second],b.second});
	while(H.size()) {
		order.push_back(H.rbegin()->second);
		H.erase(*H.rbegin());
	}
	order.push_back(first);
	
	
	assert(order.size()==N+1);
	ll ret=0;
	FOR(i,N) {
		x=order[i];
		y=order[i+1];
		ret+=max(C[x],A[y]-A[x]);
	}
	
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}