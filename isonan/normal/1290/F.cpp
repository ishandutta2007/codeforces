#include <cstdio>

const int P=998244353;
inline void add(int &a,const int &b){a+=b;(a>=P)?a-=P:a;}
int f[30][33][33][33][33][2][2],n,m,x[6],y[6],sum1,sum2,sum3,sum4;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		if(x[i]<0)sum1-=x[i];
		else sum2+=x[i];
		if(y[i]<0)sum3-=y[i];
		else sum4+=y[i];
	}
	sum1<<=1;
	sum2<<=1;
	sum3<<=1;
	sum4<<=1;
	if(!sum1||!sum2||!sum3||!sum4){
		puts("0");
		return 0;
	}
	f[0][0][0][0][0][0][0]=1;
	int ans=P-1;
	for(int i=0;i<30;i++){
//		printf("%d\n",i);
		for(int j=1;j<=n;j++)
			for(int i1=sum1;~i1;i1--)
				for(int i2=sum2;~i2;i2--)
					for(int i3=sum3;~i3;i3--)
						for(int i4=sum4;~i4;i4--)
							for(int k=0;k<2;k++)
								for(int l=0;l<2;l++){
									int n1=i1,n2=i2,n3=i3,n4=i4;
									if(x[j]<0)n1-=x[j];
									else n2+=x[j];
									if(y[j]<0)n3-=y[j];
									else n4+=y[j];
									add(f[i][n1][n2][n3][n4][k][l],f[i][i1][i2][i3][i4][k][l]);
								}
		bool This=((m&(1<<i))!=0);
			for(int i1=sum1;~i1;i1--)
				for(int i2=sum2;~i2;i2--)
					for(int i3=sum3;~i3;i3--)
						for(int i4=sum4;~i4;i4--)
							for(int k=0;k<2;k++)
								for(int l=0;l<2;l++){
									int nk=k,nl=l;
									if((i1&1)!=(i2&1)||(i3&1)!=(i4&1))continue;
									if((i1&1)!=This)nk=!This;
									if((i3&1)!=This)nl=!This;
									if(i==29){
										if(((i1|i2|i3|i4)>>1)==0&&!nk&&!nl)add(ans,f[i][i1][i2][i3][i4][k][l]);
									}
									else add(f[i+1][i1>>1][i2>>1][i3>>1][i4>>1][nk][nl],f[i][i1][i2][i3][i4][k][l]);
								}
	}
	printf("%d\n",ans);
}