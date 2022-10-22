#include <bits/stdc++.h>
#define mod(a,b) (a>=0?(a%b):(b-a%b))
using namespace std;
typedef long long ll;
int a[100000],b[100001];
bool w[100000];
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i),b[a[i]]=i;
	for (i = n; i; i--) {
		int x = b[i];
		for (j = x % i; j < n; j += i)if (a[j] > a[x])w[x] |= (!w[j]);
	}
	for (i = 0; i < n; i++)printf("%c", w[i] ? 'A' : 'B');
	getchar(); getchar();
}