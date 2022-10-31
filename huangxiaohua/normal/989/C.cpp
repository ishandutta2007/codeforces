#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,l,n,m,t,a[666666],mn,sb;
char f[66][66];

int main() {
	ios::sync_with_stdio(0);
	a[0]=6666;
	for(i='A';i<='D';i++){
		cin>>a[i];
		if(a[i]<a[mn])mn=i;
	}
	for(i=1;i<=50;i++)for(j=1;j<=50;j++){
		f[i][j]=mn;
	}
	for(i='A';i<='D';i++){
		if(i!=mn)sb=i;
	}
	
	if(a[mn]!=1)a[sb]--;
	
	for(i=3;i<=50;i+=3)for(j=3;j<=50;j+=3){
		if(a[mn]==1)break;
		a[mn]--;
		for(k=0;k<3;k++)for(l=0;l<3;l++){
			if(k==1&&l==1)continue;
			f[i-k][j-l]=sb;
		}
	}
	a[mn]=0;
	for(i=49;i>=1;i-=2)for(j=3;j<=49;j+=2){
		for(k='A';k<='D';k++){
			if(a[k]){
				f[i][j]=k;
				a[k]--;
				goto aaa;
			}
		}
		break;
		aaa:;
	}
	cout<<"50 50\n";
	for(i=1;i<=50;i++){
		cout<<f[i]+1<<'\n';
	}
}