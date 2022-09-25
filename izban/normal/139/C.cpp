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

int n,m,k,p,ans;
string s;
string a[4];
long long hsh[4];
bool f1=true,f2=true,f3=true;


bool gl(char c) {
	return c=='a' || c=='e' || c=='u' || c=='i' || c=='o';
}

bool check1(int x) {
	return (hsh[0]==hsh[1] && hsh[2]==hsh[3]);
}

bool check2(int x) {
	return (hsh[0]==hsh[2] && hsh[1]==hsh[3]);
}

bool check3(int x) {
	return (hsh[0]==hsh[3] && hsh[2]==hsh[1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		for (int j=0; j<4; j++) {
			int c=0;
			hsh[j]=0;
			p=1;
			for (int t=a[j].length()-1; t>=0; t--) {
				if (c!=k && gl(a[j][t])) c++;
				if (c==k) {
					for (int tt=t; tt<a[j].length(); tt++) {
						hsh[j]+=(a[j][tt]-'a'+1)*p;
						p*=31;
					}
					break;
				}
			}
			if (c<k) {
				f1=f2=f3=false;
			}
		}
		f1=f1 && check1(0);
		f2=f2 && check2(0);
		f3=f3 && check3(0);
	}
	if (f1 && f2 && f3) cout << "aaaa"; else 
	if (!f1 && !f2 && !f3) cout << "NO"; else 
	if (f1) cout << "aabb"; else
	if (f2) cout << "abab"; else
	if (f3) cout << "abba";
	return 0;
}