#include <bits/stdc++.h>
using namespace std;
int n,m,T,p,a[100010],st[100010],t=0;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	t=0;
	for(int i=1;i<=n;i++) if(!t||a[st[t]]<a[i]) st[++t]=i;
	st[t+1]=n+1;
	for(int j=t;j>=1;j--){
		for(int i=st[j];i<st[j+1];i++) printf("%d ",a[i]);
	}
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--) solve();
}