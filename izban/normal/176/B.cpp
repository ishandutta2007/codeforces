#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

vector<int> pr;

void prefix(string &s) {
	int n=s.length();
	pr.resize(n+1);
	pr[0]=0;
	int k=0;
	for (int i=1; i<n; i++) {
		while (k && s[i]!=s[k]) 
			k=pr[k-1];
		k+=s[i]==s[k];
		pr[i]=k;
	}
}

const int maxn=100100;
const int mod=1000000007;
int n,k;
string a,b;
int f;
int d[maxn][2];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> a >> b >> k;
	string s=b+"#"+a+a;
	prefix(s);
	for (int i=2*b.length()+1; i<s.length(); i++) 
		if (pr[i]==a.length())
			f++;
	if (!f) {
		cout << 0;
		return 0;
	}
	d[0][a==b]=1;
	for (int i=0; i<k; i++) {
		d[i+1][1]=((ll)d[i][0]*(f)+(ll)d[i][1]*(f-1))%mod;
		d[i+1][0]=((ll)d[i][1]*(a.length()-f)+(ll)d[i][0]*(a.length()-f-1))%mod;
	}
	cout << d[k][1];
	return 0;
}