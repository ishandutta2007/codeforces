#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int n;
	cin >> n;
	if(n % 4 >= 2){
		cout << "NO";
		return 0;
	}
	puts("YES");
	auto go = [&](int x, int y){
		printf("%d %d\n", x, y);
	};
	for(int i=1; i+3<=n; i+=4){
		if(n & 1) go(i, n);
		go(i, i+1);
		if(n & 1) go(i+1, n);
		if(n & 1) go(i+2, n);
		go(i+2, i+3);
		if(n & 1) go(i+3, n);
		go(i, i+2);
		go(i+1, i+3);
		go(i, i+3);
		go(i+1, i+2);
	}
	for(int i=1; i+3<=n; i+=4){
		for(int j=i+4; j+3<=n; j+=4){
			for(int k=0; k<4; k+=2){
				for(int l=0; l<4; l+=2){
					go(i+k, j+l);
					go(i+k+1, j+l+1);
					go(i+k, j+l+1);
					go(i+k+1, j+l);
				}
			}
		}
	}
}