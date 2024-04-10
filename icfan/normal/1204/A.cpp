#include <cstdio>
char s[105];
int main(){
	int n=0;
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	bool all_zero=1;
	for(int i=2;i<=n;i++){
		if(s[i]=='1'){
			all_zero=0;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i+=2){
		if(i==n){
			if(!all_zero){
				ans++;
			}
		}
		else{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}