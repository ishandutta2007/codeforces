#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
const int Maxn=20;
const int Maxm=400;
char s[Maxn+5],t[Maxn+5];
int s_len,t_len;
char a[Maxm+5],b[Maxm+5];
void solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	s_len=0;
	t_len=0;
	while(s[++s_len]!='\0');
	s_len--;
	while(t[++t_len]!='\0');
	t_len--;
	int len=lcm(s_len,t_len);
	for(int i=1;i<=len;i++){
		a[i]=s[i%s_len==0?s_len:i%s_len];
		b[i]=t[i%t_len==0?t_len:i%t_len];
		if(a[i]!=b[i]){
			puts("-1");
			return;
		}
	}
	for(int i=1;i<=len;i++){
		putchar(a[i]);
	}
	putchar('\n');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}