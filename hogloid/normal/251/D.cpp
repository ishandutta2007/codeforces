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
int n;
lint a[100005];
int bits[70][100005];
int m;
int tmp[100005];
int pivot[70];

int ans[100005];
int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	
	REP(t,2) for(int i=61;i>=0;--i){
		int sum=0;
		REP(j,n){
			tmp[j]=(a[j]>>i&1);
			sum+=tmp[j];
		}
		tmp[n]=1;
		if(sum%2!=t) continue;
		
	 	REP(j,m) if(tmp[pivot[j]]) REP(k,n+1) tmp[k]^=bits[j][k];
		
		int p=0;
		while(p<n && tmp[p]==0) ++p;
		if(p<n){
			REP(j,n+1) bits[m][j]=tmp[j];
			pivot[m++]=p;
		}
	}

	for(int i=m-1;i>=0;--i){
		int p=pivot[i];
		ans[p]=bits[i][n];
		for(int j=i+1;j<m;++j) ans[p]^=(ans[pivot[j]]*bits[i][pivot[j]]);
	}
	REP(i,n) printf("%d ",ans[i]+1);
	putchar('\n');
		
	return 0;
}