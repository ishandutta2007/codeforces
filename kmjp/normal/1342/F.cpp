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
int A[15];
int S[1<<15];
int from[16][16][1<<15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		int mask;
		FOR(mask,1<<N) {
			S[mask]=0;
			FOR(i,N) if(mask&(1<<i)) S[mask]+=A[i];
		}
		FOR(i,N+1) FOR(j,N+1) FOR(mask,1<<N) from[i][j][mask]=-1;
		from[0][0][0]=0;
		int ret=0;
		FOR(i,N+1) FOR(j,N+1) FOR(mask,1<<N) if(from[i][j][mask]>=0) {
			int cur;
			int pre=from[i][j][mask]&((1<<15)-1);
			int ma=mask | j<<16 | i<<21;
			//cout<<i<<" "<<j<<" "<<mask<<endl;
			if(mask==(1<<N)-1) ret=ma;
			if(i==0) cur=0;
			else cur=S[mask]-S[pre];
			
			for(x=j;x<N;x++) if((mask&(1<<x))==0) {
				int cand=((1<<N)-1)^mask^(1<<x);
				for(int sm=cand; sm>=0; sm--) {
					sm&=cand;
					if(S[sm|(1<<x)]>cur) {
						if(from[i+1][x+1][mask^(1<<x)^sm]==-1) {
							from[i+1][x+1][mask^(1<<x)^sm]=ma;
						}
						else {
							int pre=S[mask^(1<<x)^sm]-S[from[i+1][x+1][mask^(1<<x)^sm]&((1<<15)-1)];
							if(S[sm|(1<<x)]<pre) {
								from[i+1][x+1][mask^(1<<x)^sm]=ma;
							}
						}
					}
				}
			}
		}
		vector<pair<int,int>> R;
		while(ret) {
			i=(ret>>21);
			j=((ret>>16)%32)-1;
			mask=(ret&((1<<15)-1));
			ret=from[i][j+1][mask];
			int dif=mask^(ret&((1<<15)-1));
			FOR(x,N) if(x!=j&&(dif&(1<<x))) R.push_back({x,j});
		}
		vector<int> V;
		FOR(i,N) V.push_back(i);
		cout<<R.size()<<endl;
		FORR(r,R) {
			FOR(x,V.size()) if(V[x]==r.first) break;
			FOR(y,V.size()) if(V[y]==r.second) break;
			cout<<x+1<<" "<<y+1<<endl;
			V.erase(V.begin()+x);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}