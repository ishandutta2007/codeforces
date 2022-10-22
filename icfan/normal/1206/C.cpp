#include <cstdio>
#define Maxn 100000
int a[Maxn<<1|5];
int main(){
	int n;
	scanf("%d",&n);
	int x=1;
	if(!(n&1)){
		puts("NO");
	}
	else{
		puts("YES");
		for(int i=1;i<=(n<<1);i++){
			a[x]=i;
			if(i&1){
				x+=n;
				if(x>(n<<1)){
					x-=(n<<1);
				}
			}
			else{
				x++;
				if(x>(n<<1)){
					x-=(n<<1);
				}
			}
		}
		for(int i=1;i<=(n<<1);i++){
			printf("%d ",a[i]);
		}
		puts("");
	}
	return 0;
}