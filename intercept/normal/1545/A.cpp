#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,a[2][M];
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i&1][(i+1)/2]);
	sort(a[0]+1,a[0]+(n/2)+1);
	sort(a[1]+1,a[1]+(n+1)/2+1);
	for(int i=1;i<=n;++i){
		if(a[i&1][(i+1)/2]<a[(i-1)&1][i/2]){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}