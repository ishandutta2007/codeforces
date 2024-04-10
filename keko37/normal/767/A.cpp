#include<iostream>
#include<set>

using namespace std;

int n, x, curr;
set <int> s;

int main () {
	cin >> n;
	curr=n;
	for (int i=0; i<n; i++) {
		cin >> x;
		s.insert(-x);
		while (!s.empty() && *s.begin()==-curr) {
			cout << -(*s.begin()) << " ";
			s.erase(s.begin());
			curr--;
		}
		cout << endl;
	}
	return 0;
}