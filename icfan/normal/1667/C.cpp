#include <cstdio>
const int Maxn=100000;
int n;
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("1\n1 1");
		return 0;
	}
	for(int i=n,j;i>0;i--){
		int num=(i-1)*2+1;
		if(n-i>=num){
			printf("%d\n",n-i);
			j=1;
			while(j<i){
				j+=2;
			}
			j-=2;
			int nxt=j+2;
			int pos=1;
			while(j>0){
				printf("%d %d\n",pos,pos+j);
				printf("%d %d\n",pos+j,pos);
				pos++;
				j-=2;
			}
			j=0;
			while(j<i){
				j+=2;
			}
			j-=2;
			pos=nxt;
			nxt=pos+j+1;
			while(j>0){
				printf("%d %d\n",pos,pos+j);
				printf("%d %d\n",pos+j,pos);
				pos++;
				j-=2;
			}
			printf("%d %d\n",pos,pos);
			for(int k=nxt;k<=n-i;k++){
				printf("%d %d\n",k,k);
			}
			return 0;
		}
	}
	return 0;
}