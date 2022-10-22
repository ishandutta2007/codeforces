#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int op(int x, int y, int tp) {
	if (tp == 0) return x | y;
	if (tp == 1) return x & y;
	if (tp == 2) return assert(y == -1), !x;
	assert(0);
	return -1;
}

int op1(int x, int y, int tp) {
	int ans = 0;
	rep(i, 8) {
		ans |= op(x >> i & 1, y == -1 ? -1 : y >> i & 1, tp) << i;
	}
	return ans;
}

string dp[256][3];
priority_queue <pair <int, pair <int, int> > > que;

void push(int S, int las, const string &s) {
	if (dp[S][las].empty() || (dp[S][las].size() > s.size() || (dp[S][las].size() == s.size() && dp[S][las] > s)))  {
		dp[S][las] = s;
		que.push(mp(-(int)s.size(), mp(S, las)));
	}
}

const int X = 0b00001111;
const int Y = 0b00110011;
const int Z = 0b01010101;

const char oper[] = {'|', '&'};

void prep() {
	push(X, 2, "x");
	push(Y, 2, "y");
	push(Z, 2, "z");
	while (!que.empty()) {
		int S = que.top().second.first;
		int las = que.top().second.second;
		int l = -que.top().first;
		que.pop();
		if (dp[S][las].size() != l) continue;
		string s = dp[S][las];
		rep(nS, 256) rep(nlas, 3) {
			if (!dp[nS][nlas].empty()) {
				string ns = dp[nS][nlas];
				rep(opid, 2) {
					int truth = op1(S, nS, opid);
					string got;
					string lgot;
					if (opid > las) lgot += '(' + s + ')';
					else lgot += s;
					got += oper[opid];
					string rgot;
					if (opid > nlas) rgot += '(' + ns + ')';
					else rgot += ns;
					if (lgot > rgot) swap(lgot, rgot);
					got = lgot + got + rgot;
					push(truth, opid, got);
				}
			}
		}
		int truth = op1(S, -1, 2);
		string got;
		got += '!';
		if (2 > las) got += '(' + s + ')';
		else got += s;
		push(truth, 2, got);
	}
}

void Main() {
	char s[15];
	scanf("%s", s);
	int x = bitset <15> (string(s)).to_ulong();
	string ans;
	rep(las, 3) if (ans.empty() || (ans.size() > dp[x][las].size() || (ans.size() == dp[x][las].size() && ans > dp[x][las])))
		ans = dp[x][las];
	puts(ans.c_str());
}

int main() {
	prep();
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}