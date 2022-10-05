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

int T;
ll N;

map<int,int> enumpr(int n) {
	map<int,int> V;
	for(int i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

vector<int> enumdiv(int n) {
	vector<int> S;
	for(int i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		map<int,int> M=enumpr(N);
		vector<int> C=enumdiv(N);
		vector<int> V;
		
		if(M.size()==1) {
			V=C;
			V.erase(V.begin());
		}
		else {
			x=M.begin()->first;
			M.erase(M.begin());
			y=M.begin()->first;
			map<int,set<int>> Q;
			FORR(c,C) if(c>1) {
				i=c;
				while(i%x==0) i/=x;
				while(i%y==0) i/=y;
				Q[i].insert(c);
			}
			deque<int> D;
			D.push_back(x*y);
			for(i=x;N%i==0;i*=x) D.push_back(i);
			for(i=y;N%i==0;i*=y) D.push_front(i);
			FORR(d,D) Q[1].erase(d);
			
			
			int pre=1;
			FORR(q,Q) {
				if(q.first!=1) {
					i=D.back();
					D.push_back(i/pre*q.first);
					q.second.erase(D.back());
					i=D.front();
					D.push_front(i/pre*q.first);
					q.second.erase(D.front());
				}
				FORR(v,q.second) D.push_back(v);
				pre=q.first;
			}
			FORR(d,D) V.push_back(d);
			
			
			
		}
		
		
		
		
		int num=0;
		FOR(i,V.size()) if(__gcd(V[i],V[(i+1)%V.size()])==1) num++;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
		cout<<num<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}