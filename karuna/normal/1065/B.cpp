#include <bits/stdc++.h>

int main(){
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	
	int min, max;
	if ((n+1)/2 > m) min = n - 2*m ;
	else min = 0;
	
	long long int i;
	for (i=0;i<n;i++){
		if (m==0) max = n;
		else if (m>i*(i+1)/2 && m<=(i+1)*(i+2)/2){
			max = n-i-2;
		}
	}
	
	printf("%d %d", min, max);
	
}