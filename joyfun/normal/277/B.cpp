#include<cstdio>
#define D 10000000
int main(){
	
	int n,m;scanf("%d%d",&n,&m);
	if( m ==3 && n>=5 ) 
		printf("-1\n");
	else{
		for(int i=0;i<m;++i)
			printf("%d %d\n",i,D+i*i);
		n-=m;
		for(int i=0;i<n;++i)
			printf("%d %d\n",i,-D-i*i);
	}
	
	return 0;
}