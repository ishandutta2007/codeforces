#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200009];
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int p=lower_bound(a+1,a+n+1,a[i]+k)-a;
		if(p<=n&&p>=1&&a[p]-a[i]==k){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}