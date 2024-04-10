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
int a[2111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		gn(x);
		a[x]++;
	}
	int ans=0;
	for (int i=0;i<2000000;i++){
		a[i+1]+=(a[i]>>1);
		ans+=(a[i]&1);
	}
	printf("%d\n",ans);
	return 0;
}