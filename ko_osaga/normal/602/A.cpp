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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n1, b1, n2, b2;
lint p1, p2;

int main(){
	cin >> n1 >> b1;
	for(int i=0; i<n1; i++){
		int t;
		cin >> t;
		p1 = p1 * b1 + t;
	}
	cin >> n2 >> b2;
	for(int i=0; i<n2; i++){
		int t;
		cin >> t;
		p2 = p2 * b2 + t;
	}
	if(p1 < p2) cout << "<";
	else if(p1 == p2) cout << "=";
	else cout << ">";
}