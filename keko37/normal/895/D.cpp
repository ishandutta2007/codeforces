#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;
const int MOD = 1000000007;

llint n, sol;
string a, b;
llint l[30], fact[MAXN], inv[MAXN];

llint pot (llint x, int e) {
	if (e==0) return 1;
	if (e&1) {
		return x*pot(x, e-1)%MOD;
	} else {
		llint t=pot(x, e>>1);
		return t*t%MOD;
	}
}

void precompute () {
	fact[0]=inv[0]=1;
	for (int i=1; i<MAXN-1; i++) {
		fact[i]=fact[i-1]*i%MOD;
		inv[i]=pot(fact[i], MOD-2);
	}
}

int main () {
	precompute();
	cin >> a >> b;
	n=a.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a[n-1]==b[n-1]) n--;
	for (int i=0; i<n; i++) {
		l[a[i]-'a']++;
	}
	for (int i=n-1; i>=0; i--) {
		llint val=fact[i];
		for (int j=0; j<26; j++) {
			val=val*inv[l[j]]%MOD;
		}
		for (char c=a[i]+1; c<='z'; c++) {
			if (i==n-1 && c==b[i]) break;
			if (l[c-'a']==0) continue;
			llint t=val*fact[l[c-'a']]%MOD*inv[l[c-'a']-1]%MOD;
			sol+=t;
		}
		l[a[i]-'a']--;
	}
	for (int i=0; i<n; i++) {
		l[a[i]-'a']++;
	}
	for (int i=n-1; i>=0; i--) {
		llint val=fact[i];
		for (int j=0; j<26; j++) {
			val=val*inv[l[j]]%MOD;
		}
		for (char c=b[i]-1; c>='a'; c--) {
			if (i==n-1) break;
			if (l[c-'a']==0) continue;
			llint t=val*fact[l[c-'a']]%MOD*inv[l[c-'a']-1]%MOD;
			sol+=t;
		}
		if (l[b[i]-'a']==0) break; else l[b[i]-'a']--;
	}
	cout << sol%MOD;
	return 0;
}