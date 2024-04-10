#include<bits/stdc++.h>
using namespace std;
double ans;
int m,n;
int main(){
	scanf("%d%d",&m,&n);
	ans=m;
	for(int i=1;i<=m;++i){
		ans=ans-pow(1.0*(i-1)/m,n);
	}
	printf("%.12lf",ans);
	return 0;
}