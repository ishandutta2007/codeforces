#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
double res[100][100][100];
double ans[100][100];
int who[100];
int shift;
pi range[100];
int zip[200],zn;
double lp[100],cp[100],rp[100];


void calc(int l,int r,double nxt[100][100],const double dp[100][100]){
	REP(i,n) REP(j,n) nxt[i][j]=0;
	
	double tmp[100][100];
	REP(i,n) REP(j,n) tmp[i][j]=dp[i][j];

	REPN(i,r,l){
		REP(j,n+1) REP(k,n+1) nxt[j][k]=0;

		REP(j,n) REP(k,n) if(tmp[j][k]>1e-20){
			double p=tmp[j][k];
			nxt[j][k]+=p*lp[i];
			nxt[j+1][k]+=p*cp[i];
			nxt[j][k+1]+=p*rp[i];
		}

		REP(j,n+1) REP(k,n+1) tmp[j][k]=nxt[j][k];
	}
}

		
void rec(int l,int r,double dp[100][100]){
	if(r-l==1){
		REP(i,n+1) REP(j,n+1){
			int rest=m-1-i-j;
			if(rest+shift>=0) res[who[l]][rest+shift][i]+=dp[i][j]*cp[l];
		}
		return;
	}
	double nxt[100][100];
	int md=(l+r)>>1;
	calc(md,r,nxt,dp);
	rec(l,md,nxt);

	calc(l,md,nxt,dp);
	rec(md,r,nxt);

}

void solve(int l,int r){
	m=shift=0;
	REP(i,n){
		if(range[i].fr<=l && r<=range[i].sc){
			double len=range[i].sc-range[i].fr;
			double L=min(1.0,max(0,l-range[i].fr)/len)
				,R=min(1.0,max(0,range[i].sc-r)/len),mid=1-L-R;
			lp[m]=L;
			cp[m]=mid;
			rp[m]=R;
			who[m]=i;
			++m;
		}else if(range[i].sc<=l) ++shift;
	}
	if(m==0) return;

	double dp[100][100]={0};

	dp[0][0]=1;
	rec(0,m,dp);
}


		
int main(){
	cin>>n;
	REP(i,n){
		cin>>range[i].fr>>range[i].sc;
		zip[i*2]=range[i].fr;
		zip[i*2+1]=range[i].sc;
	}
	sort(zip,zip+n*2);
	zn=unique(zip,zip+n*2)-zip;

	REP(i,zn-1) solve(zip[i],zip[i+1]);
	
	REP(i,n) REP(j,n) REP(k,n) REP(l,k+1) ans[i][j+l]+=res[i][j][k]/(k+1);

	REP(i,n) REP(j,n) printf("%.10f%c",ans[i][j],j==n-1?'\n':' ');

	return 0;
}