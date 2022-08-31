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

vector<int> v;

int main(){
	for(int i=2; i<=50; i++){
		bool ok = 0;
		for(int j=2; j<i; j++){
			if(i%j == 0) ok = 1;
		}
		if(!ok) v.push_back(i);
	}
	v.push_back(4);
	v.push_back(9);
	v.push_back(25);
	v.push_back(49);
	assert(v.size() <= 20);
	int cnt = 0;
	for(auto &i : v){
		printf("%d\n",i);
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "yes"){
			cnt++;
		}
	}
	if(cnt <= 1){
		// check if the number is that. 
		// the number is either that, or a multiple of that

		cout << "prime" << endl;
		fflush(stdout);
		return 0;
}
	cout << "composite" << endl;
	fflush(stdout);
	return 0;
}