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

int T;
int N;
ll A[202020];
vector<int> P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V;
		FOR(i,N) {
			cin>>A[i];
			V.push_back(A[i]);
			P[i].clear();
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		
		FOR(i,N) {
			x=lower_bound(ALL(V),A[i])-V.begin();
			P[x].push_back(i);
		}
		int ma=0;
		
		FOR(i,V.size()) {
			if(i&&P[i-1].back()<P[i][0]) continue;
			int num=P[i].size();
			int pre=P[i].back();
			
			if(i) {
				FORR(p,P[i-1]) if(p<P[i][0]) num++;
			}
			
			j=i+1;
			while(j<V.size()) {
				if(P[j][0]<pre) {
					FORR(p,P[j]) if(p>pre) num++;
					break;
				}
				pre=P[j].back();
				num+=P[j].size();
				j++;
			}
			ma=max(ma,num);
		}
		FOR(i,V.size()-1) {
			y=0;
			FOR(x,P[i].size()) {
				while(y<P[i+1].size() && P[i+1][y]<P[i][x]) y++;
				ma=max(ma,(int)(x+1+P[i+1].size()-y));
			}
		}
			
		
		cout<<N-ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}