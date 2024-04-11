#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int c1, c2;

int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x == 100) c1++;
		else c2++;
	}
	int p = c1 + c2 * 2;
	if(p % 2 == 0){
		for(int i=0; i<=c1; i++){
			for(int j=0; j<=c2; j++){
				if(2*i+4*j == p){
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
}