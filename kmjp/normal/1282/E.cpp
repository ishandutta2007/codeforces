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
int A[303030],B[303030],C[303030],didE[303030];
int didV[303030];
set<vector<int>> S[202020];
map<pair<int,int>,vector<int>> num;
vector<int> E[101010];

void dfs(int cur,vector<int>& P) {
	if(didV[cur]==0) {
		didV[cur]=1;
		P.push_back(cur+1);
		dfs(E[cur][0],P);
		dfs(E[cur][1],P);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			S[i].clear();
			didE[i]=didV[i]=0;
			E[i].clear();
		}
		num.clear();
		FOR(i,N-2) {
			cin>>A[i]>>B[i]>>C[i];
			A[i]--,B[i]--,C[i]--;
			if(A[i]>B[i]) swap(A[i],B[i]);
			if(B[i]>C[i]) swap(B[i],C[i]);
			if(A[i]>B[i]) swap(A[i],B[i]);
			num[{A[i],B[i]}].push_back(i);
			num[{B[i],C[i]}].push_back(i);
			num[{A[i],C[i]}].push_back(i);
		}
		FORR(m,num) if(m.second.size()==1) {
			E[m.first.first].push_back(m.first.second);
			E[m.first.second].push_back(m.first.first);
		}
		vector<int> P,Q;
		dfs(0,P);
		FOR(i,N-2) {
			x=(num[{A[i],B[i]}].size()==1)+(num[{B[i],C[i]}].size()==1)+(num[{A[i],C[i]}].size()==1);
			if(x>=2) {
				Q.push_back(i);
				didE[i]=1;
			}
		}
		
		i=0;
		while(i<Q.size()) {
			x=Q[i];
			i++;
			num[{A[x],B[x]}].erase(remove(num[{A[x],B[x]}].begin(),num[{A[x],B[x]}].end(),x),num[{A[x],B[x]}].end());
			num[{A[x],C[x]}].erase(remove(num[{A[x],C[x]}].begin(),num[{A[x],C[x]}].end(),x),num[{A[x],C[x]}].end());
			num[{B[x],C[x]}].erase(remove(num[{B[x],C[x]}].begin(),num[{B[x],C[x]}].end(),x),num[{B[x],C[x]}].end());
			if(num[{A[x],B[x]}].size()) {
				y=num[{A[x],B[x]}][0];
				j=(num[{A[y],B[y]}].size()==1)+(num[{B[y],C[y]}].size()==1)+(num[{A[y],C[y]}].size()==1);
				if(j>=2&&didE[y]==0) {
					Q.push_back(y);
					didE[y]=1;
				}
			}
			if(num[{A[x],C[x]}].size()) {
				y=num[{A[x],C[x]}][0];
				j=(num[{A[y],B[y]}].size()==1)+(num[{B[y],C[y]}].size()==1)+(num[{A[y],C[y]}].size()==1);
				if(j>=2&&didE[y]==0) {
					Q.push_back(y);
					didE[y]=1;
				}
			}
			if(num[{B[x],C[x]}].size()) {
				y=num[{B[x],C[x]}][0];
				j=(num[{A[y],B[y]}].size()==1)+(num[{B[y],C[y]}].size()==1)+(num[{A[y],C[y]}].size()==1);
				if(j>=2&&didE[y]==0) {
					Q.push_back(y);
					didE[y]=1;
				}
			}
			
		}
		
		
		FORR(p,P) cout<<p<<" ";
		cout<<endl;
		FORR(p,Q) cout<<p+1<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}