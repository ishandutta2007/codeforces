#include<bits/stdc++.h>
const int N=3e5+6;
int n;
char a[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]){
			puts("YES");
			printf("%d %d\n",i,i+1);
			return 0;
		}
	}
	puts("NO");
	return 0;
}