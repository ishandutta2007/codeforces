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
int A[101010];
string S;
int mask;

int pat[1<<20];
void out(vector<int> V) {
	if(V.size()==1) {
		cout<<V[0];
		return;
	}
	int i,j;
	int pre=0,suf=0;
	while(V.size()&&V.back()==1) suf++, V.pop_back();
	if(V.empty()) {
		FOR(i,suf) {
			if(i) cout<<"+";
			cout<<1;
		}
		return;
	}
	reverse(ALL(V));
	while(V.size()&&V.back()==1) pre++, V.pop_back();
	reverse(ALL(V));
	
	ll mul=1;
	FORR(v,V) {
		mul*=v;
		if(mul>10*V.size()) {
			FOR(i,pre) cout<<"1+";
			FOR(i,V.size()) {
				if(i) cout<<"*";
				cout<<V[i];
			}
			FOR(i,suf) cout<<"+1";
			return;
		}
	}
	
	vector<pair<int,vector<int>>> W;
	FORR(v,V) {
		if(W.empty()) {
			W.push_back({1,vector<int>()});
		}
		else if(v==1) {
			if(W.back().second[0]!=1) W.push_back({1,vector<int>()});
		}
		else {
			if(W.back().second[0]==1) W.push_back({1,vector<int>()});;
		}
		W.back().first*=v;
		W.back().second.push_back(v);
	}
	/*
	FORR(w,W) {
		cout<<w.first<<" ";
		FORR(v,w.second) cout<<v;
		cout<<endl;
	}
	*/
	assert(W.size()%2==1);
	int N=(W.size()-1)/2;
	int mask;
	FOR(mask,1<<N) {
		int sum=0;
		int cur=W[0].first;
		FOR(i,N) {
			if(mask&(1<<i)) {
				cur*=W[(i+1)*2].first;
			}
			else {
				sum+=cur+W[i*2+1].second.size();
				cur=W[(i+1)*2].first;
			}
		}
		pat[mask]=sum+cur;
	}
	
	mask=max_element(pat,pat+(1<<N))-pat;
	
	FOR(i,pre) cout<<"1+";
	
	FOR(i,W[0].second.size()) {
		if(i) cout<<"*";
		cout<<W[0].second[i];
	}
	FOR(i,N) {
		if(mask&(1<<i)) {
			FORR(v,W[i*2+1].second) cout<<"*"<<v;
			FORR(v,W[i*2+2].second) cout<<"*"<<v;
		}
		else {
			FORR(v,W[i*2+1].second) cout<<"+1";
			cout<<"+";
			FOR(j,W[i*2+2].second.size()) {
				if(j) cout<<"*";
				cout<<W[i*2+2].second[j];
			}
		}
	}
	
	FOR(i,suf) cout<<"+1";
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>S;
	FORR(c,S) {
		if(c=='+') mask|=1;
		if(c=='*') mask|=2;
		if(c=='-') mask|=4;
	}
	
	if(mask==1||mask==5) {
		cout<<A[0];
		FOR(i,N-1) cout<<"+"<<A[i+1];
		cout<<endl;
		return;
	}
	if(mask==2) {
		cout<<A[0];
		FOR(i,N-1) cout<<"*"<<A[i+1];
		cout<<endl;
		return;
	}
	if(mask==4) {
		cout<<A[0];
		FOR(i,N-1) cout<<"-"<<A[i+1];
		cout<<endl;
		return;
	}
	if(mask==6) {
		cout<<A[0];
		FOR(i,N-1) {
			if(A[i+1]==0) cout<<"-"<<A[i+1];
			else cout<<"*"<<A[i+1];
		}
		cout<<endl;
		return;
	}
	
	vector<vector<int>> V(1),W;
	FOR(i,N) {
		if(A[i]==0) {
			V.push_back(vector<int>());
			V.back().push_back(0);
			V.push_back(vector<int>());
		}
		else {
			V.back().push_back(A[i]);
		}
	}
	FORR(v,V) if(v.size()) W.push_back(v);
	
	FOR(i,W.size()) {
		if(i) cout<<"+";
		out(W[i]);
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}