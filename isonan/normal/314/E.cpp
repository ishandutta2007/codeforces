#include <cstdio>

int n;
unsigned f[100001];
char str[100001];
int main(){
	scanf("%d%s",&n,str+1);
	if(n&1){
		puts("0");
		return 0;
	}
	f[0]=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='?')
			for(unsigned j=(i>>1),*a=f+j,*b=f+j-1;j>=1&&(int)j>=(i-(n>>1));--j,a=b--)
				(*a)+=(*b);
		else ++cnt;
	}
	unsigned ans=f[n>>1];
	for(int i=cnt+1;i<=(n>>1);i++)ans*=25;
	printf("%u\n",ans);
}