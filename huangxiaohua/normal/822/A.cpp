#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll sb=1;

int main(){
	cin>>n>>m;
	for(i=1;i<=min(n,m);i++){
		sb*=i;
	}
	cout<<sb;
}