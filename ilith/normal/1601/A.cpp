#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define ROF(i,a,b) for(rgi i=a;i>=b;--i) 
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=400010;
int T,n,a[N],ans,b[50];
signed main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		FOR(j,0,30)b[j]=0;
		FOR(i,1,n){
			scanf("%d",a+i);
			FOR(j,0,30){
				if(a[i]&(1<<j))++b[j];
			}
		}
		FOR(i,1,n){
			int fl=1;
			FOR(j,0,30){
				if(b[j]&&b[j]%i){
					fl=0;
					break;
				}
			}
			if(fl)printf("%d ",i);
		}
		puts("");
	}
	return 0;
}