#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e3+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m;
char A[N],B[N];
int f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",A+1);
	scanf("%s",B+1);
	int ans=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			ans=max(ans,f[i][j]);
			if(i<n) f[i+1][j]=max(f[i+1][j],f[i][j]-1);
			if(j<m) f[i][j+1]=max(f[i][j+1],f[i][j]-1);
			if(i<n&&j<m&&A[i+1]==B[j+1]) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+2);
		}
	}
	printf("%d\n",ans);
	return 0;
}