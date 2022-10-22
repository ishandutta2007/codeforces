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

#define int long long

const int N = 1e5 + 5;

int n, p, curtime, res[N];
pair<int, int> a[N];

priority_queue<int, vector<int>, greater<int>> pq;

void Hollwo_Pelw() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + n + 1);
	int cur = 0, id;
	while (cur < n || pq.size()) {
		if (pq.size())
			id = pq.top(), pq.pop(), curtime += p;
		else
			id = a[++ cur].second, curtime = a[cur].first + p;
		res[id] = curtime;
		// cout << id << ' ' << curtime << endl;
		while (cur < n && curtime >= a[cur + 1].first) {
			++ cur;
			if (id < a[cur].second) 
				pq.push(a[cur].second);
			else
				res[a[cur].second] = (curtime += p), id = a[cur].second;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
}