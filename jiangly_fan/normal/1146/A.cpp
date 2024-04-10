#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 120000;
void no(){
	cout << "NO";
	exit(0);
} 
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int a = 0;
	for(char c : s) if(c == 'a') a += 1;
	cout << min((int)s.size(), 2 * a - 1);
}