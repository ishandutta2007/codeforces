#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
int i, j, k;
int arr[100000];
char str[100000];

int main(){
	scanf("%lld %lld", &n, &m);
	
	printf("YES\n");
	
	ll b;
	for (b=n;b<=m;b+=2){
		printf("%lld %lld\n", b, b+1);
	}
}