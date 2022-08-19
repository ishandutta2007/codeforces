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

int a, b; string s, t;

lint nxt[105][32];

int main(){
	cin >> a >> b >> s >> t;
	for(auto &i : t){
		if(find(s.begin(), s.end(), i) == s.end()){
			cout << 0;
			return 0;
		}
	}
	for(int i=0; i<s.size(); i++){
		int cnt = 0, pos = i;
		for(auto &j : t){
			while(j != s[pos]){
				pos = (pos + 1) % s.size();
				cnt++;
			}
			pos = (pos + 1) % s.size();
			cnt++;
		}
		nxt[i][0] = cnt;
	}
	for(int i=1; i<32; i++){
		for(int j=0; j<s.size(); j++){
			nxt[j][i] = nxt[j][i-1] + nxt[(j + nxt[j][i-1]) % s.size()][i-1];
		}
	}
	int ret = 0;
	for(int i=0; i<s.size(); i++){
		int l = a * s.size() - i; // this way forward
		int cnt = 0, p = i;
		for(int j=31; j>=0; j--){
			if(nxt[p][j] <= l){
				cnt += (1<<j);
				l -= nxt[p][j];
				p = (p + nxt[p][j]) % s.size();
			}
		}
		ret = max(ret, cnt / b);
	}
	cout << ret;
}