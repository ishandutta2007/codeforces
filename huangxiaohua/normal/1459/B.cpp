#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
	scanf("%d",&n);
	if(n%2){
		printf("%d",(n/2+1)*(n/2+2)*2);
	}
	else{
		printf("%d",(n/2+1)*(n/2+1));
	}
}