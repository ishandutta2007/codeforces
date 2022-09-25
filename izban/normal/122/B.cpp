#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))
string s,anss;
int ans;

bool f(string a, int x) {
	for (int i=x; i<x+a.length(); i++)
		if (s[i]!=a[i-x]) return false;
	return true;
}
bool g(string a) {
	for (int i=0; i<a.length(); i++) 
		if (a[i]!='4' && a[i]!='7') return false;
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);       
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	for (int i=0; i<s.length(); i++)
		for (int j=i; j<s.length(); j++) {
			string a="";
			for (int k=i; k<=j; k++) a+=s[i];
			int ansa=0;
			for (int k=0; k<s.length()-a.length()+1; k++)
				if (f(a,k)) ansa++;
			if (g(a) && (ansa>ans || ansa==ans && a<anss)) {
				ans=ansa; anss=a;
			}
		}
	if (ans>0) cout << anss;
	if (ans==0) cout << -1;
	return 0;
}