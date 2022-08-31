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
const int mod = 1e9 + 7;

set<string> ls;

void bktk(string s){
	if(ls.find(s) != ls.end()) return;
	ls.insert(s);
	if(s[0] == 'X'){
		for(int i=1; i<=2; i++){
			swap(s[0], s[i]);
			bktk(s);
			swap(s[0], s[i]);
		}
	}
	if(s[3] == 'X'){
		for(int i=1; i<=2; i++){
			swap(s[3], s[i]);
			bktk(s);
			swap(s[3], s[i]);
		}
	}
	if(s[2] == 'X'){
		for(int i=0; i<=3; i+=3){
			swap(s[2], s[i]);
			bktk(s);
			swap(s[2], s[i]);
		}
	}
	if(s[1] == 'X'){
		for(int i=0; i<=3; i+=3){
			swap(s[1], s[i]);
			bktk(s);
			swap(s[1], s[i]);
		}
	}
}

int main(){
	string b1, b2, b3, b4;
	cin >> b1 >> b2 >> b3 >> b4;
	string r1 = b1 + b2, r2 = b3 + b4;
	bktk(r1);
	if(ls.find(r2) != ls.end()) cout << "YES";
	else cout <<"NO";
}