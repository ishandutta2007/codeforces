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
vector<int> E[200005];
int P[21][200005],D[200005];
int L[200005],R[200005],eid;
int K,M,RR;

ll from[303];
ll to[303];
ll mo=1000000007;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void dfs(int cur) {
	L[cur]=eid++;
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
	R[cur]=eid;
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

pair<int,int> lcadist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return make_pair((aa==bb)?aa:P[0][aa], D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]]);
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
	while(Q--) {
		cin>>K>>M>>RR;
		RR--;
		vector<vector<int>> V;
		FOR(i,K) {
			cin>>r;
			r--;
			auto p=lcadist(RR,r);
			V.push_back({p.second,p.first,r});
		}
		
		ZERO(from);
		from[0]=1;
		sort(ALL(V));
		FORR(v,V) {
			int cur=v[2];
			int p=bt(L[cur]);
			ZERO(to);
			FOR(i,M+1) {
				if(i>=p) (to[i]+=from[i]*(i-p))%=mo;
				(to[i+1]+=from[i])%=mo;
			}
			if(cur==RR) {
				bt.add(0,1);
			}
			else if(cur==v[1]) {
				bt.add(0,1);
				p=getpar(RR,D[RR]-D[cur]-1);
				bt.add(L[p],-1);
				bt.add(R[p],1);
			}
			else {
				bt.add(L[cur],1);
				bt.add(R[cur],-1);
			}
			swap(from,to);
		}
		ll ret=0;
		FOR(i,M+1) ret+=from[i];
		cout<<(ret%mo)<<endl;
		FORR(v,V) {
			int cur=v[2];
			if(cur==RR) {
				bt.add(0,-1);
			}
			else if(cur==v[1]) {
				int p=getpar(RR,D[RR]-D[cur]-1);
				bt.add(0,-1);
				bt.add(L[p],+1);
				bt.add(R[p],-1);
			}
			else {
				bt.add(L[cur],-1);
				bt.add(R[cur],1);
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}