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

const double eps=1e-10;

string s;
int a,b,c;
bool f[4];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> s;
	for (int i=0; i<s.length(); i++) {
		a+=s[i]=='1';
		b+=s[i]=='0';
		c+=s[i]=='?';
	}
	f[0]=a<b+c;
	if (s[s.length()-1]!='0') {
		if (s[s.length()-1]=='?') {
			c--; a++;
		}
		if (((b+c-a+(a+b+c)%2)/2>=0) && ((b+c-a+(a+b+c)%2)/2<=c)) f[1]=true;
		if (s[s.length()-1]=='?') {
			c++; a--;
		}
	}
	if (s[s.length()-1]!='1') {
		if (s[s.length()-1]=='?') {
			c--; b++;
		}
		if (((a+c-b-(a+b+c)%2)/2>=0) && ((a+c-b-(a+b+c)%2)/2<=c)) f[2]=true;
		if (s[s.length()-1]=='?') {
			c++; b--;
		}
	}
	f[3]=a+c>b+1;
	for (int i=0; i<4; i++) if (f[i]) cout << i/2 << i%2 << endl;
	return 0;
}