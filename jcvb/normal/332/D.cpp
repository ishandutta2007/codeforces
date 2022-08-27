#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long double db;
typedef long long ll;

int s[2005][2005];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		s[i][i]=-1;
		for (int j=i+1;j<=n;j++){
			int x;scanf("%d",&x);
			s[i][j]=s[j][i]=x;
		}
	}
	db ans=0.0;
	for (int i=1;i<=n;i++){
		ll su=0;
		int deg=0;
		for (int j=1;j<=n;j++)if(~s[i][j]){
			deg++;
			su+=s[i][j];
		}
		db x=su*1.0*k/n;
		for (int t=1;t<=k-1;t++)
			x=x*(deg-t)/(n-t);
		ans+=x;
	}
	ll tmp=ans+1e-4;
	cout<<tmp<<endl;
	return 0;
}