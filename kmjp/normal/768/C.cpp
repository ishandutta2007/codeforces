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

int N,K,X;
int from[1050],to[1050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X;
	FOR(i,N) {
		cin>>x;
		from[x]++;
	}
	
	FOR(j,K) {
		ZERO(to);
		int cnt=0;
		FOR(i,1024) {
			int dodo,donot;
			
			if(from[i]%2==0) {
				dodo=donot=from[i]/2;
			}
			else {
				if(cnt%2==0) {
					dodo=from[i]/2+1;
					donot=from[i]/2;
				}
				else {
					dodo=from[i]/2;
					donot=from[i]/2+1;
				}
			}
			to[i^X] += dodo;
			to[i] += donot;
			cnt+=from[i];
		}
		
		swap(from,to);
	}
	vector<int> V;
	FOR(i,1024) FOR(j,from[i]) V.push_back(i);
	cout<<V.back()<<" "<<V[0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}