#include <cstdio>
const int Maxn=400;
const int Inf=0x3f3f3f3f;
int n,m;
char a[Maxn+5],b[Maxn+5];
int f[Maxn+5][Maxn+5][2];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
bool check(int x){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i][j][0]=f[i][j][1]=-Inf;
		}
	}
	f[0][0][0]=f[0][0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x-1;j++){
			f[i][j][0]=mx(f[i][j][0],f[i-1][j][0]);
			f[i][j][0]=mx(f[i][j][0],f[i-1][j][1]);
			f[i][j][1]=mx(f[i][j][1],f[i-1][j][0]);
			f[i][j][1]=mx(f[i][j][1],f[i-1][j][1]);
		}
		for(int j=x-1;j>0;j--){
			if(a[i]==b[j]){
				f[i][j][0]=mx(f[i][j][0],f[i][j-1][0]);
			}
		}
		for(int j=0;j<=x-1;j++){
			if(f[i][j][1]>=0&&a[i]==b[x+f[i][j][1]]){
				f[i][j][1]++;
			}
		}
	}
	return x+mx(f[n][x-1][0],f[n][x-1][1])-1>=m;
}
int main(){
	int t;
	scanf("%d",&t);
	bool flag;
	while(t--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		n=m=0;
		while(a[++n]!='\0');
		n--;
		while(b[++m]!='\0');
		m--;
		flag=0;
		for(int i=1;i<=m;i++){
			if(check(i)){
				flag=1;
				break;
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
/*
1
aaaabbbbb
aaaaab
1
aabb
aaab
*/