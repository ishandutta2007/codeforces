#include <cstdio>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,a[200001],b[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int ans=0;
	for(int i=0;i<=30;++i){
		int b[2]={0,0};
		for(int j=1;j<=n;++j)
			if((a[j]%(1<<i))==0)b[(a[j]>>i)&1]++;
		// printf("%d %d %d\n",i,b[0],b[1]);
		if(!i){
			ans=add(ans,qsm(2,b[0]+b[1]));
			ans=sub(ans,qsm(2,b[0]));
			continue;
		}
		ans=add(ans,qsm(2,b[0]+b[1]-(b[1]!=0)));
		int b3=0;
		for(int j=1;j<=n;++j)
			if((a[j]%(1<<(i+1)))==0)++b3;
		ans=sub(ans,qsm(2,b3));
	}
	printf("%d\n",ans);
}