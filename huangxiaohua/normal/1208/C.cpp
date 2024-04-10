#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it;
int a[1050][1050];

void get(int x,int y){
	int i,j;
	for(i=x;i<=x+3;i++){
		for(j=y;j<=y+3;j++){
			a[i][j]=it;it++;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i+=4){
		for(j=1;j<=n;j+=4){
			get(i,j);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
}