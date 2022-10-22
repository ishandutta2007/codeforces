#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=3e5+10;
int n,K;
int a[N];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		int j=i,f=0;
		for(;j>=1;--j){
			if(a[i]%(j+1)){
				f=1;
				break;
			}
		}
		if(!f){
			puts("NO");
			return;
		}
	}
	puts("YES");
	return;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		MAIN();
	}
    return 0;
}