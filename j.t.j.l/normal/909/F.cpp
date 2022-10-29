#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int N, m;

void prework(){

}

void read(){

}

int a[MAXN];

int gao1(int n){
	while(n != 0){
		if (n == 1){
			puts("NO");
			return 0;
		}
		m = 1;
		while(m < n) m *= 2;
		// m >= n
		if (n == m - 1){
			puts("NO");
			return 0;
		}
		if (n == m){
			a[n] = n - 1;
			a[n - 1] = n;
			n -= 2;
			continue;
		}
		else{
			m /= 2;
			//cout << n << ' ' << m << ' ' << 2 * m - 1 - n - 1 << endl;
			for (int i = m; i <= n; i++){
				a[i] = 2 * m - 1 - i;
				a[2 * m - 1 - i] = i;
			}
			n = 2 * m - 1 - n - 1;
			continue;
		}
	}
	puts("YES");
	for (int i = 1; i <= N; i++){
		//assert((a[i] & i) == 0 && i != a[i]);
		printf("%d%c", a[i], " \n"[i == N]);
	}
}

int gao2(int n){
	if (n <= 5) {
		puts("NO");
		return 0;
	}
	if (n & 1) {
		a[1] = 5, a[5] = 7, a[7] = 1;
		a[2] = 3, a[3] = 2;
		a[4] = 6, a[6] = 4;
		for (int i = 8; i < n; i += 2)
			a[i] = i + 1, a[i + 1] = i;
	}
	else{
		m = 1;
		while(m < n) m *= 2;
		if (n == m){
			puts("NO");
			return 0;
		}
		for (int i = 2; i < n; i += 2)
			a[i] = i + 1, a[i + 1] = i;
		a[n-2] = n;
		a[n] = n-2;
		a[1] = n - 1;
		a[n - 1] = 1;
	}
	puts("YES");
	for (int i = 1; i <= N; i++){
		//assert((a[i] & i) != 0 && i != a[i]);
		printf("%d%c", a[i], " \n"[i == N]);
	}
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &N);
	gao1(N);
	gao2(N);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}