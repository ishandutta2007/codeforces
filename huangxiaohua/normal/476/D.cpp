#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k;

int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",(6*n-1)*k);
	for(i=0;i<n;i++){
		printf("%d %d %d %d\n",(i*6+1)*k,(i*6+2)*k,(i*6+3)*k,(i*6+5)*k);
	}
}