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

int N;
string S[61010];

int M[5][10100];
set<ll> did;

ll get(string v) {
	ll p=1;
	int i;
	FOR(i,v.size()) p*=10;
	ll a=atoi(v.c_str());
	FOR(i,1010) {
		if(v[0]=='0' && i==0) continue;
		ll v2=a+i*p;
		if(did.count(v2)==0) return v2;
	}
	assert(0);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1989;i<=123456;i++) {
		x=i;
		int p=1;
		int v=0;
		for(y=1;i>=p;y++) {
			if(y>4) break;
			v+=i/p%10*p;
			if(M[y][v]==0) {
				M[y][v]=i;
				break;
			}
			p*=10;
		}
	}
	
	FOR(i,N) {
		cin>>s;
		s=s.substr(4);
		y=atoi(s.c_str());
		if(s.size()<=4) {
			cout<<M[s.size()][atoi(s.c_str())]<<endl;
		}
		else {
			did.clear();
			for(x=1;x<=s.size();x++) {
				if(x<=4) {
					did.insert(M[x][atoi(s.substr(s.size()-x).c_str())]);
				}
				else {
					did.insert(get(s.substr(s.size()-x)));
				}
			}
			cout<<*did.rbegin()<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}