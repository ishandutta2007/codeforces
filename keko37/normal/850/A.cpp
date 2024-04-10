#include<iostream>
#include<set>

using namespace std;

const int MAXN = 1005;

int n;
long long l[MAXN] [10];
set <int> s;

int main () {
	cin >> n;
	if (n>100) {
		cout << 0;
		return 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) {
			cin >> l[i] [j];
		}
	}
	for (int i=0; i<n; i++) {
		bool ok=1;
		for (int j=0; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (i==j || i==k) continue;
				long long gore=0, dolje=0;
				for (int h=0; h<5; h++) {
					int val=(l[i] [h]-l[j] [h])*(l[i] [h]-l[k] [h]);
					gore+=val;
					dolje+=val*val;
				}
				if (0<gore) ok=0;
			}
		}
		if (ok) s.insert(i+1);
	}
	cout << s.size() << endl;
	for (set <int> :: iterator it=s.begin(); it!=s.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}