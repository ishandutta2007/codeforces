#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

const int MAXN = 200005;

int n, k, cnt, sum;
int a[MAXN], b[MAXN], l[MAXN];
multiset <int> s;

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i=0; i<n; i++) {
		if (a[i]<=b[i]) {
			cnt++;
			l[i]=1;
			sum+=a[i];
		} else {
			sum+=b[i];
			s.insert(a[i]-b[i]);
		}
	}
	if (cnt>=k) {
		cout << sum;
	} else {
		for (int i=0; i<k-cnt; i++) {
			sum+=*s.begin();
			s.erase(s.begin());
		}
		cout << sum;
	}
	return 0;
}