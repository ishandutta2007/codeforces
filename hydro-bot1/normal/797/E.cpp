// Hydro submission #621c621ccdb5d839880b81e3@1646027292778
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],f[N][400],Q;
int work(int x,int k){return x>n?0:work(x+a[x]+k,k)+1;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int S=sqrt(n);
	for(int i=n;i>=1;i--)
		for(int j=1;j<=S;j++){
			if(i+a[i]+j>n)f[i][j]=1;
			else f[i][j]=f[i+a[i]+j][j]+1;
		}
	scanf("%d",&Q);
	while(Q--){
		int x,k;
		scanf("%d%d",&x,&k);
		if(k>S)printf("%d\n",work(x,k));
		else printf("%d\n",f[x][k]);
	}
}