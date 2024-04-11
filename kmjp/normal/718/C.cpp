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

ll mo=1000000007;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]) % mo;
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

template<class V,int NV> class SegTree_3 {
public:
	vector<V> mul;
	vector<V> sum;
	SegTree_3(){
		int i;
		mul.resize(NV*2);
		sum.resize(NV*2);
		FOR(i,NV*2) mul[i].v[0][0]=mul[i].v[1][1] = 1;
		FOR(i,NV*2) sum[i].v[0][0]=sum[i].v[1][1] = 1;
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		
		if(r<=x || y<=l) {
			Mat e={.v={{0,0},{0,0}}};
			return e;
		}
		if(x<=l && r<=y) return sum[k];
		
		auto m1=getval(x,y,l,(l+r)/2,k*2);
		auto m2=getval(x,y,(l+r)/2,r,k*2+1);
		Mat a;
		int i,j;
		FOR(i,2) FOR(j,2) {
			a.v[i][j] = m1.v[i][j]+m2.v[i][j];
			if(a.v[i][j]>=mo) a.v[i][j]-=mo;
		}
		a = mulmat(mul[k],a);
		
		
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			sum[k] = mulmat(v,sum[k]);
			mul[k] = mulmat(v,mul[k]);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			
			int i,j;
			FOR(i,2) FOR(j,2) {
				sum[k].v[i][j] = sum[k*2].v[i][j]+sum[k*2+1].v[i][j];
				if(sum[k].v[i][j]>=mo) sum[k].v[i][j]-=mo;
			}
			sum[k] = mulmat(mul[k],sum[k]);
		}
	}
};

SegTree_3<Mat,1<<18> seg;

Mat A[101010];

int N,M;

Mat getget(ll v) {
	Mat R={.v={{1,1},{1,0}}};
	return powmat(v,R);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		A[i]=getget(x-1);
		seg.update(i,i+1,A[i]);
	}
	
	while(M--) {
		cin>>i;
		if(i==1) {
			cin>>i>>j>>x;
			seg.update(i-1,j,getget(x));
		}
		else {
			cin>>i>>j;
			auto m=seg.getval(i-1,j);
			cout<<m.v[0][0]<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}