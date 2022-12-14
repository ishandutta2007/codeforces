#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
//jiaohuan  n m
#define N 2105
int f[30],s_[30],z_[30],x_[30],y_[30],b[N][N],t,n,m,ii,jj,h;
char a[N][N];//int   //int =char    ///bool     ...  ...
int main()
{
	t=read();
	while(t--) {
		n=read(); m=read();
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)b[i][j]=a[i][j]-96;
		for(int k=26;k;--k){
			f[k]=0;
			for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				if(b[i][j]==k){
					if(!f[k]){
						f[k]=1;  ///a=b=1;
						s_[k]=i; z_[k]=j;
						x_[k]=i; y_[k]=j;
						continue;
					}
					if(f[k]==1){
						if(s_[k]==i){
							f[k]=2;
							y_[k]=j;
							continue;
						}
						if(z_[k]==j){
							f[k]=3;
							x_[k]=i;
							continue;
						}
						puts("NO");
						goto lll;
					}
					if(f[k]==2){
						if(s_[k]==i){
							y_[k]=j;
							continue;
						}
						puts("NO");
						goto lll;
					}
					if(z_[k]==j){
						x_[k]=i;
						continue;
					}
					puts("NO");
					goto lll;
				}
			}  //a   <=  < > >=  ??? /// dizhi ?  //it ?    !=  < >   <= >=   ==    //'a' ??  ///??\   ///  \////
			if(f[k]<=1)continue;
			if(f[k]==2){
				ii=s_[k];
				for(int j=z_[k];j<=y_[k];++j)if(b[ii][j]<k){
					puts("NO");
					goto lll;
				}
			}
			if(f[k]==3){
				jj=z_[k];
				for(int i=s_[k];i<=x_[k];++i)if(b[i][jj]<k){
					puts("NO");
					goto lll;
				}
			}
			//continue;
		}
		
		puts("YES");
		for(h=26;h;--h)if(f[h])break;
		for(int i=h;i;--i){   ///  -1
			if(!f[i]){
				f[i]=f[i+1];
				s_[i]=s_[i+1];
				z_[i]=z_[i+1];
				x_[i]=x_[i+1];
				y_[i]=y_[i+1];
			}
		}
		printf("%d\n",h);//  ///ans
		for(int i=1;i<=h;++i){ //_  \n    //duoge ?? //...         //\r\n    //
			printf("%d %d %d %d\n",s_[i],z_[i],x_[i],y_[i]);//cin cout    xiaoshudian  changkuan ... ..
		}
		lll:;  //i=0;i;--i
	}
	
}