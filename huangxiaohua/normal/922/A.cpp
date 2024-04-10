#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,k;
ll n,m,res;

int main(){
	cin>>m>>n;n--;
	if(n<0||m<0){
		puts("No");return 0;
	}
	if(!n&&m){
		puts("No");return 0;
	}
	if(m<n){
		puts("No");return 0;
	}
	if((m-n)&1){
		puts("No");return 0;
	}
	puts("Yes");
}