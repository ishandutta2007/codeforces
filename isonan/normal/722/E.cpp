#include <cstdio>
#include <algorithm>

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
int n,m,k,s;
struct tile{
	int x,y;
}num[2010];
bool cmp(tile a,tile b){return (a.x<b.x)||(a.x==b.x&&a.y<b.y);}
int f[2010][26],lim=25;
int _mul[200001],invmul[200001];
int C(int n,int m){if(n<m||m<0)return 0;return mul(mul(_mul[n],invmul[m]),invmul[n-m]);} 
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=n+m;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n+m;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=n+m;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	bool h1=0,h2=0;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&num[i].x,&num[i].y);
		if(num[i].x==1&&num[i].y==1)h1=1,s=(s+1)>>1;
		else if(num[i].x==n&&num[i].y==m)h2=1,s=(s+1)>>1;
	}
	if(n==1&&m==1){
		printf("%d\n",s);
		return 0;
	}
	if(!h1)num[++k]=(tile){1,1};
	if(!h2)num[++k]=(tile){n,m};
	std::sort(num+1,num+k+1,cmp);
	f[1][0]=1;
	for(int i=2;i<=k;i++){
		for(int j=1;j<i;j++){
			int Mul=C(num[i].x-num[j].x+num[i].y-num[j].y,num[i].x-num[j].x);
			if(i<k)
				for(int l=0;l<=lim;l++)
					f[i][l]=add(f[i][l],mul(Mul,sub(l?f[j][l-1]:0,f[j][l])));
			else
				for(int l=0;l<=lim;l++)
					f[i][l]=add(f[i][l],mul(Mul,f[j][l]));
		}
//		printf("(%d %d)\n",num[i].x,num[i].y);
//		for(int j=0;j<=k;j++)
//			printf("%d ",f[i][j]);
//		putchar('\n');
	}
	int res=C(n-1+m-1,m-1),ans=0;
	for(int i=0;i<=lim;i++){
		ans=add(ans,mul(s,f[k][i]));
		s=(s+1)>>1;
		res=sub(res,f[k][i]);
	}
	printf("%d\n",mul(qsm(C(n-1+m-1,m-1),P-2),add(ans,res)));
}