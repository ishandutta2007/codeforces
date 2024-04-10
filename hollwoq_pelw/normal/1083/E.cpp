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
    // cin >> testcases;
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

struct line {
	long long a, b;
	line(long long _a, long long _b) 
		: a(_a), b(_b) {}
	long long f(int x) {
		return a * x + b;
	}
};

long double slope(line l1, line l2){
	return (long double) (l2.b - l1.b) / (long double) (l2.a - l1.a);
}

bool comp(line l, line a, line b){
	return slope(l, a) <= slope(l, b);
}

vector<line> lines;

struct CHT {
	int ptr = 0;
	void add(long long a, long long b){
		line ln(a, b);
		while (lines.size() > 1 && comp(lines[lines.size() - 2], lines.back(), ln))
			lines.pop_back();
		lines.push_back(ln);
		ptr = min(ptr, (int) lines.size() - 1);
	}
	long long get(long long x){
		if (lines.empty()) return -1e18;
		while (ptr + 1 < lines.size() && lines[ptr].f(x) < lines[ptr + 1].f(x))
			++ ptr;
		return lines[ptr].f(x);
	}
} cht;

const int N = 1e6 + 5;

struct rect {
	int w, h; long long a;
	bool operator < (const rect &oth) const {
		return w < oth.w;
	}
} r[N];

int n;

long long ans, tmp;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> r[i].w >> r[i].h >> r[i].a;
	sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; i++){
		ans = max(ans, (tmp = max(cht.get(- r[i].h), 0ll) + 1ll * r[i].w * r[i].h - r[i].a)), cht.add(r[i].w, tmp);
	}
	cout << ans;
}