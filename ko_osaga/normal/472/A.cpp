#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int n;
	cin >> n;
	if(n%2 == 0) printf("%d 4\n", n-4);
	else printf("%d 9\n", n-9);
}