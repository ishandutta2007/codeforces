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
int n,m,k,p,ans;
string s;

string a,b;

int get(string s, int x) {
	ll res=0; 
	ll p=1;
	for (int i=s.length()-1; i>=0; i--) {
		if (s[i]>='0' && s[i]<='9' && (s[i]-'0'>=x)) return -1;
		if (s[i]>='A' && s[i]<='Z' && (s[i]-'A'+10>=x)) return -1;
		if (s[i]>='0' && s[i]<='9') res+=(s[i]-'0')*p;
		if (s[i]>='A' && s[i]<='Z') res+=(s[i]-'A'+10)*p;
		p*=x;
	}
	if (res>60) return -1;
	return res;
}

bool check(string s,int x) {
	for (int i=0; i<s.length()-1; i++) {
		if (s[i]!='0') return false;
	}
	if (x==59) return true;
	if (s[s.length()-1]-'A'+10<=23) return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s;
	int k=0;
	while (s[k]!=':') a+=s[k++];
	k++;
	while (k<s.length()) b+=s[k++];
	bool f=false;
	if (check(a,23)&&check(b,59)) {
		cout << -1;
		return 0;
	}
	for (int i=2; i<=100; i++) {
		if (get(a,i)>=0 && get(a,i)<=23 && get(b,i)>=0 && get(b,i)<=59) {
			cout << i << ' ';
			f=true;
		}
	}
	if (!f) cout << 0;
	return 0;
}