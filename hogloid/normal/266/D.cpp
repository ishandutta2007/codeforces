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
int g[205][205],dst[205][205];
pair<pi,int> es[40005];
double mini[40005];
double Ltall[405],Rtall[405];
double zip[405];
double answer=1e10;
void prep(){
	REP(i,m){
		pair<pi,int>& e=es[i];
		int n2=n;
		REP(k,n){
			int left=dst[k][e.fr.fr],right=dst[k][e.fr.sc];
			double farest=(right+e.sc+left)/2.0,p=farest-left;//from left
			zip[k]=p;
		}
		zip[n2++]=0;zip[n2++]=e.sc;

		sort(zip,zip+n2);
		REP(i,n2) Ltall[i]=Rtall[i]=-1e10;
		REP(k,n){
			int left=dst[k][e.fr.fr],right=dst[k][e.fr.sc];
			double farest=(right+e.sc+left)/2.0,p=farest-left;//from left

			int lb=lower_bound(zip,zip+n2,p-1e-9)-zip;

			Ltall[lb]=max(farest,Ltall[lb]);
			Rtall[lb]=max(farest,Rtall[lb]);
		}
		for(int k=n2-1;k>=1;--k){
			Ltall[k-1]=max(Ltall[k-1],Ltall[k]-(zip[k]-zip[k-1]));
		}
		REP(k,n2-1) Rtall[k+1]=max(Rtall[k+1],Rtall[k]-(zip[k+1]-zip[k]));
		

		REP(k,n2-1){
			double l1=Ltall[k+1]-(zip[k+1]-zip[k]),l2=Ltall[k+1],
				r1=Rtall[k],r2=Rtall[k]-(zip[k+1]-zip[k]);
			if(l2>r2 && r1>l1){
				double dif=l2-r2;
				dif/=2;
				answer=min(answer,l2-dif);
			}else if(l2<=r2) answer=min(answer,r2);
			else answer=min(answer,l1);
		}
	}
}
	
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n) dst[i][j]=g[i][j]=INF;
	REP(i,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		g[a][b]=g[b][a]=dst[a][b]=dst[b][a]=c;
		es[i]=mp(mp(a,b),c);
	}
	REP(i,n) dst[i][i]=0;
	REP(i,n) REP(j,n) REP(k,n) dst[j][k]=min(dst[j][i]+dst[i][k],dst[j][k]);
	
	prep();
	printf("%.10f\n",answer);

	return 0;
}