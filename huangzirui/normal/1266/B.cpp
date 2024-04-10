#include<bits/stdc++.h>
using namespace std;
int i,j,k,n;long long m;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&m);
		if(m<15)puts("NO");
		else{
			m%=14;
			if(m>0 && m<7)puts("YES");
			else puts("NO");
		}
	}
}