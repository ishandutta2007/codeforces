#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

unsigned long long a, b, p, q;

int main(){
	cin >> a >> b;
	if(a < b || (a&1) != (b&1)){
		puts("-1");
		return 0;
	}
	unsigned long long c = (a - b) >> 1;
	for(int i=0; i<64; i++){
		if((c >> i) & 1){
			if((b) & (1ull << i)){
				puts("-1");
				return 0;
			}
			p |= (1ull << i);
			q |= (1ull << i);
		}
		else{
			if((b) & (1ull << i)){
				q |= (1ull << i);
			}
		}
	}
	cout << p << " " << q;
}