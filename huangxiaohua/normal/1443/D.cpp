#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,a[30050],tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		tmp=a[1];a[1]=0;
		for(i=2;i<=n;i++){
			tmp=min(tmp,a[i]-a[i-1]);
			tmp=max(tmp,0);a[i]-=tmp;
			if(a[i]<a[i-1]){puts("NO");goto aaa;
			}
		}
		puts("YES");aaa:;
	}
}