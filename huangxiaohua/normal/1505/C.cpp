#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,x,y,t;
char sb[666];

int main(){
	cin>>sb+1;
	n=strlen(sb+1);
	for(i=1;i<=n;i++){
		sb[i]-='A';
	}
	for(i=3;i<=n;i++){
		if(((sb[i-1]+sb[i-2])%26)!=(sb[i]%26)){puts("NO");return 0;}
	}puts("YES");
}