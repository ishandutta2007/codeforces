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

int cnt[10], chk[10];

string s;

int main(){
	cin >> s;
	for(int i=0; i<s.size(); i++){
		cnt[s[i] - '0']++;
	}
	s.clear();
	cnt[1]--, cnt[6]--, cnt[8]--, cnt[9]--;
	for(int i=1; i<=9; i++){
		for(int j=0; j<cnt[i]; j++) s.push_back('0'+i);
	}
	int ret = 0;
	for(int i=0; i<s.size(); i++){
		ret = ret * 10 + s[i] - '0';
		ret %= 7;
	}
	ret *= 10000;
	ret %= 7;
	int perm[4] = {1, 6, 8, 9};
	do{
		if((perm[0] *1000 + perm[1] * 100 + perm[2] * 10+perm[3] + ret) % 7 == 0){
			break;
		}
	}while(next_permutation(perm, perm + 4));
	cout << s;
	for(int i=0; i<4; i++) printf("%d",perm[i]);
	for(int i=0; i<cnt[0]; i++) putchar('0');
}