#include <bits/stdc++.h>

using namespace std;

vector<long long int> arr;
long long int prefix[100001];
vector<tuple<int, int, long long int> > que;
int preque[100001];

int main() {
	int n, m, k, x, y, z;
	long long int curr = 0;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		que.push_back(make_tuple(x, y, z));
	}
	for(int i = 0; i < k; i++) {
		cin >> x >> y;
		preque[x-1]++;
		preque[y]--;
	}
	for(int i = 0; i < m; i++) {
		//cout << i << ": " << preque[i] << '\n';
		curr+=preque[i];
		prefix[get<0>(que[i])-1] += get<2>(que[i])*curr;
		prefix[get<1>(que[i])] -= get<2>(que[i])*curr;
	}
	curr = 0;
	for(int i = 0; i < n; i++) {
		//cout << i << ": " << prefix[i] << '\n';
		curr += prefix[i];
		cout << arr[i] + curr << ' ';
	}
}