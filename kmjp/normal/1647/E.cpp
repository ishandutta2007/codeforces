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

int N;
int P[101010][35];
int A[101010];
int B[101010];
int C[101010];
int go[101010];
vector<int> from[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i][0];
		P[i][0]--;
		C[P[i][0]]++;
	}
	int rem=0;
	FOR(i,N) if(C[i]>1) rem+=C[i]-1;
	int ma=0;
	MINUS(go);
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		if(A[i]<N) go[A[i]]=i;
		ma=max(ma,A[i]);
	}
	int step=(ma-(N-1))/rem;
	
	vector<int> to;
	FOR(i,N) to.push_back(i);
	FOR(i,30) {
		if(step&(1<<i)) {
			vector<int> to2;
			FOR(j,N) to2.push_back(P[to[j]][i]);
			swap(to,to2);
		}
		FOR(j,N) P[j][i+1]=P[P[j][i]][i];
	}
	FOR(j,N) from[to[j]].push_back(j);
	
	set<int> space;
	
	MINUS(B);
	FOR(i,N) {
		if(go[i]==-1) {
			x=*space.begin();
			B[x]=i+1;
			space.erase(space.begin());
		}
		else {
			int first=0;
			FORR(f,from[go[i]]) {
				if(first==0) {
					B[f]=i+1;
					first=1;
				}
				else {
					space.insert(f);
				}
			}
		}
	}
	FOR(i,N) cout<<B[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}