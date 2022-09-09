#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void maxi(int & a, int b) { a = max(a, b); }

vector<ll> candidate[2][2];

int n;
vector<int> answer;
vector<vector<vector<int>>> extensions;

void consider(int one, int two, int score) {
	maxi(answer[max(one, two)], score);
	extensions[min(one, two)].push_back(vector<int>{one, two, score});
}

void go_from(int one, int two, int so_far) {
	// extend the first row
	if(one < n) {
		consider(one + 1, two, so_far);
		int i = candidate[0][0][one];
		if(i != -1)
			consider(i + 1, two, so_far + 1);
	}
	// extend the second row
	if(two < n) {
		consider(one, two + 1, so_far);
		int i = candidate[1][1][two];
		if(i != -1)
			consider(one, i + 1, so_far + 1);
	}
	// extend both rows (with a rectangle of height 2)
	if(one == two && one < n) {
		int i = candidate[0][1][one];
		if(i != -1)
			consider(i + 1, i + 1, so_far + 1);
	}
}

int main() {
	scanf("%d", &n);
	answer.resize(n + 1, 0);
	extensions.resize(n + 1);
	vector<vector<ll>> in(2, vector<ll>(n));
	for(vector<ll> & row : in)
		for(int i = 0; i < n; ++i) {
			scanf("%lld", &row[i]);
			if(i) row[i] += row[i-1]; // prefix sums
		}
	for(int i0 = 0; i0 <= 1; ++i0)
		for(int i1 = i0; i1 <= 1; ++i1) {
			candidate[i0][i1].resize(n, -1);
			map<ll, int> next_occurrence;
			for(int where = n - 1; where >= 0; --where) {
				ll new_value = 0;
				for(int i = i0; i <= i1; ++i)
					new_value += in[i][where];
				next_occurrence[new_value] = where;
				ll need = 0;
				if(where != 0)
					for(int i = i0; i <= i1; ++i)
						need += in[i][where-1];
				if(next_occurrence.count(need))
					candidate[i0][i1][where] = next_occurrence[need];
			}
		}
	
	for(int where = 0; where < n; ++where) {
		int so_far = answer[where];
		go_from(where, where, so_far);
		
		auto mini = [&] (int & a, int b) {
			if(a == -1 || b < a) a = b;
		};
		int how_far_up = -1, how_far_down = -1;
		for(const vector<int> & ext : extensions[where]) {
			if(ext[1] == where && ext[2] == so_far + 1)
				mini(how_far_up, ext[0]);
			if(ext[0] == where && ext[2] == so_far + 1)
				mini(how_far_down, ext[1]);
		}
		if(how_far_up != -1)
			go_from(how_far_up, where, so_far + 1);
		if(how_far_down != -1)
			go_from(where, how_far_down, so_far + 1);
	}
	printf("%d\n", answer[n]);
}