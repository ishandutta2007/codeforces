#include<iostream>
#include<set>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 100005;

int n, naso;
int bio[MAXN];
vector <int> v;
set <int> s;

void f (int pos) {
	if (naso) return;
	if (pos==n+1) {
		naso=1;
		for (int i=1; i<=n; i++) {
			printf("%d ", bio[i]);
		}
	}
	for (int i=max(pos-10, 1); i<=n; i++) {
		if (naso) return;
		if (i!=pos && !bio[i] && (pos&i)!=0) {
			bio[i]=pos;
			f(pos+1);
			bio[i]=0;
		}
	}
}

int main () {
	cin >> n;
	int org=n;
	if (n&1) {
		cout << "NO" << endl;
	} else {
		while (n>0) {
			int obr=0, prva=1;
			for (int i=30; i>=0; i--) {
				if (n & (1<<i)) {
					if (prva) {
						prva=0;
						obr=(1<<i)-1;
					} else {
						obr-=(1<<i);
					}
				}
			}
			for (int i=obr; i<=n; i++) {
				v.push_back(i);
			}
			n=obr-1;
		}
		cout << "YES" << endl;
		for (int i=v.size()-1; i>=0; i--) {
			printf("%d ", v[i]);
		}
		cout << endl;
	}
	n=org;
	if (__builtin_popcount(n)==1 || n<6) {
		cout << "NO";
	} else {
		cout << "YES" << endl;
		for (int i=1; i<=n; i++) {
			s.insert(i);
		}
		f(1);
	}
	return 0;
}