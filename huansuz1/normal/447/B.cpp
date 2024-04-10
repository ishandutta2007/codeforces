#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>

#define f first
#define s second
#define mp make_pair
#define ll long long

using namespace std;
int k , n , m , p , a[12345] , ans , ma;
string s;

int main() {
	cin >> s >> k;
	for (int i = 0; i < 26; i++) {
		cin >> a[i];
		if ( a[i] > ma ) ma = a[i];
	}
	
	for (int i = 0; i < s.length(); i++)
		ans += ((i + 1) * a[s[i]-'a']);
	for (int i = s.length() + 1; i <= s.length() + k; i++)
		ans += (i * ma);
	cout<<ans;

}