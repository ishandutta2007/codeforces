#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105000],b[105000];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		for(i=1;i<=n;i++){
			if(b[a[i]]==1){printf("%d\n",i);break;}
		}
	}
}