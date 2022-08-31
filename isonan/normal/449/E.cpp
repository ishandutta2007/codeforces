#include <cstdio>
#include <vector>

typedef std::vector<int>poly;
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
poly operator*(poly a,poly b){
	int size=a.size()+b.size()-1;
	poly c(size);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
int prime[1000001],top,t,phi[1000001];
int f[1000001],sumf[3][1000001],sum[6][1000001];
bool pri[1000001];
int main(){
	phi[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!pri[i])prime[++top]=i,phi[i]=i-1;
		for(int j=1;j<=top&&i*prime[j]<=1000000;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
		f[i]%=P;
	}
	for(int i=1;i<=1000000;i++)
		for(int j=i;j<=1000000;j+=i)
			f[j]=add(f[j],mul(i,phi[j/i]));
//	for(int i=1;i<=10;i++)printf("%d\n",f[i]);
	for(int i=1;i<=1000000;i++){
		for(int j=0,Mul=f[i];j<3;j++,Mul=mul(Mul,i))
			sumf[j][i]=add(sumf[j][i-1],Mul);
		for(int j=0,Mul=1;j<6;j++,Mul=mul(Mul,i))
			sum[j][i]=add(sum[j][i-1],Mul);
	}
	scanf("%d",&t);
	for(int i=1,n,m;i<=t;i++){
		scanf("%d%d",&n,&m);
		if(n>m)std::swap(n,m);
		poly f;
		f.push_back(mul(n+1,m+1));
		f.push_back(sub(0,add(n+1,m+1)));
		f.push_back(1);
		poly g;
		g.push_back(0);
		g.push_back((P+1)/3);
		g.push_back(P-2);
		g.push_back(mul((P+1)/3,2));
		g=g*f;
		int ans=0;
//		for(int i=0;i<g.size();i++)printf("%d ",mul(3,g[i]));putchar('\n');
		for(int i=0;i<g.size();i++)ans=add(ans,mul(sum[i][n],g[i]));
//		printf("%d\n",ans);
		for(int i=0;i<f.size();i++)ans=add(ans,mul(sumf[i][n],mul(f[i],2)));
		printf("%d\n",ans);
	}
}