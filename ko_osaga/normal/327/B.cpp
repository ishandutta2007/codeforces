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
const int mod = 1e9 + 7;

bool isprime(int x){
	for(int i=2; i*i<=x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	for(int i=2; n; i++){
		if(isprime(i)){
			printf("%d ",i);
			n--;
		}
	}
}