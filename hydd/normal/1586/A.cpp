#include<bits/stdc++.h>
using namespace std;
int T,n,a[110];
bool check(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return true;
	return false;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); int pos=0,sum=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i]; if (a[i]&1) pos=i;
		}
		if (check(sum)){
			printf("%d\n",n);
			for (int i=1;i<=n;i++) printf("%d ",i);
		} else{
			printf("%d\n",n-1);
			for (int i=1;i<=n;i++)
				if (i!=pos) printf("%d ",i);
		}
		putchar('\n');
	}
	return 0;
}