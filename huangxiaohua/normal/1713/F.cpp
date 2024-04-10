#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,a[500500],b[500500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(i=1;i<=20;i++){
		for(j=0;j<n;j++){
			if(b(i)&j){
				a[j]^=a[j^b(i)];
			}
		}
	}
	for(i=1;i<=20;i++){
		for(j=0;j<n;j++){
			if(b(i)&j){
				a[j^b(i)]^=a[j];
			}
		}
	}
	for(i=n-1;i>=0;i--){
		cout<<a[i]<<' ';
	}
}