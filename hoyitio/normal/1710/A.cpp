#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],k,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		bool flag=false;
		ll sum=0;
		for(ri i=1;i<=k;++i){
			scanf("%d",a+i);
			if(a[i]/m>1){
				sum+=a[i]/m;
				if(a[i]/m>2)flag=true;
			}
		}
		if(sum>=n&&(flag||!(n&1))){
			puts("YES");
			continue;
		}
		sum=flag=0;
		for(ri i=1;i<=k;++i)
			if(a[i]/n>1){
				sum+=a[i]/n;
				if(a[i]/n>2)flag=true;
			}
		if(sum>=m&&(flag||!(m&1))){
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}