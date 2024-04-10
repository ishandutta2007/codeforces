#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int chk(int x,int y){
	int k=0,i=0;
	while(x||y){
		i++;
		if((x%m)!=(y%m))k=i;
		x/=m;y/=m;
	}
	return k;
}

int main() {
	cin>>n>>m;
	for(i=1;i<n;i*=m,j++){}
	cout<<j<<endl;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			printf("%d ",chk(i,j));
		}
	}
}