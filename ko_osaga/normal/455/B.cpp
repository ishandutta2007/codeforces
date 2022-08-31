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
typedef pair<lint, lint> pi;

int trie[100005][26], piv, k;

int win(int node, int dep){
	for(int j=0; j<26; j++){
		if(!trie[node][j]) continue;
		if(!win(trie[node][j], dep+1)){ // found loser -> i am winner
			return 1;
		}
	}
	return 0;
}

int lose(int node, int dep){
	int cnt = 0;
	for(int j=0; j<26; j++){
		if(!trie[node][j]) continue;
		cnt++;
		if(!lose(trie[node][j], dep + 1)){
			return 1;
		}
	}
	return !cnt;
}

int main(){
	int n;
	cin >> n >> k;
	k++;
	while(n--){
		string s;
		cin >> s;
		int p = 0;
		for(auto &i : s){
			if(!trie[p][i - 'a']){
				trie[p][i - 'a'] = ++piv;
			}
			p = trie[p][i - 'a'];
		}
	}
	int w = win(0, 0), l = lose(0, 0);
	//printf("%d %d\n",w, l);
	if(w && l) puts("First");
	else if(w){
		puts(k % 2 ? "Second" : "First");
	}
	else{
		puts("Second");
	}
}