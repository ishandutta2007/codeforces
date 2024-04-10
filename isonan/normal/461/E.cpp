#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

int son[8000001][4],len,loglen,points=1,q[8000001],h,t,dep[8000001];
struct point{
	long long num[4][4];
	long long *operator[](int n){
		return num[n];
	}
	long long val(){
		long long tem=1000000000000000001l;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				tem=min(tem,num[i][j]);
		return tem;
	}
}mn[101];
point merge(point a,point b){
	point ans;
	for(int j=0;j<4;j++)
		for(int k=0;k<4;k++)
			ans[j][k]=min(min(a[j][0]+b[0][k],a[j][1]+b[1][k]),min(a[j][2]+b[2][k],a[j][3]+b[3][k]));
	return ans;
}
long long n;
char str[100001];

int main(){
	scanf("%I64d%s",&n,str+1);
	len=strlen(str+1);
	loglen=(int)log2(len);
	for(int i=1;i+loglen-1<=len;i++){
		int now=1;
		for(int j=0;j<loglen;j++){
			if(!son[now][str[i+j]-'A'])son[now][str[i+j]-'A']=++points,dep[points]=dep[now]+1;
			now=son[now][str[i+j]-'A'];
		}
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			if(!son[1][i]){
				mn[0][i][j]=1000000000000000001ll;
				continue;
			}
			h=t=0;
			q[++t]=son[1][i];
			while(h<t){
				++h;
				if(!son[q[h]][j])break;
				for(int k=0;k<4;k++)if(son[q[h]][k])q[++t]=son[q[h]][k];
			}
			mn[0][i][j]=(long long)dep[q[h]];
		}
	for(int i=1;i<=100;i++)mn[i]=merge(mn[i-1],mn[i-1]);
	long long l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		bool cando=0;
		point tem;
		long long t=mid;
		for(long long i=62;~i;--i)
			if(t>=(1ll<<i)){
				if(!cando)cando=1,tem=mn[i];
				else tem=merge(tem,mn[i]);
				t-=1ll<<i;
			}
		if(tem.val()<n)ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans+1);
}