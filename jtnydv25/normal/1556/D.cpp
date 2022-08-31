#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif
const int N = 100;
int vals[N];

int OR(int i, int j){
	#ifdef LOCAL
	return vals[i] | vals[j];
	#endif
	cout << "or " << i + 1 << " " << j + 1 << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int AND(int i, int j){
	#ifdef LOCAL
	return vals[i] & vals[j];
	#endif
	cout << "and " << i + 1 << " " << j + 1 << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

void res(int v){
	cout << "finish " << v << endl;
	fflush(stdout);
}

int main(){
	int n, k; cin >> n >> k;
	vector<int> A(n);
	vector<int> B(n);
	vector<int> o(n), a(n);
	#ifdef LOCAL
	for(int i = 0; i < n; i++){
		vals[i] = rand() % 100;
		cerr<<vals[i] <<" ";
	}
	cerr<<endl;
	#endif
	for(int i = 1; i < n; i++){
		int u = OR(i - 1, i), v = AND(i - 1, i);
		o[i - 1] = u;
		a[i - 1] = v;
		B[i] = u & ~v;
		A[i] = A[i - 1] ^ B[i];
	}

	// get x
	int x = 0;
	int xx = AND(0, 2), yy = OR(0, 2); 
	for(int i = 0; i < 30; i++){
		int a0 = a[0] >> i & 1, o0 = o[0] >> i & 1;
		int a1 = a[1] >> i & 1, o1 = o[1] >> i & 1;
		if(a0 == o0){
			x |= a0 << i;
		} else if(a1 == o1){
			x |= (((a[1] ^ A[1])) >> i & 1) << i;
		} else{
			int u = xx >> i & 1, v = xx >> i & 1;
			assert(u == v);
			x |= (xx >> i & 1) << i;
		}
	}

	for(int i = 0; i < n; i++) A[i] ^= x;
	sort(all(A));
	res(A[k - 1]);
}