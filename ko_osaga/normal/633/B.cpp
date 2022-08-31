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

int cnt2[500005], cnt5[500005];

int m;

int main(){
	cin >> m;
	for(int i=1; i<500005; i++){
		cnt2[i] = cnt2[i-1];
		cnt5[i]= cnt5[i-1];
		for(int j=i; j%2 == 0; j/=2){
			if(j%2 == 0) cnt2[i]++;
		}
		for(int j=i; j%5 == 0; j/=5){
			if(j%5 == 0) cnt5[i]++;
		}
	}
	vector<int> v;
	for(int i=1; i<500005; i++){
		if(min(cnt2[i], cnt5[i]) == m){
			v.push_back(i);
		}
	}
	cout << v.size() << endl;
	for(auto &i : v){
		cout << i << " ";
	}
}