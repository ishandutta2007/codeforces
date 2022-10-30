#include <bits/stdc++.h>
using namespace std;

int i,j,k,t,n,m,a[105][105];
int it,op[10050][105];

void work(int x,int y){
	it++;int i;
	while(1){
		for(i=1;i<=n;i++)if(a[x][i]>1){
			op[it][x]=i;a[x][i]--;a[(x%n)+1][i]++;break;
		}
		x=(x%n)+1;if(x==y)break;
	}
}

bool fuck(){
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]>1){
		work(i,i);return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){cin>>k;a[i][k]++;}
	while(fuck());
	cout<<it+(n*n-n)/2<<'\n';
	for(i=1;i<=it;i++){
		for(j=1;j<=n;j++)cout<<op[i][j]<<' ';
		cout<<'\n';
	}
	for(i=2;i<=n;i++)for(j=i;j>=2;j--){
		t=j;for(k=1;k<=n;k++){cout<<t<<' ';t=(t%n)+1;}cout<<'\n';
	}
}