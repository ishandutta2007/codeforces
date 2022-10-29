#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	int a, b;
	cin >> n >> a >> b;
	vector<int> f;
	f.push_back(a);
	f.push_back(a);
	f.push_back(a);
	f.push_back(a);
	f.push_back(b);
	f.push_back(b);
	sort(f.begin(), f.end());
	int ans = 6;
	for (int i = 1; i <= 100000; i++){
		random_shuffle(f.begin(), f.end());
		int cnt = 1, rm = n;
		for (auto &x : f)
			if (rm >= x){
				rm -= x;
			}
			else{
				cnt++;
				rm = n - x;
			}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
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