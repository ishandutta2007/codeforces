#include <cstdio>
const int Maxn=200000;
int n;
char s[Maxn+5];
char a[Maxn+5],b[Maxn+5];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n&1){
		puts("NO");
		return;
	}
	int lst_1=0,lst_0=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			a[i]=(lst_0==0?'(':')');
			lst_0^=1;
		}
		else{
			lst_1++;
		}
	}
	int tmp_1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			tmp_1++;
			if(tmp_1<=(lst_1>>1)){
				a[i]='(';
			}
			else{
				a[i]=')';
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			b[i]=a[i];
		}
		else{
			b[i]=(a[i]=='('?')':'(');
		}
	}
	int num_0=0,num_1=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='('){
			num_0++;
		}
		else{
			num_0--;
			if(num_0<0){
				puts("NO");
				return;
			}
		}
		if(b[i]=='('){
			num_1++;
		}
		else{
			num_1--;
			if(num_1<0){
				puts("NO");
				return;
			}
		}
	}
	if(num_0!=0||num_1!=0){
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		putchar(a[i]);
	}
	putchar('\n');
	for(int i=1;i<=n;i++){
		putchar(b[i]);
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