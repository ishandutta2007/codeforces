#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[110000],lst[110000];
int main(){
	scanf("%d",&n); int x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x!=a[cnt]) a[++cnt]=x;
	}
	int ans=cnt,pos=0;
	for (int i=1;i<=cnt;i++){
		if (lst[a[i]]&&lst[a[i]]>=pos-1){
			pos=i;
			ans--;
		}
		lst[a[i]]=i;
	}
	printf("%d\n",ans);
	return 0;
}