#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
    	cout << n/2 + 1 << endl;
	}

}