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

int N,Q;
int C[1515][1515];
int A[1515][1515];
int ret[1515];
vector<pair<int,int>> R[1515][1515],D[1515][1515],X[1515][1515];
int cnt[1515*1515];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(y,N) FOR(x,N) scanf("%d",&C[y][x]);
	for(y=N-1;y>=0;y--) {
		for(x=N-1;x>=0;x--) {
			vector<pair<int,int>>& RR=R[y][x];
			vector<pair<int,int>>& DD=D[y][x];
			vector<pair<int,int>>& XX=X[y+1][x+1];
			vector<pair<int,int>> V;
			swap(RR,R[y][x+1]);
			swap(DD,D[y+1][x]);
			
			FOR(i,RR.size()) if(C[RR[i].first][RR[i].second]==C[y][x]) {
				RR.erase(RR.begin()+i);
				break;
			}
			RR.insert(RR.begin(),{y,x});
			if(RR.size()>Q+1) RR.resize(Q+1);
			FOR(i,DD.size()) if(C[DD[i].first][DD[i].second]==C[y][x]) {
				DD.erase(DD.begin()+i);
				break;
			}
			DD.insert(DD.begin(),{y,x});
			if(DD.size()>Q+1) DD.resize(Q+1);
			
			
			int a=0,b=0,c=0;
			while(a<RR.size()||b<DD.size()||c<XX.size()) {
				if(V.size()==Q+1) break;
				int da=(a==RR.size())?5000:max(RR[a].first-y,RR[a].second-x);
				int db=(b==DD.size())?5000:max(DD[b].first-y,DD[b].second-x);
				int dc=(c==XX.size())?5000:max(XX[c].first-y,XX[c].second-x);
				if(da<=min(db,dc)) {
					if(cnt[C[RR[a].first][RR[a].second]]==0) {
						V.push_back(RR[a]);
						cnt[C[RR[a].first][RR[a].second]]++;
					}
					a++;
				}
				else if(db<=min(da,dc)) {
					if(cnt[C[DD[b].first][DD[b].second]]==0) {
						V.push_back(DD[b]);
						cnt[C[DD[b].first][DD[b].second]]++;
					}
					b++;
				}
				else {
					if(cnt[C[XX[c].first][XX[c].second]]==0) {
						V.push_back(XX[c]);
						cnt[C[XX[c].first][XX[c].second]]++;
					}
					c++;
				}
			}
			X[y+1][x+1].clear();
			FORR(v,V) {
				cnt[C[v.first][v.second]]--;
				assert(cnt[C[v.first][v.second]]==0);
			}
			
			
			if(V.size()>=Q+1) {
				V.resize(Q+1);
				r=max(V.back().first-y,V.back().second-x);
				r=min({r,N-y,N-x});
			}
			else {
				r=min(N-y,N-x);
			}
			ret[r]++;
			X[y][x]=V;
			
		}
	}
	
	for(i=N;i>=1;i--) ret[i]+=ret[i+1];
	for(i=1;i<=N;i++) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}