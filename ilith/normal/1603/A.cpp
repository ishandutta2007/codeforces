#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define ROF(i,a,b) for(rgi i=a;i>=b;--i) 
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=300010;
int n,a[N],T;
signed main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		FOR(i,1,n)scanf("%d",a+i);
		FOR(i,1,n){
			int fl=0;
			FOR(j,2,i+1)if(a[i]%j){
				fl=1;
				break;
			}
			if(!fl){
				puts("NO");
				goto tag;
			}
		}
		puts("YES");
		tag:;
	}
	return 0;
}