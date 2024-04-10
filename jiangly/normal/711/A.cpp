#include<bits/stdc++.h>
const int N=1e3+5;
int n;
bool flag;
char a[N][10];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
		if(!flag&&a[i][1]=='O'&&a[i][2]=='O'){
			a[i][1]=a[i][2]='+';
			flag=1;
		}
		if(!flag&&a[i][4]=='O'&&a[i][5]=='O'){
			a[i][4]=a[i][5]='+';
			flag=1;
		}
	}
	if(flag){
		puts("YES");
		for(int i=1;i<=n;++i){
			puts(a[i]+1);
		}
	}else{
		puts("NO");
	}
	return 0;
}