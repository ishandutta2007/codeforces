#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000100;
vector<int>a[N];
int n,m;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)a[i].resize(m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>a[i][j];
	for(int i=0;i<n/2;++i)
		for(int j=0;j<m;++j)
			cout<<i+1<<" "<<j+1<<'\n'<<n-i<<" "<<m-j<<'\n';
	if(n%2){
		for(int i=0;i<m/2;++i)cout<<n/2+1<<" "<<i+1<<'\n'<<n/2+1<<" "<<m-i<<'\n';
		if(m%2)cout<<n/2+1<<" "<<m/2+1<<endl;
	}
}