#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) cin >> x[i];
	sort(x.begin(), x.end());
	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int tmp;
		cin >> tmp;
		auto ub = upper_bound(x.begin(), x.end(), tmp);
		cout << ub - x.begin() << endl;
	}
}