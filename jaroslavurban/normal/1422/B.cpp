#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=110;
int n,m;
int a[N][N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>m;
		ll res=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)cin>>a[i][j];
		for(int i=0;i<n/2;++i)
			for(int j=0;j<m/2;++j){
				int b[4];b[0]=a[i][j];
				b[1]=a[n-i-1][j];
				b[2]=a[i][m-j-1];
				b[3]=a[n-i-1][m-j-1];
				sort(b,b+4);
				for(int k=0;k<4;++k)res+=abs(b[1]-b[k]);
			}
		if(n%2)for(int i=0;i<m/2;++i)res+=abs(a[n/2][i]-a[n/2][m-i-1]);
		if(m%2)for(int i=0;i<n/2;++i)res+=abs(a[i][m/2]-a[n-i-1][m/2]);
		cout<<res<<endl;
	}
}