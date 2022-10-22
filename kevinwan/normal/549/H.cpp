#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld a, b, c, d,aad=1e300,bad=-1e300,abc=1e300,bbc=-1e300;
bool solve(ld x) {
	aad = min(min(min((a - x)*(d - x), (a + x)*(d + x)), (a + x)*(d - x)), (a - x)*(d + x));
	bad = max(max(max((a - x)*(d - x), (a + x)*(d + x)), (a + x)*(d - x)), (a - x)*(d + x));
	abc = min(min(min((b - x)*(c - x), (b + x)*(c + x)), (b + x)*(c - x)), (b - x)*(c + x));
	bbc = max(max(max((b - x)*(c - x), (b + x)*(c + x)), (b + x)*(c - x)), (b - x)*(c + x));
	return (aad <= abc && abc <= bad) || (aad <= bbc && bbc <= bad)||(abc<=aad&&aad<=bbc)||(abc<=bad&&bad<=bbc);
}
int main() {
	scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
	ld cur = 0;
	for (ld i = 1e200; i >= 1e-200; i /= 2) {
		if (!solve(cur + i))cur += i;
	}
	printf("%.15Lf", cur);
	for(int i=1;i<=1e7;i++)printf("%d",rand()%10);
}