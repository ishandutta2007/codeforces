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

struct pnt{int x, y, v;};
vector<pnt> a;
int n;
bool ok[805];
int mat[805];
int main(){
	cin >> n;
	n *= 2;
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			pnt t;
			cin >> t.v;
			t.x = i, t.y = j;
			a.push_back(t);
		}
	}
	sort(a.begin(), a.end(), [&](const pnt &a, const pnt &b){
		return a.v > b.v;
	});
	for(auto &i : a){
		if(!ok[i.x] && !ok[i.y]){
			mat[i.x] = i.y;
			mat[i.y] = i.x;
			ok[i.x] = ok[i.y] = 1;
		}
	}
	for(int i=1; i<=n; i++) printf("%d ",mat[i]);
}