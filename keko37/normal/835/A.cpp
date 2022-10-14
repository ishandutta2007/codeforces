#include<iostream>

using namespace std;

int s, v1, v2, t1, t2;
int val1, val2;

int main () {
	cin >> s >> v1 >> v2 >> t1 >> t2;
	val1=s*v1+2*t1;
	val2=s*v2+2*t2;
	if (val1>val2) {
		cout << "Second";
	} else if (val1<val2) {
		cout << "First";
	} else {
		cout << "Friendship";
	}
	return 0;
}