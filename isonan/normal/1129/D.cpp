#include <cmath>
#include <cstdio>
#include <cstring>

int n,k,a[100001],P=998244353,lcol[100001],last[100001],f[100001],val[100001],pos[100001],block;
inline int sub(int a,const int &b){a-=b;return a<0?a+P:a;}
inline int add(int a,const int &b){a+=b;return a>=P?a-P:a;}
typedef long long ll;
inline int mul(const int &a,const int &b){return (ll)a*b-(ll)a*b/P*P;}
struct sum{
	int num[200001],tot,delta;
	sum(){memset(num,0,sizeof num);tot=0;}
	void Add(const int &x){tot=add(tot,x);}
	void upd(const int &x,int &pos,const int &del){
		if(del==1)num[pos+n]=sub(num[pos+n],x);
		else num[pos-1+n]=add(num[pos-1+n],x);
		pos+=del;
	}
	int query(){return add(k>=delta?tot:0,num[k-delta+n]);}
}S[210];
void update(int L,int R,int l){
//	printf("update %d %d %d\n",L,R,l);
	if(pos[L]==pos[R]){
		for(int i=L;i<=R;i++)S[pos[i]].upd(f[i],val[i],l);
	}
	else{
		for(int i=L;pos[i]==pos[L];++i)S[pos[i]].upd(f[i],val[i],l);
		for(int i=pos[L]+1;i<pos[R];++i)S[i].delta+=l;
		for(int i=R;pos[i]==pos[R];--i)S[pos[i]].upd(f[i],val[i],l);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	block=500;
	for(int i=0;i<=n;i++)pos[i]=i/block+1;
	f[0]=1;
	S[1].Add(1);
//	for(int j=1;j<=n;j++)printf("%d ",val[j]);putchar('\n');
//		for(int j=1;j<=pos[n];j++){
//			printf("block No.%d : ",j);
//			for(int k=0;k<=block;k++)printf("%d ",add(S[j].num[k],S[j].tot));
//			printf("|| %d\n",S[j].delta);
//		}
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		last[i]=lcol[a[i]];
		lcol[a[i]]=i;
		update(last[i],i-1,1);
		if(last[i])update(last[last[i]],last[i]-1,-1);
		for(int j=pos[i];j;--j)f[i]=add(f[i],S[j].query());
		S[pos[i]].Add(f[i]);
//		for(int j=1;j<=n;j++)printf("%d ",val[j]);putchar('\n');
//		for(int j=1;j<=pos[n];j++){
//			printf("block No.%d : ",j);
//			for(int k=0;k<=block;k++)printf("%d ",add(S[j].num[k],S[j].tot));
//			printf("|| %d\n",S[j].delta);
//		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);putchar('\n');
	printf("%d\n",f[n]);
}