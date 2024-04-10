#include<bits/stdc++.h>
using namespace std;
 
const int N = 1000005, Z = (1<<21) + 5;
 
int n, a[N], c[Z];
 
void upd (int I, int J) {
	if(c[I] == 2) return;
	c[I]++;
	for(;J;J/=2) {
		if(J&I) upd(I-J, J/2);
	}
}
 
bool can (int X) {
	for(int i=0;i<Z;i++) c[i] = 0;
	for(int i=n;i>=1;i--) {
		if(c[(~a[i])&X] == 2) return true;
		upd(a[i], (1<<20));
	}
	return false;
}
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int C = 0;
	for(int i=(1<<20);i>=1;i/=2) {
		if(can(C+i)) C += i;
	}
	printf("%d\n", C);
}