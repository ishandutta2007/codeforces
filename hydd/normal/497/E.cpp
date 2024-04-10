#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
ll n;
int m,K,sum,now,a[110];
void ADD(int &x,int y,int m){
	x+=y; if (x>=m) x-=m;
}
struct Matrix{
	int v[35][35];
	Matrix(){ memset(v,0,sizeof(v));}
	Matrix operator*(const Matrix &a) const{
		Matrix res;
		for (int k=0;k<=K;k++)
			for (int i=0;i<=K;i++)
				if (v[i][k])
					for (int j=0;j<=K;j++)
						if (a.v[k][j])
							res.v[i][j]=(1ll*v[i][k]*a.v[k][j]+res.v[i][j])%Mod;
		return res;
	}
} ans,/*hanhan,*/s[75][35],pre[75][35],suf[75][35];
void work(ll n){
	ll tmp=n;
	while (tmp){
		a[++m]=tmp%K;
		tmp/=K;
	}
	reverse(a+1,a+m+1);
}
int main(){
	scanf("%lld%d",&n,&K);
//	n++; 
	work(n);
	for (int i=0;i<K;i++){
		for (int j=0;j<=K;j++) s[0][i].v[j][j]=1;
		for (int j=0;j<=K;j++) s[0][i].v[i][j]=1;
	}
//	hanhan=s[0][0]*s[0][1]*s[0][2]*s[0][3]*s[0][4]*s[0][5]*s[0][6];
	for (int i=1;i<=m;i++){
		pre[i-1][0]=s[i-1][0]; suf[i-1][K-1]=s[i-1][K-1];
		for (int j=1;j<K;j++) pre[i-1][j]=pre[i-1][j-1]*s[i-1][j];
		for (int j=K-2;j>=0;j--) suf[i-1][j]=s[i-1][j]*suf[i-1][j+1];
		for (int j=0;j<K;j++)
			if (j) s[i][j]=suf[i-1][j]*pre[i-1][j-1];
			else s[i][j]=suf[i-1][j];
	}
	for (int i=0;i<=K;i++)
		for (int j=0;j<=K;j++)
			ans.v[i][j]=(i==j);
	now=0;
	for (int i=1;i<=m;i++){
		//now+0,now+1,...,now+a[i]-1
		if (a[i]){
			if (now+a[i]-1>=K){
				for (int j=now;j<K;j++) ans=ans*s[m-i][j];
				for (int j=0;j<=(now+a[i]-1)-K;j++) ans=ans*s[m-i][j];
			} else 
				for (int j=now;j<=now+a[i]-1;j++) ans=ans*s[m-i][j];
			ADD(now,a[i],K);
		}
	}
	for (int i=0;i<=K;i++) ADD(sum,ans.v[i][K],Mod);
	printf("%d\n",sum);
	return 0;
}