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

int L;
string S;

ll getval(vector<ll> v,vector<int> op) {
	int i;
	vector<ll> v2;
	v2.push_back(v[0]);
	FOR(i,v.size()-1) {
		if(op[i]==0) v2.push_back(v[i+1]);
		else v2.back()*=v[i+1];
	}
	
	ll ret=0;
	FORR(r,v2) ret+=r;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	
	vector<int> cand;
	for(i=0;i<L;i+=2) if(i==0 || i==L-1 || (i>0 && S[i-1]=='*')||(i<L-1&&S[i+1]=='*')) cand.push_back(i/2);
	
	ll ma=0;
	FOR(y,cand.size()) FOR(x,y+1) {
		vector<ll> v[3];
		vector<int> op[3];
		FOR(i,L) {
			if(i<cand[x]*2) j=0;
			else if(i<=cand[y]*2) j=1;
			else j=2;
			
			if(i%2) op[j].push_back(S[i]=='*');
			else v[j].push_back(S[i]-'0');
		}
		v[0].push_back(getval(v[1],op[1]));
		copy(v[2].begin(),v[2].end(),back_inserter(v[0]));
		copy(op[2].begin(),op[2].end(),back_inserter(op[0]));
		
		ma=max(ma,getval(v[0],op[0]));
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}