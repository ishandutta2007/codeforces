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

int n, m;
char str[10005];
vector<pi> gph[10005];
int trie[1000005][26], endp[1000005], piv;

string orig[100005];

bool ok[10005];

int main(){
	scanf("%d %s",&n,str + 1);
	scanf("%d",&m);
	for(int i=1; i<=m; i++){
		cin >> orig[i];
		int p = 0;
		for(auto j : orig[i]){
			if(j >= 'A' && j <= 'Z'){
				j -= 'A' - 'a';
			}
			if(!trie[p][j - 'a']){
				trie[p][j - 'a'] = ++piv;
			}
			p = trie[p][j - 'a'];
		}
		endp[p] = i;
	}
	for(int i=1; i<=n; i++){
		int p = 0;
		for(int j=i; j; j--){
			p = trie[p][str[j] - 'a'];
			if(p == 0) break;
			if(endp[p]){
				gph[i].emplace_back(j - 1, endp[p]);
			}
		}
	}
	ok[0] = 1;
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			ok[i] |= ok[j.first];
		}
	}
	stack<int> ret;
	for(int i=n; i; ){
		int nxt = -1;
		for(auto &j : gph[i]){
			if(ok[j.first]){
				ret.push(j.second);
				nxt = j.first;
				break;
			}
		}
		i = nxt;
	}
	while(!ret.empty()){
		cout << orig[ret.top()] <<" ";
		ret.pop();
	}
}