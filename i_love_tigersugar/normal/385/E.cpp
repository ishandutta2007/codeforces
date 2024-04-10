#include<cstdio>
#include<cstring>
#include<iostream>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const int matmul[][6]={{2,1,1,1,0,0},{1,2,1,1,0,0},{1,0,1,0,0,0},
						{0,1,0,1,0,0},{1,1,1,1,1,0},{2,2,2,2,1,1}};
ll N,sx,sy,dx,dy,t;
struct matrix {
	int m,n;
	ll d[13][13];
	matrix() {
		m=0;n=0;
		memset(d,0,sizeof d);
	}
	matrix(int m,int n) {
		this->m=m;
		this->n=n;
		memset(d,0,sizeof d);
	}
	matrix operator * (const matrix &a) const {
		int x=m;
		int y=n;
		int z=a.n;
		matrix res=matrix(x,z);
		REP(i,x) REP(j,z) REP(k,y) res.d[i][j]=(res.d[i][j]+d[i][k]*a.d[k][j])%N;
		return (res);
	}
	matrix operator ^ (ll k) const {
		matrix res=matrix(m,n);
		matrix mul=(*this);
		REP(i,m) res.d[i][i]=1;
		while (k>0) {
			if (k%2==1) res=res*mul;
			mul=mul*mul;
			k=k>>1;
		}
		return (res);
	}
	void print(void) const {
		REP(i,m) {
			REP(j,n) cout << d[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
};
matrix fst,mul;
void process(void) {
	cin >> N >> sx >> sy >> dx >> dy >> t;
	if (N==1) {
		cout << "1 1";
		return;
	}
	fst=matrix(1,6);
	mul=matrix(6,6);
	REP(i,6) REP(j,6) mul.d[i][j]=matmul[i][j]%N;
	fst.d[0][0]=sx-1;
	fst.d[0][1]=sy-1;
	fst.d[0][2]=(dx%N+N)%N;
	fst.d[0][3]=(dy%N+N)%N;
	fst.d[0][4]=0;
	fst.d[0][5]=1;
	/*REP(i,t) {
		fst=fst*mul;
		fst.print();
	}*/
	fst=fst*(mul^t);
	cout << fst.d[0][0]+1 << " " << fst.d[0][1]+1;
}
int main(void) {
	process();
	return 0;
}