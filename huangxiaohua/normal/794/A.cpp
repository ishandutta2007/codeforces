#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,c;

int main() {
	ios::sync_with_stdio(0);
	cin>>a>>b>>c;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j;
		if(j>b&&j<c)k++;
	}cout<<k;
}