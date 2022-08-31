#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int main(){
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		int good = 0, cnt = 0;
		for(int i=x; i; i>>=1){
			if(i % 2 == 0) good = 1;
			cnt++;
		}
		if(good){
			cout << (1<<cnt) - 1 << endl;
		}
		else{
			int ret = 0;
			for(int i=1; i*i<=x; i++){
				if(x % i == 0){
					ret = max(ret, i);
					if(i > 1) ret = max(ret, x / i);
				}
			}
			printf("%d\n", ret);
		}
	}
}