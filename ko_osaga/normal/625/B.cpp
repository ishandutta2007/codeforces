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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

string s1, s2;
vector<int> v;

int main(){
	cin >> s1 >> s2;
	for(int i=0; i<=(int)s1.size()-(int)s2.size(); i++){
		bool bad = 0;
		for(int j=0; j<s2.size(); j++){
			if(s1[i+j] != s2[j]){
				bad = 1;
				break;
			}
		}
		if(!bad) v.push_back(i);
	}
	int l = s2.size(), cnt = 0;
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[e] - v[i] < l) e++;
		i = e;
		cnt++;
	}
	cout << cnt;
}