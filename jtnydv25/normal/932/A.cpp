#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

int main(){
	string s;
	cin >> s;
	string s2 = s;
	reverse(s2.begin(), s2.end());
	s += s2;
	cout << s;
}