#include<bits/stdc++.h>
char a[3],b[3];
int main(){
	scanf("%s",a+1);
	for(int i=1;i<=5;++i){
		scanf("%s",b+1);
		if(a[1]==b[1]||a[2]==b[2]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}