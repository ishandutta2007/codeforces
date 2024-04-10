#include <bits/stdc++.h>

int main(){
	long long int n;
	long long int s, a, b, c;
	scanf("%lld", &n);
	
	long long int i, j, k, cnt=0, choco = 0;
	for (i=0;i<n;i++){
		cnt = 0;
		
		scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
		
		cnt += s/c;
		cnt += b * ((s/c)/a);
		s = s%c;
		
		
		
		printf("%lld\n", cnt);
	}
	
}