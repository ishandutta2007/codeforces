#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

inline long long t10(long long x) {
	long long t=1;
	while(x) {
		x/=10;
		t*=10;
	}
	return t;
}
inline long long ref(long long x) {
	return t10(x)-1-x;
}
inline long long wt(long long x) {
	return x*ref(x);
}

inline void relax(long long &x, long long val) { if(val>x) x=val; }
inline bool between(long long x,long long l,long long r) {
	return x>=l&&x<=r;
}

int main(void)
{
	long long l,r,m,x;
	long long sol;
	while(cin>>l>>r) {
		if(r==1000000000) {
			//     123456789123456789
			puts("8999999999000000000");
			continue;
		}
		sol=0;
		relax(sol,wt(l));
		relax(sol,wt(r));
		for(m=1;m<=r;m*=10) {
			x=m*10/2;
			if(between(x,l,r)) relax(sol,wt(x));
			x=m*10/2-1;
			if(between(x,l,r)) relax(sol,wt(x));
		}
		cout << sol << endl;
	}
}