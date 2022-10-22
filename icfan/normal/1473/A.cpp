#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100;
int n,d;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		if(a[n]<=d){
			puts("YES");
			continue;
		}
		if(a[1]+a[2]<=d){
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}