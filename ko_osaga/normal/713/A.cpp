#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int cnt[19][1<<19];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char t[5]; lint x;
		scanf("%s", t);
		if(*t == '+'){
			string x;
			cin >> x;
			reverse(x.begin(), x.end());
			while(x.size()&& x.back() % 2 == 0) x.pop_back();
			reverse(x.begin(), x.end());
			int v = 0;
			for(int i=0; i<x.size(); i++){
				v = 2 * v + (x[i] % 2);
			}
			cnt[x.size()][v]++;
		}
		if(*t == '-'){
			string x;
			cin >> x;
			reverse(x.begin(), x.end());
			while(x.size()&& x.back() % 2 == 0) x.pop_back();
			reverse(x.begin(), x.end());
			int v = 0;
			for(int i=0; i<x.size(); i++){
				v = 2 * v + (x[i] % 2);
			}
			cnt[x.size()][v]--;
		}
		if(*t == '?'){
			string x;
			cin >> x;
			int pat = 0;			reverse(x.begin(), x.end());
			while(x.size()&& x.back() % 2 == 0) x.pop_back();
			reverse(x.begin(), x.end());

			for(int i=0; i<x.size(); i++) pat = pat * 2 + (x[i] % 2);
			int ret = 0;
			for(int i=x.size(); i<=18; i++){
				ret += cnt[i][pat];
			}
			printf("%d\n", ret);
		}
	}
}