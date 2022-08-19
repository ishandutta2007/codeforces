#include <cstdio>
#include <cstring>

const int P=10007;
inline int mul(const int &a,const int &b){return a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int f[210][210][210],n,nl,mx0,mx1,mat[410][410],ans[410][410],tem[410][410],fin;
char s[210];
		long long T=0;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%s%d",s+1,&n);
	n+=(nl=strlen(s+1));
	f[0][nl+1][0]=1;
	for(int i=0;i<=nl;i++)
		for(int j=nl+1;j>i;--j)
			for(int k=0;k<=nl;k++)
				if(s[i+1]==s[j-1]&&i+1!=j-1)f[i+1][j-1][k]=add(f[i+1][j-1][k],f[i][j][k]);
				else if(i+1==j-1)f[i+1][j][k]=add(f[i+1][j][k],f[i][j][k]);
				else f[i+1][j][k+1]=add(f[i+1][j][k+1],f[i][j][k]),
					 f[i][j-1][k+1]=add(f[i][j-1][k+1],f[i][j][k]);
	int cnt=(nl<<1)+1;
	for(int i=1;i<nl;i++)mat[i][i+1]=1;
	for(int i=1;i<=nl;i++)mat[i][i]=25;
	for(int i=nl+1;i<cnt;i++)mat[i][i+1]=1;
	for(int i=nl+1;i<cnt;i++)mat[i][i]=24;
	mat[cnt][cnt]=26;
	for(int i=0;i<=nl;i++)
		for(int k=0;k<=nl;k++)
			mat[((nl-k+1)>>1)][cnt-k]=add(mat[((nl-k+1)>>1)][cnt-k],f[i][i+1][k]);
//	for(int i=1;i<=cnt;i++,putchar('\n'))
//		for(int j=1;j<=cnt;j++)
//			printf("%d ",mat[i][j]);
	for(int i=1;i<=cnt;i++)ans[i][i]=1;
	int orig=n;
	n=n>>1;
		while(n){
			if(n&1){
				memset(tem,0,sizeof tem);
				for(int i=1;i<=cnt;i++)
					for(int j=i;j<=cnt;j++){
						T=0;
						for(int k=i;k<=j;k++)
							T+=ans[i][k]*mat[k][j];
						tem[i][j]=T%P;
					}
				memcpy(ans,tem,sizeof tem);
			}
			memset(tem,0,sizeof tem);
				for(int i=1;i<=cnt;i++)
					for(int j=i;j<=cnt;j++){
						T=0;
						for(int k=i;k<=j;k++)
							T+=mat[i][k]*mat[k][j];
						tem[i][j]=T%P;
					}
			memcpy(mat,tem,sizeof tem);
			n>>=1;
		}
	fin=ans[1][cnt];
	if(orig%2==1){
		int cnt=(nl<<1)+1;
		memset(mat,0,sizeof mat);
		for(int i=1;i<nl;i++)mat[i][i+1]=1;
		for(int i=1;i<=nl;i++)mat[i][i]=25;
		for(int i=nl+1;i<cnt;i++)mat[i][i+1]=1;
		for(int i=nl+1;i<cnt;i++)mat[i][i]=24;
		for(int i=0;i<=nl;i++)
			for(int k=0;k<nl;k++)
				mat[((nl-k)>>1)+1][cnt-k]=add(mat[((nl-k)>>1)+1][cnt-k],f[i][i+2][k]);
//	for(int i=1;i<=cnt;i++,putchar('\n'))
//		for(int j=1;j<=cnt;j++)
//			printf("%d ",mat[i][j]);
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				ans[i][j]=(i==j);
		n=(orig+1)>>1;
		while(n){
			if(n&1){
				memset(tem,0,sizeof tem);
				for(int i=1;i<=cnt;i++)
					for(int j=i;j<=cnt;j++){
						T=0;
						for(int k=i;k<=j;k++)
							T+=ans[i][k]*mat[k][j];
						tem[i][j]=T%P;
					}
				memcpy(ans,tem,sizeof tem);
			}
			memset(tem,0,sizeof tem);
				for(int i=1;i<=cnt;i++)
					for(int j=i;j<=cnt;j++){
						T=0;
						for(int k=i;k<=j;k++)
							T+=mat[i][k]*mat[k][j];
						tem[i][j]=T%P;
					}
			memcpy(mat,tem,sizeof tem);
			n>>=1;
		}
		printf("%d\n",add(mul(fin,26),ans[1][cnt]));
	}
	else printf("%d\n",fin);
}