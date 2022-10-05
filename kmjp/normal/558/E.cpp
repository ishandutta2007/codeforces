#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int L,Q;
set<pair<int,char> > S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>Q;
	cin>>s;
	char p='*';
	FOR(i,L) if(p!=s[i]) {
		p=s[i];
		S.insert({i,s[i]});
	}
	S.insert({L,'a'});
	
	while(Q--) {
		cin>>x>>y>>k;
		x--;y--;
		
		auto it=S.lower_bound({x,'a'});
		auto it2=S.lower_bound({y+1,'a'});
		if(it->first>x) it--;
		
		pair<int,char> ppre={-1,'*'}, ppost={-1,'*'};
		auto it3=it;
		int num[26]={};
		while(it3!=it2) {
			auto pre=it3++;
			int cnt=it3->first-pre->first;
			int n=0;
			if(pre->first<x) {
				cnt -= x-pre->first;
				ppre={pre->first,pre->second};
			}
			if(y+1<it3->first) {
				cnt -= it3->first - (y+1);
				ppost={y+1,pre->second};
			}
			
			num[pre->second-'a'] += cnt;
			S.erase(pre);
		}
		
		if(ppre.first>=0) S.insert(ppre);
		if(ppost.first>=0) S.insert(ppost);
		
		if(k==1) {
			FOR(i,26) if(num[i]) S.insert({x,'a'+i}), x += num[i];
		}
		else {
			for(i=25;i>=0;i--) if(num[i]) if(num[i]) S.insert({x,'a'+i}), x += num[i];
		}
	}
	
	auto it=S.begin();
	auto it2=it++;
	while(it!=S.end()) {
		FOR(i,it->first-it2->first) _P("%c",it2->second);
		it++;it2++;
	}
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}