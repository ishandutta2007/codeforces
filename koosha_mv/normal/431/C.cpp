#include<bits/stdc++.h>
using namespace std;
long long n,d,k,a[101][2],e=1e9+7;
int main(){
	cin>>n>>k>>d;
	a[0][0]=1;
	for (long long i=1;i<=n;i++)
		for (long long j=1;j<=min(k,i);j++)
			if (j>=d)a[i][1]=(a[i][1]+a[i-j][0]+a[i-j][1])%e;
			else a[i][0]=(a[i][0]+a[i-j][0])%e,a[i][1]=(a[i][1]+a[i-j][1])%e;
	cout<<(a[n][1])%e<<endl;
}