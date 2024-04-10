#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n,m,sb;

int main(){
	cin>>n>>m;
	if(m==1){
		cout<<n;return 0;
	}
	sb=1;
	while(sb<=n)sb<<=1;
	cout<<sb-1;
}