#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 1000005;

int n;
int A[105];
bool done[N];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%d", A+i);
		}
		sort(A, A+n);
		set<int> diff;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++)
				diff.insert(A[j] - A[i]);
		}
		vi DD(diff.begin(), diff.end());
		memset(done, 0, sizeof done);
		done[1] = true;
		vi B(1,1);
		bool ans = true;
		for (int i=1; i<n; i++) {
			for (auto x: DD) {
				if (B[i-1] + x <= 1000000)
					done[B[i-1] + x] = true;
			}
			int j = B[i-1] + 1;
			while (j<=1000000 && done[j])
				j++;
			if (j <= 1000000)
				B.push_back(j);
			else {
				ans = false;
				break;
			}
		}
		if (ans) {
			printf("YES\n");
			for (auto x : B)
				printf("%d ", x);
			printf("\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}