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

vector<string> ret;
int ok[10];

void check(string s, int cp){
	int cur1 = 0, cur2 = 0, cur3 = 0;
	for(int i=1; i<=3 && i<cp; i++){
		cur1 = cur1 * 10 + (s[i-1] - '0');
		if(i != 1 && s[0] == '0') break;
		if(cur1 <= 255){
			cur2 = 0;
			for(int j=i+1; j<=i+3 && j<cp; j++){
				cur2 = cur2 * 10 + (s[j-1] - '0');
				if(j != i+1 && s[i] == '0') break;
				if(cur2 <= 255){
					cur3 = 0;
					for(int k=j+1; k<=j+3 && k<cp; k++){
						cur3 = cur3 * 10 + (s[k-1] - '0');
						if(k != j+1 && s[j] == '0') break;
						if(cur3 > 255) break;
						if(cp - k > 3) continue;
						int cur4 = 0;
						for(int l=k+1; l<=cp; l++){
							cur4 = cur4 * 10 + (s[l-1] - '0');
						}
						if(k+1 < cp && s[k] == '0') continue;
						if(cur4 <= 255){
							string tmp;
							for(int l=0; l<cp; l++){
								if(l == i || l == j || l == k){
									tmp.push_back('.');
								}
								tmp.push_back(s[l]);
							}
							ret.push_back(tmp);
						}
					}
				}
			}
		}
	}
}

void bktk(string &s, int cp){
	if(cp >= 2){
		string r = s;
		reverse(r.begin(), r.end());
		string t;
		check(s + r, cp * 2);
		if(cp == 6) return;
		for(int i=0; i<10; i++){
		if(!ok[i]) continue;
			s.push_back(i + '0');
			check(s + r, cp * 2 + 1);
			s.pop_back();
		}
	}
	for(int i=0; i<10; i++){
		if(!ok[i]) continue;
		s.push_back(i + '0');
		bktk(s, cp+1);
		s.pop_back();
	}
}
/*
29.95.59.92
29.95.059.92
29.95.159.92
29.96.69.92
29.96.069.92
29.96.169.92
29.97.79.92
29.97.079.92
29.97.179.92
29.98.89.92
29.98.089.92
29.98.189.92
29.99.99.92
29.99.099.92
29.99.199.92

*/

int main(){
	int n; cin >> n;
	while(n--){
		int u; cin >> u;
		ok[u] = 1;
	}
	string t = "";
	bktk(t, 0);
	vector<string> real;
	for(auto &i : ret){
		bool bad = 0;
		for(int j=0; j<10; j++){
			if(ok[j] && !count(i.begin(), i.end(), j + '0')){
				bad = 1;
			}
			else if(!ok[j] && count(i.begin(), i.end(), j + '0')){
				bad = 1;
			}
		}
		if(!bad) real.push_back(i);
	}
	printf("%d\n",real.size());
	for(auto &i : real){
		cout << i << endl;
	}
}