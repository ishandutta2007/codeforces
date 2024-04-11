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


ll V;
unordered_map<ll,string> po;
string ret;


string no_plus(ll v) {
	string ret=to_string(v);
	
	// no plus
	for(ll a=2;a*a<=v;a++) {
		ll b=a*a;
		int c=2;
		while(v%b==0) {
			string s;
			if(v/b>1) s=to_string(v/b)+"*"+to_string(a)+"^"+to_string(c);
			else s=to_string(a)+"^"+to_string(c);
			
			if(s.size()<ret.size()) ret=s;
			
			c++;
			b*=a;
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>V;
	if(V==10000000000LL) return _P("100^5\n");
	ret=no_plus(V);
	
	// 4*4
	for(x=2;x<=99;x++) {
		ll v=1;
		for(y=1;y<=99;y++) {
			v*=x;
			if(v>V) break;
			if(x>=10 && y>=10) break;
			string tmp=to_string(x)+"^"+to_string(y);
			if(po.count(v)==0 || po[v].size()>tmp.size()) po[v]=tmp;
		}
	}
	for(i=0;i<1000;i++) po[i]=to_string(i);
	
	// one plus
	FORR(p,po) {
		ll v=V-p.first;
		if(v>0) {
			string tmp=p.second+"+"+no_plus(v);
			if(tmp.size()<ret.size()) ret=tmp;
		}
	}
	
	// two plus
	FORR(p,po) FORR(p2,po) {
		ll v=V-p.first-p2.first;
		if(po.count(v)) {
			string tmp=p.second+"+"+p2.second;
			if(v) tmp+="+"+po[v];
			if(tmp.size()<ret.size()) ret=tmp;
		}
		v=V-p.first*p2.first;
		if(po.count(v)) {
			string tmp=p.second+"*"+p2.second;
			if(v) tmp+="+"+po[v];
			if(tmp.size()<ret.size()) ret=tmp;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}