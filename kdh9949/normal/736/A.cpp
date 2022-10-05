#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[100010];
ll n;

int main(){
	scanf("%lld", &n);
	d[1] = 2;
	d[2] = 3;
	for(int i = 1; i <= 100000; i++){
		if(i >= 3) d[i] = d[i - 1] + d[i - 2];
		if(d[i] > n){
			printf("%d\n", i - 1);
			break;
		}
	}
	return 0;
}