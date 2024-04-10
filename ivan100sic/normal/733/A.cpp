#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int pos = -1, sol = 0, i = 0;
	for (char x : s) {
		if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y')
		{
			sol = max(sol, i - pos);
			pos = i;
		}
		i++;
	}
	cout << max(sol, i - pos);
}