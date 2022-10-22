/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5;
#define int long long

int n, a[N], b[N];

template<typename T, T(*merge)(T, T) > struct rmq {
    T st[N][18];
    void init(int n, T * arr){
        for (int i = 1; i <= n; i++){
            st[i][0] = arr[i];
        }
        for (int j = 1; j < 18; j++){
            for (int i = 1; i + (1 << j) <= n + 1; i++){
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    T query(int L, int R){
        if (L > R) return T(0);
        int j = __lg(R - L + 1);
        return merge(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int gcd(int a, int b) {
	return __gcd(a, b);
}

rmq<int, gcd> st;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		b[i] = abs(a[i] - a[i - 1]);
	st.init(--n, b);
	int res = 1;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && st.query(i, j) != 1) j++;
		res = max(res, j - i + 1);
	}
	cout << res << '\n';
}