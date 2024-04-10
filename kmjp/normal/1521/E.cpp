#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,M,K;
pair<int,int> P[101010];

int A[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(k,T) {
		cin>>M>>K;
		FOR(i,K) {
			cin>>x;
			P[i]={-x,i+1};
		}
		sort(P,P+K);
		x=0;
		while(1) {
			int tot=x*x-(x/2)*(x/2);
			int ma=x*((x+1)/2);
			if(tot>=M&&ma>=-P[0].first) break;
			x++;
		}
		int N=x;
		vector<pair<int,int>> C[4];
		FOR(y,N) FOR(x,N) {
			A[y][x]=0;
			if(x%2==1&&y%2==0) C[0].push_back({y,x});
			else if(x%2==0&&y%2==0) C[1].push_back({y,x});
			else if(x%2==0&&y%2==1) C[2].push_back({y,x});
			
		}
		FOR(i,K) {
			FOR(x,-P[i].first) {
				y=0;
				if(C[1].size()) y=1;
				if(C[2].size()) y=2;
				assert(C[y].size());
				A[C[y].back().first][C[y].back().second]=P[i].second;
				C[y].pop_back();
			}
		}
		
		
		cout<<N<<endl;
		FOR(y,N) {
			FOR(x,N) cout<<A[y][x]<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}