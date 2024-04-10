#include<bits/stdc++.h>
typedef long long ll;
ll a,b,r;
void process(void) {
	scanf("%I64d",&a);
	scanf("%I64d",&b);
	r=0LL;
	while (true) {
		if (a%b==0) {
			r=r+a/b;
			break;
		}
		if (b%a==0) {
			r=r+b/a;
			break;
		}
		if (a>b) {
			r=r+a/b;
			a=a%b;
			continue;
		}
		if (b>a) {
			r=r+b/a;
			b=b%a;
			continue;
		}
	}
	printf("%I64d",r);
}
int main(void) {
	process();
	return 0;
}