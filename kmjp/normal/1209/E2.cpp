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
int A[2020][2020];
int H,W;
int from[1<<12],to[1<<12],sum[1<<12];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>W>>H;
		FOR(y,W) FOR(x,H) cin>>A[x][y];
		vector<pair<int,int>> V;
		FOR(y,H) {
			i=*max_element(A[y],A[y]+W);
			V.push_back({i,y});
		}
		sort(ALL(V));
		reverse(ALL(V));
		if(V.size()>W) V.resize(W);
		
		ZERO(from);
		FORR(v,V) {
			ZERO(sum);
			int mask=0;
			FOR(mask,1<<W) {
				int s=0;
				FOR(i,W) if(mask&(1<<i)) s+=A[v.second][i];
				int cmask=mask;
				FOR(i,W) {
					sum[cmask]=max(sum[cmask],s);
					cmask=((cmask<<1) | (cmask>>(W-1))) & ((1<<W)-1);
				}
			}
			
			ZERO(to);
			FOR(mask,1<<W) {
				int cand=((1<<W)-1)^mask;
				for(int cm=cand; cm>=0; cm--) {
					cm&=cand;
					to[mask|cm]=max(to[mask|cm],from[mask]+sum[cm]);
				}
			}
			
			swap(from,to);
		}
		
		cout<<from[(1<<W)-1]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}