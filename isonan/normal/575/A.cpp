#include <algorithm> 
#include <cstdio>
#include <map>
#define int long long

int K,P,N,M,s[50001];
int num[100010],top;
std::map<int,int>map;
int gs(int x){return map.count(x)?map[x]:s[x%N];}
struct matrix{
	int num[2][2];
	void init(){
		num[0][0]=num[1][1]=1;
		num[0][1]=num[1][0]=0;
	}
	matrix operator*(const matrix &a){
		static matrix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				c.num[i][j]=(1ll*num[i][0]*a.num[0][j]+1ll*num[i][1]*a.num[1][j])%P;
		return c;
	}
}se[200001],unit;
struct vector{
	int num[2];
	vector operator*(const matrix &a){
		static vector c;
		for(int i=0;i<2;i++)
			c.num[i]=(1ll*num[0]*a.num[0][i]+1ll*num[1]*a.num[1][i])%P;
		return c;
	}
};
void build(int root,int l,int r){
	if(l==r){
		se[root].num[0][0]=s[(l+1)%N];
		se[root].num[1][0]=s[l];
		se[root].num[0][1]=1;
		se[root].num[1][1]=0;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=se[root<<1]*se[root<<1|1];
}
matrix query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return unit;
	if(el<=l&&er>=r)return se[root];
	return query(root<<1,l,(l+r)>>1,el,er)*query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
matrix qsm(matrix a,int b){
	matrix ans=unit;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
matrix get(int l,int r){
	if(l>r)return unit;
	if((l/N)==(r/N))return query(1,0,N-1,l%N,r%N);
	return query(1,0,N-1,l%N,N-1)*qsm(se[1],(r/N)-(l/N)-1)*query(1,0,N-1,0,r%N);
}
signed main(){
	scanf("%I64d%I64d%I64d",&K,&P,&N);
	if(!K){
		puts("0");
		return 0;
	}
	--K;
	unit.init();
	for(int i=0;i<N;i++)scanf("%I64d",s+i);
	build(1,0,N-1);
	scanf("%I64d",&M);
	for(int i=1,j,v;i<=M;i++){
		scanf("%I64d%I64d",&j,&v);
		map[j]=v;
		num[++top]=j-1;
		num[++top]=j;
	}
	std::sort(num+1,num+top+1);
	top=std::unique(num+1,num+top+1)-num-1;
	vector ans;
	ans.num[0]=1,ans.num[1]=0;
	num[0]=-1;
	while(num[top]>=K)--top;
	for(int i=1;i<=top;i++){
		ans=ans*get(num[i-1]+1,num[i]-1);
		matrix tem;
		tem.num[0][0]=gs(num[i]+1);
		tem.num[1][0]=gs(num[i]);
		tem.num[0][1]=1;
		tem.num[1][1]=0;
		ans=ans*tem;
	}
	ans=ans*get(num[top]+1,K-1);
	printf("%I64d\n",ans.num[0]);
}