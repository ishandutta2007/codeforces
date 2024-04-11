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

int N,Q;
int A[202020];
set<pair<int,int>> S;

void add(int v) {
	auto it=S.lower_bound({v+1,0});
	auto p=*prev(it);
	if(v<p.first+p.second) {
		S.erase(p);
		if(v-p.first) {
			S.insert({p.first,v-p.first});
		}
		add(p.first+p.second);
	}
	else if(v==p.first+p.second) {
		if(it->first==v+1) {
			auto q=p;
			q.second=it->first+it->second-q.first;
			S.erase(it);
			S.erase(p);
			S.insert(q);
		}
		else {
			S.erase(p);
			p.second++;
			S.insert(p);
		}
	}
	else if(it->first==v+1) {
		auto p=*it;
		S.erase(it);
		p.first--;
		p.second++;
		S.insert(p);
	}
	else {
		S.insert({v,1});
	}
}

void del(int v) {
	auto it=S.lower_bound({v+1,0});
	auto p=*prev(it);
	if(v<p.first+p.second) {
		pair<int,int> q={v+1,p.first+p.second-(v+1)};
		p.second=v-p.first;
		S.erase(prev(it));
		if(p.second) S.insert(p);
		if(q.second) S.insert(q);
	}
	else {
		p=*it;
		auto q=*prev(it);
		S.erase(p);
		if(p.second>1) S.insert({p.first+1,p.second-1});
		
		if(q.first+q.second==v) {
			S.erase(q);
			q.second=p.first-q.first;
			S.insert(q);
		}
		else {
			S.insert({v,p.first-v});
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	S.insert({0,1});
	S.insert({1<<30,1});
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		add(A[i]);
	}
	while(Q--) {
		cin>>i>>j;
		i--;
		del(A[i]);
		A[i]=j;
		add(A[i]);
		auto it=S.end();
		it--;
		it--;
		cout<<it->first+it->second-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}