#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int t, bc, bo, n, ans = 0;
int O[600000], C[600000], SC = 0;

int main() {
	cin >> n;
	memset(O, 0, sizeof(O));
	memset(C, 0, sizeof(C));
	getchar();
	while(n--) {
		bc = bo = 0;
		while((t=getchar()) != '\n') {
			if(t == '(')
				bo++;
			else if(bo)
				bo--;
			else
				bc++;
		}
		if(bo == 0 && bc == 0) {
			SC++;
		}else if(bo == 0) {
			if(O[bc])
				O[bc]--, ans++;
			else
				C[bc]++;
		}else if(bc == 0) {
			if(C[bo])
				C[bo]--, ans++;
			else
				O[bo]++;
		}
	}
	if(SC&1)
		SC--;
	ans += (SC>>1);
	cout << ans;
	return 0;
}