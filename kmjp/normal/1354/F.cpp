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
int N,K;
pair<int,int> P[101];

int A[76],B[76];
pair<ll,int> from[76][76];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i]>>B[i];
			P[i]={B[i],i};
		}
		sort(P,P+N);
		
		FOR(x,76) FOR(y,76) from[x][y]={-(1LL<<60),0};
		from[0][0]={0,0};
		FOR(x,N) {
			FOR(y,N+1) if(from[x][y].first>=0) {
				// take
				if(y<N) {
					ll v=from[x][y].first+A[P[x].second]+P[x].first*y;
					if(from[x+1][y+1].first<v) from[x+1][y+1]={v,1};
				}
				// not take
				{
					ll v=from[x][y].first+P[x].first*(K-1);
					if(from[x+1][y].first<v) from[x+1][y]={v,0};
				}
			}
		}
		
		vector<int> X,Y;
		x=N,y=K;
		while(x>0) {
			if(from[x][y].second==0) {
				Y.push_back(1+P[x-1].second);
			}
			else {
				X.push_back(1+P[x-1].second);
				y--;
			}
			x--;
		}
		reverse(ALL(X));
		cout<<Y.size()*2+X.size()<<endl;
		FOR(i,X.size()-1) cout<<X[i]<<" ";
		FOR(i,Y.size()) cout<<Y[i]<<" "<<-Y[i]<<" ";
		cout<<X.back()<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}