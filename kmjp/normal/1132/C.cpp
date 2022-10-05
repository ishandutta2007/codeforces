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

int N,Q;
pair<int,int> P[5050];

int from[5050][3],to[5050][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>P[i].first>>P[i].second;
	}
	sort(P,P+Q);
	FOR(i,5050) FOR(j,3) from[i][j]=-1<<30;
	from[0][0]=0;
	
	FOR(i,Q) {
		int L=P[i].first,R=P[i].second;
		FOR(j,5050) {
			to[j][2]=max(from[j][2],from[j][1]);
			to[j][1]=from[j][0];
			to[j][0]=from[j][0];
		}
		FOR(j,5050) {
			if(j<L) {
				to[R][0]=max(to[R][0],from[j][0]+R-L+1);
				to[R][1]=max(to[R][1],from[j][1]+R-L+1);
				to[R][2]=max(to[R][2],from[j][2]+R-L+1);
			}
			else if(j<R) {
				to[R][0]=max(to[R][0],from[j][0]+R-j);
				to[R][1]=max(to[R][1],from[j][1]+R-j);
				to[R][2]=max(to[R][2],from[j][2]+R-j);
			}
		}
		swap(from,to);
	}
	
	int ma=0;
	FOR(j,N+1) ma=max(ma,from[j][2]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}