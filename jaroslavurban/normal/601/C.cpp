#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=110,M=1010;
ld dp[N*M],pref[N*M]; //exclusive
int a[N];
int n,m;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	if(m==1){cout<<1<<endl;return 0;}
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=1;i<N*M;++i)pref[i]=m-1;
	dp[0]=m-1;
	for(int i=0;i<n;++i){
		for(int j=N*M-1;j>=0;--j)
			dp[j]=(pref[j]-pref[max(0,j-m)]-(j-a[i]>=0?dp[j-a[i]]:0))/(m-1);
		for(int j=1;j<N*M;++j)pref[j]=dp[j-1]+pref[j-1];
	}
	for(int i=1;i<n;++i)a[i]+=a[i-1];
	cout<<fixed<<setprecision(10)<<1+pref[a[n-1]]<<endl;
}