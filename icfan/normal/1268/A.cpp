#include <cstdio>
#define Maxn 200000
int n,k;
char s[Maxn+5];
char a[Maxn+5];
char mx(char a,char b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i=0;i<k;i++){
		a[i]=s[i];
	}
	bool flag=1;
	for(int i=0;i<n;i++){
		if(s[i]>a[i%k]){
			flag=0;
			break;
		}
		if(a[i%k]>s[i]){
			break;
		}
	}
	if(!flag){
		a[k-1]++;
		int i=k-1;
		while(a[i]>'9'){
			a[i]='0';
			i--;
			a[i]++;
		}
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		putchar(a[i%k]);
	}
	puts("");
	return 0;
}