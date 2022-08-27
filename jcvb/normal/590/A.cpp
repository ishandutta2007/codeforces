#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;


int n;
int a[555555];
int chg[555555];
int len[555555];

int ma=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)gn(a[i]);
	for (int i=2;i<n;i++)chg[i]=(a[i]!=a[i-1]) && (a[i]!=a[i+1]);
	for (int i=2;i<=n;i++)
		if(chg[i]==1){
			len[i]=len[i-1]+1;
		}else len[i]=0;
	for (int i=1;i<=n;i++)if(len[i] && len[i+1]==0){
		ma=max(ma,(len[i]+1)/2);
		int lef=i-len[i]+1;
		if(len[i]%2==0){
			for (int j=lef;j<lef+len[i]/2;j++)a[j]=a[lef-1];
			for (int j=lef+len[i]/2;j<=i;j++)a[j]=a[i+1];
		}else{
			for (int j=lef;j<=i;j++)a[j]=a[lef-1];
		}
	}
	printf("%d\n",ma);
	for (int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}