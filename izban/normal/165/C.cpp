#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=1000100;

int k,cur;
string s;
ll d[maxn],ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> k >> s;
	d[0]=1;
	for (int i=0; i<s.length(); i++) {
		int c=s[i]-'0';
		cur+=c;
		if (cur>=k) 
			ans+=d[cur-k];
		d[cur]++;
	}
	cout << ans;
	return 0;
}