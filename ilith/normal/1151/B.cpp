#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=510;
int n,m,fl,k;
int a[N][N],g[N];
signed main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n){
		FOR(j,1,m){
			scanf("%d",a[i]+j);
			if(a[i][j]!=a[i][1])g[i]=j;
		}
		k^=a[i][1];
		fl|=g[i];
	}
	fl|=k;
	puts(fl?"TAK":"NIE");
	if(fl){
		if(k){
			FOR(i,1,n)printf("1 ");
			exit(0);
		}
		else{
			int t=0;
			FOR(i,1,n){
				if(g[i]&&!t)t=1,printf("%d ",g[i]);
				else printf("1 ");
			}
		}
	}
	return 0;
}