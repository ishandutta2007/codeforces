#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,n,t,j,k,res,a,b,c,d;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		if((a+b+c)%9){puts("NO");continue;}
		d=(a+b+c)/9;
		if(a<d||b<d||c<d){puts("NO");continue;}
		puts("YES");
	}
}