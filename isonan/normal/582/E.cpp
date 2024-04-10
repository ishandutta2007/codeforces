#include <cstdio>
#include <cstring>

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
char str[501];
int n,m;
const int lim=65536;
int cnt,f[201][lim];
int t1[lim],t2[lim];
int match[501],stk[501],top;
int val[4];
void FMT(int *a,int tp,int(*op)(int,const int &)){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;++k)
				if(tp==0)a[j+k]=op(a[j+k],a[i+j+k]);
				else a[i+j+k]=op(a[i+j+k],a[j+k]);
}
int solve(int l,int r){
	int now=++cnt;
	if(l==r){
		for(int i=0;i<4;++i)
			if(str[l]=='A'+i||str[l]=='?'){
				f[now][val[i]]=1;
			}
		for(int i=0;i<4;++i)
			if(str[l]=='a'+i||str[l]=='?'){
				f[now][(lim-1)^val[i]]=1;
			}
	}
	else{
		int L=solve(l+1,match[l]-1),R=solve(match[l]+3,r-1);
		for(int i=0;i<2;++i)
			if(str[match[l]+1]=='?'||str[match[l]+1]==(i?'|':'&')){
				memcpy(t1,f[L],sizeof t1);
				memcpy(t2,f[R],sizeof t2);
				FMT(t1,i,add);
				FMT(t2,i,add);
				for(int i=0;i<lim;++i)t1[i]=mul(t1[i],t2[i]);
				FMT(t1,i,sub);
				for(int i=0;i<lim;++i)f[now][i]=add(f[now][i],t1[i]);
			}
	}
	return now;
}
int main(){
	scanf("%s",str+1);
	scanf("%d",&n);
	int v1=0,v2=0;
	for(int i=1,tem;i<=n;++i){
		int x=0;
		for(int j=0;j<4;++j){
			scanf("%d",&tem);
			if(tem)x|=1<<j;
		}
		v1|=1<<x;
		scanf("%d",&tem);
		if(tem)v2|=1<<x;
	}
	for(int i=0;i<4;++i)
		for(int j=0;j<16;++j)
			if(j&(1<<i))val[i]|=1<<j;
	m=strlen(str+1);
	for(int i=1;i<=m;++i){
		if(str[i]=='(')stk[++top]=i;
		else if(str[i]==')')match[stk[top--]]=i;
	}
	int now=solve(1,m),ans=0;
	for(int i=0;i<lim;++i)
		if((i&v1)==v2)ans=add(ans,f[now][i]);
	printf("%d\n",ans);
}