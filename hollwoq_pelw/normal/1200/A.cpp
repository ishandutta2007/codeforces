#include <bits/stdc++.h>
using namespace std;
 
bool a[10];
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	for(char c : s) {
		if(c=='L') {
			int i=0;
			while(a[i])
				++i;
			a[i]=1;
		} else if(c=='R') {
			int i=9;
			while(a[i])
				--i;
			a[i]=1;
		} else {
			a[c-'0']=0;
		}
	}
	for(int i=0; i<10; ++i)
		cout << a[i];
}