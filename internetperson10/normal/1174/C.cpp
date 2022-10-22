#include <bits/stdc++.h>

using namespace std;

int num[100001];

int main() {
	int ct=1;
	for(int a=2; a<100001; a++) {
		if(num[a]==0) {
			for(int b=a; b<100001; b+=a) {
				num[b]=ct;
			}
			ct++;
		}
	}
	int n;
	cin >> n;
	for(int a=2; a<=n; a++) cout << num[a] << ' ';
}