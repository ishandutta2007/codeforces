#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=205,M=1e6+10;
ll a[M+10],n;
int f[N][N];
ll w[N][2],t;
int main(){
	
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	int n1=0;
	for (int i=1;i<=n;i++){
		if (a[i]>0)a[++n1]=a[i];
	}
	n=n1;
	if (n>200){
		cout<<3<<endl;
		return 0;
	}
	for (ll k=1;k<=2e18;k<<=1){
		int cnt=0,s1=0,s2=0;
		for (int j=1;j<=n;j++){
			if (k&a[j]){
				cnt++;
				if (s1==0)s1=j;
				else s2=j;
			}
		}
		if (cnt>=3){
			cout<<3<<endl;
			return 0;
		}
		else {
			if (cnt==2){
				w[++t][0]=s1;
				w[t][1]=s2;
			}
		}
	}
	int ans=n+1;
	for (int d=1;d<=t;d++){
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)f[i][j]=1e7;
		for (int i=1;i<=t;i++){
			if (w[i][0]!=w[d][0]||w[i][1]!=w[d][1]){
				f[w[i][0]][w[i][1]]=f[w[i][1]][w[i][0]]=1;
			}
		}
		for (int i=1;i<=n;i++)f[i][i]=0;
		for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		ans=min(ans,f[w[d][0]][w[d][1]]+1);
	}
	if (ans>n){
		ans=-1;
	}
	cout<<ans<<endl;
}