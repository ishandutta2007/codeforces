#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

typedef long long llint;

const int MAXN = 5005;
const llint INF = 10000000000000000LL;

int n;
int l[MAXN];
llint dp[MAXN] [5];
pair <int, int> doso[MAXN] [5];
vector <int> v;

llint f (int ind, int ost) {
	if (dp[ind] [ost]!=-INF) return dp[ind] [ost];
	if (ind==n) return 0;
	llint res;
	if (ost & 1) {
		res=-INF;
		if (ost) {
			llint t=-f(ind, ost-1);
			if (t>res) {
				res=t;
				doso[ind] [ost]=make_pair(ind, ost-1);
			}
		}
		llint t=l[ind]+f(ind+1, ost);
		if (t>res) {
			res=t;
			doso[ind] [ost]=make_pair(ind+1, ost);
		}
	} else {
		res=INF;
		if (ost) {
			llint t=-f(ind, ost-1);
			if (t<res) {
				res=t;
				doso[ind] [ost]=make_pair(ind, ost-1);
			}
		}
		llint t=l[ind]+f(ind+1, ost);
		if (t<res) {
			res=t;
			doso[ind] [ost]=make_pair(ind+1, ost);
		}
	}
	dp[ind] [ost]=res;
	return res;
}

int main () {
	for (int i=0; i<MAXN; i++) {
		for (int j=0; j<5; j++) {
			dp[i] [j]=-INF;
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	f(0, 3);
	int ind=0, ost=3, nind, nost;
	while (ind!=n) {
		//cout << ind << " " << ost << endl;
		nind=doso[ind] [ost].first;
		nost=doso[ind] [ost].second;
		if (ost>nost) v.push_back(ind);
		ind=nind; ost=nost;
	}
	while (v.size()<3) v.push_back(n);
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}