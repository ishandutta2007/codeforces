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

int g(int x, int y){
	return y ? g(y, x%y) : x;
}

int cnt = 0;
int main(){
	int n, a[1005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n-1; i++){
		if(g(a[i], a[i+1]) != 1) cnt++;
	}
	cout << cnt << endl;
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
		if(i != n-1 && g(a[i], a[i+1]) != 1){
			printf("1 ");
		}
	}
}