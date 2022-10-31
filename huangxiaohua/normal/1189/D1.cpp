#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[114514];

int main(){
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;a[j]++;a[k]++;
	}
	for(i=1;i<=n;i++){
		if(a[i]==2)return puts("NO"),0;
	}
	cout<<"YES";
}