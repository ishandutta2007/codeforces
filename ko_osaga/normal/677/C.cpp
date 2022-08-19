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

int p;

int proc(char t){
	if(t == '-') return 62;
	if(t == '_') return 63;
	if(t <= '9' && t >= '0') return t - '0';
	if(t <= 'Z' && t >= 'A') return t - 'A' + 10;
	if(t <= 'z' && t >= 'a') return t - 'a' + 36;
}

char str[100005];
int pp[100005];
int ok[64];

int main(){
	cin >> str;
	for(int i=0; str[i]; i++){
		pp[i] = proc(str[i]);
	}
	for(int i=0; i<64; i++){
		for(int j=0; j<64; j++){
			for(int k=0; k<64; k++){
				if((j & k) == i){
					ok[i]++;
				}
			}
		}
	}
	lint ret = 1;
	for(int i=0; str[i]; i++){
		ret *= ok[pp[i]];
		ret %= 1000000007;
	}
	cout << ret;
}