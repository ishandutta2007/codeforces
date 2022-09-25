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
 
const int maxn=100100;

string s;
ll cnt,ans;
ll d[maxn],p[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s;
	for (int i=0; i<s.length(); i++) {
		for (int j=0; i-j>=0 && i+j<s.length(); j++) {
			if (s[i+j]!=s[i-j]) break;
			cnt++;
			d[i+j]++;
			p[i-j]++;
		}
		for (int j=0; i-j>=0 && i+j+1<s.length(); j++) {
			if (s[i-j]!=s[i+j+1]) break;
			cnt++;
			d[i+j+1]++;
			p[i-j]++;
		}
	}
	for (int i=0; i<s.length(); i++) {
		cnt-=p[i];
		ans+=cnt*d[i];
	}
	cout << ans;
	return 0;
}