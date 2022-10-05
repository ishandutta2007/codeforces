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


int T,N,M;
int A[303],B[303],C[303];
int D[303][303];

const int MAT=2556;
ll mo=3;
ll ma[5000][MAT],V[MAT],R[MAT];
ll rev(ll a, ll n = mo-2) {
	return a;
}

int Gauss(int n,int m,ll mat_[5000][MAT],ll v_[MAT],ll r[MAT]) { //mn
	int i,j,k;
	static ll mat[5000][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	int cur=0;

	FOR(i,m) {
		r[i]=0;
		for(j=cur;j<n;j++) if(mat[j][i]) break;
		if(j>=n) continue;
		FOR(k,m) swap(mat[cur][k],mat[j][k]);
		swap(v[cur],v[j]);
		
		(v[cur]*=rev(mat[cur][i]))%=mo;
		FOR(k,i) assert(mat[cur][k]==0);
		for(k=m-1;k>=i;k--) (mat[cur][k]*=rev(mat[cur][i]))%=mo;
		FOR(j,n) if(j!=cur&&mat[j][i]) {
			v[j]=((v[j]-v[cur]*mat[j][i]%mo)+mo)%mo;
			for(k=m-1;k>=i;k--) mat[j][k]=((mat[j][k]-mat[cur][k]*mat[j][i]%mo)+mo)%mo;
		}
		cur++;
	}
	
	FOR(i,n) {
		
		FOR(j,m) if(mat[i][j]) break;

		if(j<m) r[j]=v[i];
		else if(v[i]) {
			return -1;
		}
	}
	return cur;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		MINUS(D);
		ZERO(ma);
		ZERO(V);
		ZERO(R);
		int cur=0;
		
		FOR(i,M) {
			cin>>A[i]>>B[i]>>C[i];
			A[i]--,B[i]--;
			D[A[i]][B[i]]=D[B[i]][A[i]]=i;
			
			if(C[i]>=0) {
				ma[cur][i]=1;
				V[cur]=C[i]-1;
				cur++;
			}
		}
		FOR(k,N) FOR(y,k) FOR(x,y) if(D[x][y]>=0&&D[x][k]>=0&&D[y][k]>=0) {
			ma[cur][D[x][y]]=ma[cur][D[y][k]]=ma[cur][D[x][k]]=1;
			V[cur]=0;
			cur++;
		}
		x=Gauss(cur,M,ma,V,R);
		if(x==-1) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,M) cout<<R[i]+1<<" ";
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