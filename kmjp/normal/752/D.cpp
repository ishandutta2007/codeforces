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

int K,N;
map<string,vector<int>> M;
vector<pair<int,int>> L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,K) {
		cin>>s>>x;
		M[s].push_back(x);
	}
	FORR(m,M) sort(ALL(m.second));
	
	ll ret=0;
	
	while(M.size()) {
		auto m=*M.begin();
		M.erase(M.begin());
		
		string a=m.first, b=a;
		reverse(ALL(b));
		
		if(a==b) {
			while(m.second.size()>=2 && m.second.back()>=0 && m.second[m.second.size()-2]>=0) {
				ret += m.second.back() + m.second[m.second.size()-2];
				m.second.pop_back();
				m.second.pop_back();
			}
			if(m.second.size() && m.second.back()>0) {
				int f=m.second.back();
				int s=max(0,f+((m.second.size()>=2)?m.second[m.second.size()-2]:-1<<30));
				L.push_back({f,s});
			}
		}
		else if(M.count(b)) {
			auto m2=M[b];
			M.erase(b);
			while(m.second.size() && m2.size() && m.second.back()+m2.back()>=0) {
				ret += m.second.back() + m2.back();
				m.second.pop_back();
				m2.pop_back();
			}
		}
	}
	
	ll a[2]={};
	FORR(r,L) {
		ll b[2]={0,0};
		// take single
		b[1]=max(b[1],a[0]+r.first);
		b[1]=max(b[1],a[1]+r.second);
		b[0]=max(b[0],a[0]+r.second);
		
		a[0]=b[0];
		a[1]=b[1];
	}
	
	cout<<ret+max(a[0],a[1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}