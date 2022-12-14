#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a(8);
	a[0] = 1, a[1] = 2;
	for(int i = 2; i < 8; ++i){
		a[i] = a[i - 2] * a[i - 1];
	}
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		if(N == 3){
			cout << "2\n3 2\n3 2\n";
			continue;
		}
		if(N == 4){
			cout << "3\n3 4\n4 2\n4 2\n";
			continue;
		}
		int pos = 1;
		while(pos + 1 < 8 && a[pos + 1] < N){
			++pos;
		}
		cout << N - 2 + (pos - 2 + 1) << '\n';
		for(int i = 2; i < N; ++i){
			if(i != a[pos - 1] && i != a[pos]){
				cout << i << ' ' << N << '\n';
			}
		}
		cout << N << ' ' << a[pos] << '\n' << N << ' ' << a[pos] << '\n';
		int A = a[pos], B = a[pos - 1];
		for(int i = 2; i <= pos; ++i){
			cout << A << ' ' << B << '\n';
			swap(A, B);
		}
	}
	return 0;
}