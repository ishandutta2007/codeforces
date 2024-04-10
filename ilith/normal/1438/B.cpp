#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]){
			puts("YES");goto tag;}
		}
		puts("NO");
		tag:; 
	}
	return 0;
}