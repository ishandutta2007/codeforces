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
string S;


template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		int mat[26][26]={};
		vector<int> E[26];
		UF<26> uf;
		cin>>S;
		N=S.size();
		FORR(c,S) c-='a';
		int ng=0;
		FOR(i,N-1) mat[S[i]][S[i+1]]=mat[S[i+1]][S[i]]=1;
		FOR(i,26) {
			FOR(j,26) if(mat[i][j]) E[i].push_back(j);
		}
		int vis[26]={};
		string R;
		
		FOR(i,26) {
			if(E[i].size()>=3) {
				ng=1;
				break;
			}
			if(E[i].size()==2 || vis[i]) continue;
			
			int cur=i;
			while(1) {
				vis[cur]=1;
				R+='a'+cur;
				if(E[cur].size()==0) {
					break;
				}
				else if(E[cur].size()==1) {
					if(vis[E[cur][0]]) break;
					else cur=E[cur][0];
				}
				else {
					if(vis[E[cur][0]]) cur=E[cur][1];
					else cur=E[cur][0];
					if(vis[cur]==1) {
						ng=1;
						break;
					}
				}
			}
		}
		
		if(ng || R.size()!=26) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			cout<<R<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}