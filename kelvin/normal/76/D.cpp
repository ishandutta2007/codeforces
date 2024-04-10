#include <iostream>

using namespace std;

unsigned long long s,x;
unsigned long long tp[64];

inline bool solve() {
	int i;
	unsigned long long a=0,rem=s;
	for(i=0;i<64;i++)
		if(x&tp[i]) rem-=tp[i];
	if(rem&1) return 0;
	rem>>=1;
	for(i=0;i<64;i++) {
		if(x&tp[i]) {
			if(rem&tp[i]) return 0;
			continue;
		}
		if(rem&tp[i]) a|=tp[i];
	}
	cout << a << " " << s-a << endl;
	return 1;
}

int main(void)
{
	int i;
	for(i=0;i<64;i++)
		tp[i]=(unsigned long long)1<<i;
	while(cin>>s>>x) {
		if(!solve()) cout << -1 << endl;
	}
}