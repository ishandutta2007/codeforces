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

ll N,L,V1,V2,K;

const int MAT=2;
int Gauss(int n,double mat_[MAT][MAT],double v_[MAT],double r[MAT]) {
	int i,j,k;
	double mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return -1;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[k]);
		}
		v[i]/=mat[i][i];
		for(k=n-1;k>=i;k--) mat[i][k]/=mat[i][i];
		for(j=i+1;j<n;j++) {
			v[j]-=v[i]*mat[j][i];
			for(k=n-1;k>=i;k--) mat[j][k]-=mat[i][k]*mat[j][i];
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]-=mat[i][j]*v[j],mat[i][j]=0;
		r[i]=v[i];
	}
	return 0;
}

double mat[2][2];
double V[2];
double R[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>V1>>V2>>K;
	ll step=(N+K-1)/K;
	
	if(step==1) return _P("%.12lf\n",L*1.0/V2);
	
	mat[0][0]=2*step;
	mat[0][1]=-V2;
	V[0]=L;
	mat[1][0]=1.0/V2-1.0/V1;
	mat[1][1]=-1;
	V[1]=-L*1.0/V1;
	
	Gauss(2,mat,V,R);
	
	_P("%.12lf\n",R[1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}