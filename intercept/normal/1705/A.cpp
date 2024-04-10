#include<bits/stdc++.h>
using namespace std;
int a[1009];
int n,x;
void work(){
	cin>>n>>x;
	n*=2;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;++i){
		if(a[i+n/2]-a[i]<x){
			puts("NO");
			return;
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