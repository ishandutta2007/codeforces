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

int n;
string s[55];
map<string, int> pnt,  df, sc;

struct t1{
	int idx, a, b, c;
}r[55];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	for(int i=0; i<n*(n-1)/2; i++){
		char buf[100];
		int a, b;
		scanf("%s %d:%d",buf, &a, &b);
		bool pt = 0;
		string b1, b2;
		for(int i=0; buf[i]; i++){
			if(buf[i] == '-'){
				pt = 1;
				continue;
			}
			if(pt) b2.push_back(buf[i]);
			else b1.push_back(buf[i]);
		}
		if(a < b){
			swap(a, b);
			swap(b1, b2);
		}
		if(a == b){
			pnt[b1] += 1;
			pnt[b2] += 1;
		}
		else{
			pnt[b1] += 3;
			pnt[b2] += 0;
		}
		df[b1] += a - b;
		df[b2] += b - a;
		sc[b1] += a;
		sc[b2] += b;
	}
	vector<t1> ret;
	for(int i=0; i<n; i++){
		ret.push_back({i, pnt[s[i]], df[s[i]], sc[s[i]]});
	}
	sort(ret.begin(), ret.end(), [&](const t1 &a, const t1 &b){
		return make_tuple(a.a, a.b, a.c) > make_tuple(b.a, b.b, b.c);
	});
	sort(ret.begin(), ret.begin() + n / 2, [&](const t1 &a, const t1 &b){
		return s[a.idx] < s[b.idx];
	});
	for(int i=0; i<n/2; i++){
		cout << s[ret[i].idx] << endl;
	}
}