#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;

lint gcd(lint a, lint b){
	return b ? gcd(b, a%b) : a;
}

lint lcm(lint a, lint b){
	return a * (b / gcd(a, b));
}
int main(){
	cin >> n;
	lint ret = 0;
	if(n == 1){
		cout << 1;
		return 0;
	}
	if(n == 2){
		cout << 2;
		return 0;
	}
	for(int i=max(1, n-5); i<=n; i++){
		for(int j=i+1; j<=n; j++){
			for(int k=j+1; k<=n; k++){
				ret = max(ret, lcm(lcm(i, j), k));
			}
		}
	}
	cout << ret;
}