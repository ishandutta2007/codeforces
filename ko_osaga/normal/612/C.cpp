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

bool opener(char t){
	return t == '<' || t == '{' || t == '[' || t == '(';
}

bool match(char t, char u){
	return (t == '<' && u == '>') || (t == '{' && u == '}') || (t == '[' && u == ']') || (t == '(' && u == ')'); 
}

string s;

int main(){
	int ret = 0;
	cin >> s;
	stack<char> stk;
	for(auto &i : s){
		if(opener(i)){
			stk.push(i);
		}
		else{
			if(stk.empty()){
				cout << "Impossible";
				return 0;
			}
			if(!match(stk.top(), i)) ret++;
			stk.pop();
		}
	}
	if(stk.size()){
		cout << "Impossible";
		return 0;
	}
	cout << ret;
}