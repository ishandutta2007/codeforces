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

const int maxn=100100;

int n,l,r,k,ans=maxn;
string s;
int c[maxn],d[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s;
	c[0]=s[0]>='a' && s[0]<='z';
	d[0]=s[0]>='A' && s[0]<='Z';
	for (int i=1; i<s.length(); i++) {
		c[i]=c[i-1]+(s[i]>='a' && s[i]<='z');
		d[i]=d[i-1]+(s[i]>='A' && s[i]<='Z');
	}
	ans=min(ans,d[s.length()-1]);
	for (int i=0; i<s.length(); i++) {
		ans=min(ans,c[i]+(d[s.length()-1]-d[i]));
	}
	cout << ans;
	/*l=s.length()-1, r=0;
	for (int i=0; i<s.length(); i++) {
		if (s[i]>='a' && s[i]<='z') {
			l=i;
			break;
		}
	}

	for (int i=s.length()-1; i>=0; i--) {
		if (s[i]>='A' && s[i]<='Z') {
			r=i;
			break;
		}
	}
	for (int i=l; i<=r; i++)
		k+=s[i]>='A' && s[i]<='Z';
	int g=0;

	cout << max(0,min(k,r-l+1-k));*/
	return 0;
}