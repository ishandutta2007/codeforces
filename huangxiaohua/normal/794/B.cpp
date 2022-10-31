#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main() {
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<n;i++){
		printf("%.20lf ",sqrt(1.0*m*m/n*i) );
	}
}