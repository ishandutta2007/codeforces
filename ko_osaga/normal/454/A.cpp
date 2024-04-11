#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(abs(i - n/2) + abs(j - n/2) <= n/2) putchar('D');
			else putchar('*');
		}
		puts("");
	}
}