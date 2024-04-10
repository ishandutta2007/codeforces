#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000007
using namespace std;
int n;
const int M=1<<20;
int a[M]={0};
inline void upd(int &a,int b){
	a+=b;if(a>=mo)a-=mo;if(a<0)a+=mo;
}
int qp(int a,int b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int cnt(int x){
	int t=1;
	while(x){
		if(x&1)t*=-1;
		x>>=1;
	}
	return t;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[x]++;
	}
	for (int i=0;i<20;i++)
		for (int j=0;j<M;j++)if(!(j&1<<i))upd(a[j],a[j+(1<<i)]);
	int ans=0;
	for (int i=0;i<M;i++)upd(ans,cnt(i)*qp(2,a[i]));
	printf("%d\n",ans);
	return 0;
}