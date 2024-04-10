#include <cstdio>
#define Maxn 100000
int n;
char s[Maxn+5];
int a[Maxn+5];
int lst[Maxn+5];
int f[Maxn+5];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int a,int b){
	int fa_x=find(a),fa_y=find(b);
	if(fa_x==fa_y){
		return;
	}
	if(fa_x>fa_y){
		fa_x^=fa_y^=fa_x^=fa_y;
	}
	f[fa_y]=fa_x;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	int last=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			lst[i]=last;
			last=i;
		}
		f[i]=i;
	}
	int now=0,num_0=0,num_1=0;
	last=0;
	int ans=0;
	int x;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			a[i]=0;
			num_0++;
			ans++;
			if(num_0>=num_1){
				now+=num_0;
				num_0=num_1=0;
			}
		}
		else{
			num_1++;
			ans++;
			last=i;
		}
		if(now+mx(num_0,num_1)<ans){
			while(a[last]==1){
				last=find(last);
				x=lst[last];
				if(a[x]==0){
					merge(x,last);
				}
				last=x;
			}
			a[last]=1;
			ans--;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	puts("");
	return 0;
}