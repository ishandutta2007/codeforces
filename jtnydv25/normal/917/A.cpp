#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5005;
const int logN = 13;
int floorlog[N];
int rmq[logN][N];
int p[N], q[N];
const int INF = 1e9;
inline int mn(int i, int j){
	if(j < i) return INF;
	int k = floorlog[j - i + 1];
	return min(rmq[k][i], rmq[k][j - (1 << k) + 1]);
}
vector<int> qm;
int main(){
	int n;
	cin.tie(0);
	string s;
	cin >> s;
	n = s.length();
	for(int i = 0; (1 << i) < N; i++){
		for(int j = (1 << i) ; j < N && j < (1 << (i + 1)); j++)
			floorlog[j] = i;
	}
	for(int i = 1; i <= n; i++){
		char c = s[i - 1];
		q[i] = q[i - 1];
		p[i] = p[i - 1];
		if(c == '?') q[i]++, p[i]++;
		else if(c == '(') p[i]++;
		else if(c == ')') p[i] --;
	}

	for(int i = n; i >= 1; i--){
		rmq[0][i] = p[i] - 2 * q[i];
		for(int j = 1; i + (1 << j) - 1 <= n; j++){
			rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
		}
	}
	int ans = 0;
	for(int l = 1; l <= n; l++){
		int sm = 0;
		qm.clear();
		int mnpos = INF;
		for(int r = l; r <= n; r++){
			sm = p[r] - p[l - 1];
			if(s[r - 1] == '?') qm.push_back(r);
			if(sm < 0) break;
			if(sm == 0){
				ans++; continue;
			}
			if((r - l + 1) & 1) continue;
			// cerr << l << " " << r << " " << sm
			int req = sm >> 1;
			if(qm.size() >= req){
				int t = qm[qm.size() - req];
				int d = 2 * q[t - 1] - p[l - 1];
				// cerr << l << " " << r << endl;
				if(mn(t, r) + d >= 0) ans++;
			}
		}
	}
	cout << ans;
}