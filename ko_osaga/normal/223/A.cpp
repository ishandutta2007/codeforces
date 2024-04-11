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

int match[100005];
char str[100005];
int cnt[100005];

bool chk(char a, char b){
	return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int sum(int s, int e){
	return cnt[e] - (s ? cnt[s-1] : 0);
}

int main(){
	memset(match, -1, sizeof(match));
	cin >> str;
	stack<int> stk;
	for(int i=0; str[i]; i++){
		cnt[i] = (i ? cnt[i-1] : 0) + (str[i] == '[');
		if(!stk.empty() && chk(str[stk.top()], str[i])){
			match[i] = stk.top();
			if(match[i] && ~match[match[i]-1]){
				match[i] = match[match[i] - 1];
			}
			stk.pop();
		}
		else stk.push(i);
	}
	int ret = 0; pi opt(1, 0);
	for(int i=0; str[i]; i++){
		if(~match[i] && sum(match[i], i) >= ret){
			ret = sum(match[i], i);
			opt = pi(match[i], i);
		}
	}
	printf("%d\n",ret);
	for(int i=opt.first; i<=opt.second; i++) putchar(str[i]);
}