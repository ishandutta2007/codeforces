#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <chrono>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, a[1000005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",a+i);
	}
	int cnt0 = 0, cnt1 = 0;
	lint ret = 0;
	for(int i=0; i<n; i++){
		if(a[i] == 0){
			ret += cnt1;
		}
		else{
			cnt1++;
		}
	}
	cout << ret;
}