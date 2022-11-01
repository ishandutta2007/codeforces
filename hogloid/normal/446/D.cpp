
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif


template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,m;
lint k;
int g[505][505];
int mark[505];

vector<double> mat[505];
int ps[505],deg[505];
double prob[70][505][505];

double ans[505][505];
double tmp[505][505];

int cnt;
void merge(double a[505][505],double b[505][505]){
	REP(i,cnt) REP(j,cnt){
		tmp[i][j]=0;
		REP(k,cnt) tmp[i][j]+=a[i][k]*b[k][j];
	}

	memcpy(a,tmp,sizeof(tmp));
}

int main(){
	cin>>n>>m>>k;
	--k;
	REP(i,n) cin>>mark[i];
	REP(i,m){
		int a,b;cin>>a>>b;
		--a;--b;
		g[a][b]++;
		g[b][a]++;
		deg[a]++;
		deg[b]++;
	}
	cnt=0;
	REP(i,n) if(i==0 || mark[i]) ps[cnt++]=i;

	
	REP(i,n) mat[i].resize(n*2);

	REP(i,n){
		if(!mark[i]){
			REP(j,n) mat[i][j]=1.0*g[i][j]/deg[i];
		}else{
			mat[i][n+i]=1;
		}
		mat[i][i]=-1;
	}

	REP(i,n){
		double mx=-1;
		int ind;
		for(int j=i;j<n;++j) if(abs(mat[j][i])>mx){
			mx=abs(mat[j][i]);
			ind=j;
		}

		swap(mat[ind],mat[i]);
		
		double prev=mat[i][i];
		REP(j,n*2) mat[i][j]/=prev;

		REP(j,n) if(j!=i && mat[j][i]!=0){
			REP(k,n*2) if(i!=k) mat[j][k]-=mat[i][k]*mat[j][i];
			mat[j][i]=0;
		}
	}

	REP(i,cnt) REP(j,cnt){

		int a=ps[i],b=ps[j];
		if(mark[a]){
			prob[0][i][j]=0;
			REP(k,n){
				prob[0][i][j]-=mat[k][n+b]*g[a][k]/deg[a];
			}
		}else{
			prob[0][i][j]=-mat[a][n+b];
		}
	}

	REP(i,61){
		memcpy(prob[i+1],prob[i],sizeof(prob[i]));
		merge(prob[i+1],prob[i]);
	}
	REP(i,cnt) debug(prob[1][i],prob[1][i]+cnt);
	
	
	ans[0][0]=1;

	
	REP(i,61) if(k>>i&1) merge(ans,prob[i]);

	double res=ans[0][cnt-1];

	REP(i,cnt) debug(ans[i],ans[i]+cnt);

	printf("%.10f\n",res);



	return 0;
}