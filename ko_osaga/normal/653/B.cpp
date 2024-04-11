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

int n, q;
string a[60], b[60];

set<string> st;

void bktk(string s){
	if(st.find(s) != st.end()) return;
	st.insert(s);
	if(s.size() == n) return;
	for(int i=0; i<1; i++){
		for(int j=0; j<q; j++){
			if(b[j][0] == s[i]){
				bktk(s.substr(0, i) + a[j] + s.substr(i+1, s.size()-i-1));
			}
		}
	}
}

int main(){
	cin >> n >> q;
	for(int i=0; i<q; i++) cin >> a[i] >> b[i];
	bktk("a");
	int cnt = 0;
	for(auto &i : st){
		if(i.size() == n) cnt++;
	}
	cout << cnt;
}