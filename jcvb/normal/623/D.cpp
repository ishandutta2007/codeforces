#include<cstdio>
#include<cassert>
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
typedef long double db;
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
ll inf=1e18;
db eps=1e-6;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n;
db p[111];
db pp[111];
db lef[111],rig[111];
db ans;

void doit(){
	lef[0]=1.0;
	for (int j=1;j<=n;j++)lef[j]=lef[j-1]*(1-pp[j]);
	rig[n+1]=1.0;
	for (int j=n;j>=1;j--)rig[j]=rig[j+1]*(1-pp[j]);
	int opt=1;db ma=-1.0;
	for (int j=1;j<=n;j++){
		db tmp=lef[j-1]*rig[j+1]*(1-pp[j]*(1.0-p[j]));
		if(tmp>ma){
			ma=tmp;
			opt=j;
		}
	}
	ans+=1.0-ma;
	pp[opt]*=1.0-p[opt];
}
void doit2(){
	lef[0]=1.0;
	for (int j=1;j<=n;j++)lef[j]=lef[j-1]*(1-pp[j]);
	rig[n+1]=1.0;
	for (int j=n;j>=1;j--)rig[j]=rig[j+1]*(1-pp[j]);
	int opt=1;db ma=-1.0;
	for (int j=1;j<=n;j++){
		db tmp=lef[j-1]*rig[j+1]*(1-pp[j]*(1.0-p[j]));
		if(tmp>ma){
			ma=tmp;
			opt=j;
		}
	}
	while(opt>=2 && fabs(p[opt-1]-p[opt])<1e-6)opt--;

	db tmp=lef[opt-1];
	for (int i=opt;i<=n && fabs(p[i]-p[opt])<1e-6;i++){
		pp[i]*=1.0-p[i];
		tmp*=(1-pp[i]);
		ans+=1.0-tmp*rig[i+1];
	}
}
int main(){
	gn(n);
	for (int i=1;i<=n;i++){
		int x;gn(x);
		p[i]=1.0*x/100;
		if(i<n)pp[i]=1.0-p[i];
		else pp[i]=1.0;
	}
	ans=(n-1)*1.0;
	doit();
	for (int i=1;i<=100000;i++){
		doit2();
	}
	printf("%.10lf\n",double(ans+1.0));
	return 0;
}