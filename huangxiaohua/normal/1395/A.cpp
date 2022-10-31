#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,t,a,b,c,d;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a%2+b%2+c%2+d%2<=1){puts("Yes");continue;}
		if(a%2+b%2+c%2+d%2>=3&&a>0&&b>0&&c>0){puts("Yes");continue;}
		puts("No");
	}
}