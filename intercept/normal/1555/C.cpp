#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int m;
int a[2][M];
void work(){
	scanf("%d",&m);
	for(int i=0;i<2;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i][j-1];
		}
	}
	int ma=1e9;
	for(int i=1;i<=m;++i){
		ma=min(ma,max(a[0][m]-a[0][i],a[1][i-1]));
	}
	printf("%d\n",ma);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}