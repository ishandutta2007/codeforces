#include <cstdio>
const int Maxn=100;
int n;
char s[Maxn+5];
int main(){
	int t;
	scanf("%d",&t);
	int ans,sum;
	while(t--){
		scanf("%s",s+1);
		n=0;
		while(s[++n]!='\0');
		n--;
		sum=0;
		ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				sum++;
			}
		}
		if(sum==n){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				ans++;
			}
			else{
				break;
			}
		}
		for(int i=n;i>0;i--){
			if(s[i]=='0'){
				ans++;
			}
			else{
				break;
			}
		}
		printf("%d\n",sum-ans);
	}
	return 0;
}