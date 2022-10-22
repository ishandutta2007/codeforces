#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100009];
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		puts("YES");
		return;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==1){
			for(int j=1;j<=n;++j){
				if(j>1&&a[j]-a[j-1]==1){
					puts("NO");
					return;
				}
			}
		}
	}
	puts("YES");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}