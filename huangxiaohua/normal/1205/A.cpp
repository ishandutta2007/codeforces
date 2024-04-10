#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[500500],it;

int main(){
	cin>>n;
	if(n&1){
		puts("YES");
		for(i=1;i<=n;i++){
			if(i&1){
				res[i]=it+2;
				res[i+n]=it+1;
			}
			else{
				res[i]=it+1;
				res[i+n]=it+2;
			}
			it+=2;
		}
		for(i=1;i<=n+n;i++){
			printf("%d ",res[i]);
		}
	}
	else{
		puts("NO");
	}
}