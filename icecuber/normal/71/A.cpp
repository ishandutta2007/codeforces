#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string in;
		cin >> in;
		if (in.length() <= 10) {
			cout << in << endl;
		} else {
			cout << in[0] << in.length()-2 << in[in.length()-1] << endl;
		}
	}
	return 0;
}