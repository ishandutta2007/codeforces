#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
set<int> X;
multiset<int> D;

void add(int x) {
	if(X.empty()) {
		X.insert(x);
	}
	else {
		auto it=X.insert(x).first;
		if(it==X.begin()) {
			D.insert(*next(it)-*it);
		}
		else if(next(it)==X.end()) {
			D.insert(*it-*prev(it));
		}
		else {
			x=*next(it)-*prev(it);
			D.erase(D.find(x));
			D.insert(*next(it)-*it);
			D.insert(*it-*prev(it));
		}
	}
}

void del(int x) {
	if(X.size()==1) {
		X.erase(x);
	}
	else {
		auto it=X.find(x);
		if(it==X.begin()) {
			D.erase(D.find(*next(it)-x));
		}
		else if(next(it)==X.end()) {
			D.erase(D.find(x-*prev(it)));
		}
		else {
			D.erase(D.find(*next(it)-x));
			D.erase(D.find(x-*prev(it)));
			D.insert(*next(it)-*prev(it));
		}
		X.erase(x);
	}
	
}

void hoge() {
	if(X.size()<=2) {
		cout<<0<<endl;
	}
	else {
		ll tot=*prev(X.end())-*X.begin();
		ll ma=*prev(D.end());
		cout<<tot-ma<<endl;
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		add(x);
	}
	
	hoge();
	FOR(i,Q) {
		cin>>j>>x;
		if(j==0) del(x);
		else add(x);
		hoge();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}