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
int N,A,B;
vector<int> E[101010],DS[101010];
int L,root;

int P[21][200005],D[200005],F[200005];


int dfs(int cur,int pre,int len) {
	D[cur]=len;
	int ma=0;
	int i;
	FOR(i,E[cur].size()) {
		if(E[cur][i]!=pre) {
			DS[cur][i]=dfs(E[cur][i],cur,len+1)+1;
			ma=max(ma,DS[cur][i]);
		}
	}
	return ma;
}

void dfs2(int cur,int pre,int p) {
	int i;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) DS[cur][i]=p+1;
	vector<int> D2=DS[cur];
	D2.push_back(0);
	sort(ALL(D2));
	reverse(ALL(D2));
	FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
		dfs2(E[cur][i],cur,D2[DS[cur][i]==D2[0]]);
	}
	
	int num=0;
	FORR(d,D2) if(d>=L) num++;
	if(num>=3) root=cur;
	
}
int dfs3(int cur,int pre,int len) {
	D[cur]=len;
	P[0][cur]=pre;
	F[cur]=cur;
	FORR(e,E[cur]) if(e!=pre) {
		int r=dfs3(e,cur,len+1);
		if(D[r]>D[F[cur]]) F[cur]=r;
		
	}
	return F[cur];
}

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		A--,B--;
		FOR(i,N) E[i].clear(),DS[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
			DS[x-1].push_back(0);
			DS[y-1].push_back(0);
		}
		dfs(A,A,0);
		L=D[B];
		root=-1;
		dfs2(A,A,0);
		if(root==-1) {
			cout<<"NO"<<endl;
			continue;
		
		}
		dfs3(root,root,0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		FOR(i,N) {
			if(abs(D[A]-D[B])>=L) break;
			
			int lc=lca(A,B);
			A=F[A];
			int dif=D[A]-D[lc];
			if(dif>=L) {
				B=root;
				break;
			}
			dif=L-dif;
			assert(D[B]-D[lc]>=dif);
			B=getpar(B,D[B]-(D[lc]+dif));
			
			
			
			swap(A,B);
		}
		
		
		if(abs(D[A]-D[B])>=L) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}