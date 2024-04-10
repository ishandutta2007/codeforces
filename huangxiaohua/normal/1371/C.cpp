#include<bits/stdc++.h>
using namespace std;

unsigned long long int t,i,a,b,n,m;

int main(){
	scanf("%llu",&t);
	while(t--){
		scanf("%llu%llu%llu%llu",&a,&b,&n,&m);
		if(a<b){swap(a,b);}
		if(b<m){puts("nO");continue;}
		if(a+b<n+m){puts("nO");continue;}
		puts("yES");
	}
}