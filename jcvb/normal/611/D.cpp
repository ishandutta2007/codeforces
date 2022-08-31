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

///////////////////
#define MAXN 50005
#define SIZE 26
///////////////////
int n,m=SIZE+1,s[MAXN],sa[MAXN],tmp1[MAXN],tmp2[MAXN],cnt[MAXN],*rk,h[MAXN];
void da(){
     int *x=tmp1,*y=tmp2,num,i,j,len;
     for (i=0;i<m;i++)cnt[i]=0;
     for (i=0;i<n;i++)cnt[s[i]]++;
     for (i=1;i<m;i++)cnt[i]+=cnt[i-1];
     for (i=n-1;i>=0;i--)sa[--cnt[s[i]]]=i;
     for (num=i=1,x[sa[0]]=0;i<n;i++)
         x[sa[i]]=s[sa[i-1]]==s[sa[i]]?num-1:num++;
     for (len=1;num<n;len<<=1){
         for (j=0;j<len;j++)y[j]=n-len+j;
         for (i=0;j<n;i++)if(sa[i]>=len)y[j++]=sa[i]-len;
        
         for (i=0;i<num;i++)cnt[i]=0;
         for (i=0;i<n;i++)cnt[x[i]]++;
         for (i=1;i<num;i++)cnt[i]+=cnt[i-1];
         for (i=n-1;i>=0;i--)sa[--cnt[x[y[i]]]]=y[i];
         
         swap(x,y);
         for (num=i=1,x[sa[0]]=0;i<n;i++)
             x[sa[i]]= y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+len]==y[sa[i]+len] ?num-1:num++;
     }
     rk=x;
}
int mi[5555][5555];
char str[5555];
void ch(){
     int i,j,l;
     for (i=l=0;i<n-1;h[rk[i++]]=l)
         for (l?l--:0,j=sa[rk[i]-1];s[j+l]==s[i+l];l++);
     h[0]=0;
}
void init(int n){
	for (int i=0;i<n;i++)s[i]=str[i+1]-'0'+1;
	s[n]=0;
	::n=n+1;
	da();
	ch();
	for (int i=0;i<n;i++){
		mi[i][i]=h[i];
		for (int j=i+1;j<n;j++)mi[i][j]=min(mi[i][j-1],h[j]);
	}
}
int cmp(int a1,int a2,int len){
	a1--,a2--;
	if(rk[a1]>=rk[a2])return 0;
	int l=rk[a1]+1,r=rk[a2];
	if(mi[l][r]>=len)return 0;
	return 1;
}
int f[5555][5555];
int main()
{
	int n;
	gn(n);
	scanf("%s",str+1);
	init(n);
	f[1][1]=1;
	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			f[l][r]=(f[l][r]+f[l][r-1])%mo;
			int len=r-l+1;
			if(r+len>n)continue;
			if(str[r+1]=='0')continue;
			int ed;
			if(cmp(l,r+1,len)){
				ed=r+len;
			}else ed=r+len+1;

			f[r+1][ed]=(f[r+1][ed]+f[l][r])%mo;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)ans=(ans+f[i][n])%mo;
	printf("%d\n",ans);
}