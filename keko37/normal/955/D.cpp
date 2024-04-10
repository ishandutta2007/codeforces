#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 500005;

int n, m, k;
string s, t;
int back[MAXN], dp[MAXN] [2], pos[MAXN];

void build () {
	int curr=-1;
	back[0]=-1;
	for (int i=1; i<m; i++) {
		while (curr!=-1 && t[i]!=t[curr+1]) {
			curr=back[curr];
		}
		curr++;
		back[i]=curr;
		if (curr==0 && t[i]!=t[0]) back[i]=-1, curr--;
	}
}

void calc_dp (int ind) {
	int curr=0;
	dp[0] [ind]=0;
	if (s[0]!=t[0]) dp[0] [ind]=-1, curr--;
	for (int i=1; i<n; i++) {
		while (curr!=-1 && s[i]!=t[curr+1]) {
			curr=back[curr];
		}
		curr++;
		dp[i] [ind]=curr;
		if (curr==0 && s[i]!=t[0]) dp[i] [ind]=-1, curr--;
	}
}

void nadi (int x, int y) {
	for (int i=0; i<n; i++) {
		if (i<=x && y<=i+2*k-1) {
			cout << "Yes" << endl << i+1 << " " << i+1+k;
			break;
		}
	}
}

int main () {
	memset(pos, -1, sizeof pos);
	cin >> n >> m >> k >> s >> t;
	build(); calc_dp(0);
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	build(); calc_dp(1);
	reverse(t.begin(), t.end()); build();
	for (int i=0; i<n; i++) {
		if (dp[i] [0]==m-1) {nadi(i-m+1, i); return 0;}
		if (dp[i] [1]==m-1) {nadi(i, i+m-1); return 0;}
	}
	for (int i=k-1; i<n-k; i++) {
		int val=dp[i] [0], q=dp[n-i-2] [1];
		while (val<k && val!=-1 && pos[val]==-1) {
			pos[val]=i;
			val=back[val];
		}
		if (q>=k || q==-1) continue;
		if (m-q-2>=0 && pos[m-q-2]!=-1) {
			cout << "Yes" << endl << pos[m-q-2]-k+2 << " " << i+2;
			return 0;
		}
	}
	cout << "No";
	return 0;
}