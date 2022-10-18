#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

	int N, M;
	cin >> N >> M;

	bool b = true;
	for (int i = 0; i < N && b; i++)
	{
		char c;
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c != 'W' && c != 'B' && c != 'G')
			{
				b = false;
				break;
			}
		}
	}

	cout << (b ? "#Black&White" : "#Color") << endl;

}