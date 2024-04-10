#include "bits/stdc++.h"
using namespace std;

multiset<int> A;

bool has(int l, int r){
	auto lit = A.lower_bound(l);
	auto rit = A.upper_bound(r);
	return lit != rit;	
}

char buff[10];

int main(){
	A.insert(0);
	int n;
	scanf("%d", &n);
	while (n--){
		int x;
		scanf("%s%d", buff, &x);
		if (buff[0] == '+'){
			A.insert(x);
		} else if (buff[0] == '-'){
			A.erase(A.find(x));
		} else {
			int base = 0, sol = 0;
			for (int i=29; i>=0; i--){
				if (x & (1<<i)){
					// trazimo broj koji na ovom mestu ima nulu
					if (has(base, base + (1<<i) - 1)){
						// good
						sol += (1<<i);
					} else {
						// bad
						base += (1<<i);
					}
				} else {
					// trazimo broj koji na ovom mestu ima keca
					if (has(base + (1<<i), base + (1<<i) + (1<<i) - 1)){
						// good
						sol += (1<<i);
						base += (1<<i);
					} else {
						// bad
					}
				}
			}
			printf("%d\n", sol);
		}
	}	
	return 0;
}