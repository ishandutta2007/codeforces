#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,a[66];

bool chk(int x){
	memset(a,0,sizeof(a));
	while(x){
		if(a[x%10]){return 0;}
		a[x%10]=1;
		x/=10;
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++){
		if(chk(i)){
			cout<<i;return 0;
		}
	}
	cout<<-1;
}