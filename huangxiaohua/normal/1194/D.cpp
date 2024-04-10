#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n,i,j,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if((k%3)==0){
			n%=(k+1);
			if(n==k||n%3){puts("Alice");}
			else{puts("Bob");}
		}
		else{
			if(n%3){puts("Alice");}
			else{puts("Bob");}
		}
	}
}