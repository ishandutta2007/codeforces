#include <bits/stdc++.h>
#define mod(a,b) (a>=0?(a%b):(b-a%b))
using namespace std;
typedef long long ll;
int a, b, c, d, e, f;
int main() {
	int n;
	scanf("%d", &n);
	scanf("%d%d%d%d%d%d", &c, &d, &a, &b, &e, &f);
	int q1[2], q2[2];
	q1[0] = (a > c);
	q1[1] = (b > d);
	q2[0] = (e > c);
	q2[1] = (f > d);
	if (q1[0] == q2[0] && q1[1] == q2[1])printf("YES");
	else printf("NO");
	getchar(); getchar();
}