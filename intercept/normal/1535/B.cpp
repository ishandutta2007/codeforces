#include<bits/stdc++.h>
using namespace std;
const int M=2009;
int n;
int a[M];
void work(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(__gcd(a[i]*2,a[j])>1||__gcd(a[i],a[j]*2)>1)ans++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}