#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 200005;

int n, cnt;
int l[MAXN];
string s;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	cin >> s;
	s+='0';
	int prvi=-1;
	for (int i=0; i<n; i++) {
		if (i==0 && s[i]=='1' || s[i-1]=='0' && s[i]=='1') {
			prvi=i;
		} else if (s[i]=='0' && i!=0 && s[i-1]=='1') {
			sort(l+prvi, l+i+1);
		}
	}
	for (int i=1; i<n; i++) {
		if (l[i]>l[i-1]) cnt++;
	}
	if (cnt==n-1) cout << "YES"; else cout << "NO";
	return 0;
}