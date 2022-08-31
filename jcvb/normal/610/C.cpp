#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
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
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789


int a[555][555];

int main()
{
	int n;
	gn(n);
	a[1][1]=1;
	for (int k=1;k<=256;k<<=1){

		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++){
				a[i+k][j]=a[i][j+k]=a[i][j];
				a[i+k][j+k]=!a[i][j];
			}
	}
	int s=1<<n;
	for (int i=1;i<=s;i++){
		for (int j=1;j<=s;j++)putchar(a[i][j]?'+':'*');
		putchar('\n');
	}
	return 0;
}