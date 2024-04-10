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

int n,m,k,p,ans=0;
string s;

int a[1000],b[1000];

bool f(char c){ 
	return c=='a' || c=='e' || c=='o' || c=='u' || c=='i';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	for (int i=0; i<s.length(); i++) {
		if (s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
	}
	int len=s.length();
	while (true) {
		int gl=0,curgl=10000000;
		for (int i=0; i<len; i++) gl+=f(s[i]);
		if (gl<=2*(len-gl)) {
			break;
		}		
		curgl=gl;
		for (int i=1; i<s.length()-len+1; i++) {
			gl+=-f(s[i-1])+f(s[i+len-1]);
			if (gl<=2*(len-gl)) {
				break;
			}
			else curgl=min(curgl,gl);
		}
		if (gl<=2*(len-gl)) break;
		len=3*(len-curgl);
	}
	int gl=0;
	for (int i=0; i<len; i++) {
		gl+=f(s[i]);
	}
	ans+=gl<=2*(len-gl);
	for (int i=1; i<s.length()-len+1; i++) {
		gl+=-f(s[i-1])+f(s[i+len-1]);
		if (gl<=(len-gl)*2) ans++;
	}
	if (len==0) cout << "No solution";
	else 
	cout << len << ' ' << ans;
	return 0;
}