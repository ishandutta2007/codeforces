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
int L[2005],R[2005];
int sect[2005][2005];

int rank[2005],bord[2005],able[2005];//...bord[i] ]
int sum[2005];
bool check(int len){
	REP(i,n){
		rank[i]=-1;
		bord[i]=n-1;
		able[i]=1;
	}
	
	int cnt=0;
	dump(len);
	while(1){
		int rmin=-1;
		REP(i,n) if(able[i]){
			if(rmin==-1 || R[rmin]>R[i]) rmin=i;
		}
		rank[rmin]=bord[rmin]=cnt++;
		if(cnt==n) return true;

		REP(i,n) if(sect[rmin][i]) bord[i]=min(bord[i],rank[rmin]+len);
		memset(sum,0,sizeof(sum));
		REP(i,n) sum[bord[i]]++;
		REP(i,n) sum[i+1]+=sum[i];


		REP(i,n) if(sum[i]>i+1) return false;
		
		int from;
		REPN(i,n,rank[rmin]+1) if(sum[i]==i+1){
			from=i;
			break;
		}
		REP(i,n) able[i]=(rank[i]==-1 && bord[i]<=from);
	}
}

int res[2005];
int main(){
	scanf("%d",&n);
	REP(i,n) cin>>L[i]>>R[i];

	REP(i,n) REP(j,n) sect[i][j]=(L[j]<=R[i] && L[i]<=R[j]);

	int lb=-1,ub=n;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(check(md)) ub=md;
		else lb=md;
	}

	check(ub);
	dump(ub);
	debug(rank,rank+n);
	REP(i,n) res[rank[i]]=i;

	REP(i,n) printf("%d%c",res[i]+1,i==n-1?'\n':' ');
	return 0;
}