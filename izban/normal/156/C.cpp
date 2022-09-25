#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const ll mod=1000000007;
string s;
int ans,sum;
int d[200][3000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	d[0][0]=1;
	for (int i=0; i<200-1; i++) 
		for (int j=0; j<27*100; j++)
			for (int k=0; k<26; k++) 
				d[i+1][j+k]=(d[i+1][j+k]+d[i][j])%mod;
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		cin >> s;
		sum=0;
		for (int i=0; i<s.length(); i++) sum+=s[i]-'a';
		cout << d[s.length()][sum]-1 << endl;
	}
	return 0;
}