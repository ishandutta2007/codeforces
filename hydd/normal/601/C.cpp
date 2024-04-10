#include<bits/stdc++.h>
using namespace std;
typedef long double ldb;
int n,m,x[110];
ldb f[110000],s[110000];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m; int sum=0;
	for (int i=1;i<=n;i++){
		cin>>x[i];
		sum+=x[i];
	}
	if (m==1){
		puts("1.000000000000");
		return 0;
	}
	for (int j=1;j<=m;j++)
		if (j!=x[1]) f[j]=1;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=i*m;j++){
			s[j]=s[j-1]+f[j];
			if (j<=m+1){//f[k]->f'[j] j-k
				if (x[i]<j) f[j]=s[j-1]-(s[j-x[i]]-s[j-x[i]-1]);
				else f[j]=s[j-1];
			} else
				f[j]=s[j-1]-s[j-m-1]-(s[j-x[i]]-s[j-x[i]-1]);
			f[j]/=(m-1);
		}
	}
	ldb ans=0;
	for (int i=1;i<sum;i++) ans+=f[i];
	printf("%.12lf\n",(double)ans+1);
	return 0;
}