#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int a, b, c, d, e, f;

int main(){
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	if(a > c) swap(a,c);
	if(d > f) swap(d,f);
	int ret = (b + a) * (b + a) - b * b;
	ret += (e + d) * (e + d) - e * e;
	ret += (c - a) * 2 * (b + a);
	printf("%d",ret);
}