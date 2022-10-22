#include <cstdio>
#define Maxn 200000
char s[Maxn+5];
char t[Maxn+5];
int s_n,t_n;
int f[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	while(s[++s_n]!='\0');
	s_n--;
	while(t[++t_n]!='\0');
	t_n--;
	for(int i=s_n-1,j=t_n+1;i>0;i--){
		if(s[i+1]==t[j-1]){
			f[i]=f[i+1]+1;
			j--;
		}
		else{
			f[i]=f[i+1];
		}
	}
	int ans=0;
	for(int i=1,j=0,k=0;i<=s_n;i++){
		if(s[i-1]==t[j+1]){
			j++;
		}
		while(k<s_n&&f[k+1]+j>=t_n){
			k++;
		}
		ans=mx(ans,k-i+1);
	}
	printf("%d\n",ans);
	return 0;
}