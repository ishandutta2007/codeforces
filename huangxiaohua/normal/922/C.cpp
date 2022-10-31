#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n,m;

int main(){
	cin>>n>>m;
	if(m>=5000){
		puts("No");return 0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			if(i!=j&&((n%i)==(n%j))){
				puts("No");return 0;
			}
		}
	}
	puts("Yes");
}