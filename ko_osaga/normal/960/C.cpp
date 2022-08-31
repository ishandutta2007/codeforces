#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
const int MAXN = 100005;

vector<lint> tmp;

int main(){
	int x, d;
	cin >> x >> d;
	d += 1000;
	int it = 0;
	for(int i=30; i>0; i--){
		while(x >= (1ll << i) - 1){
			x -= (1ll << i) - 1;
			it++;
			for(int j=0; j<i; j++) tmp.push_back(1ll * d * it);
		}
	}
	cout << tmp.size() << endl;
	for(auto &i : tmp) cout << i << " ";
}