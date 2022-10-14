#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 5005;

int n, k, v, naso;
int a[MAXN], bio[MAXN];
pair <int, int> doso[MAXN] [MAXN];
bool dp[MAXN] [MAXN];
vector < pair <int, pair <int, int> > > sol;

void premjesti (int x, int y) {
	if (a[x]!=0) sol.push_back(make_pair(a[x]/k+(a[x]%k>0), make_pair(x, y)));
	a[y]+=a[x];
	a[x]=0;
}

int f (int x, int y) {
	if (doso[x] [y].first==-1) {
		bio[x]=1;
		if (x>0) naso=1;
		return x;
	} else if (doso[x] [y].second==y) {
		return f(doso[x] [y].first, doso[x] [y].second);
	} else {
		bio[x]=1; naso=1;
		int t=f(doso[x] [y].first, doso[x] [y].second);
		premjesti(t, x);
		return x;
	}
}

void ispis () {
	for (int i=0; i<sol.size(); i++) {
		cout << sol[i].first << " " << sol[i].second.first << " " << sol[i].second.second << endl;
	}
}

int main () {
	cin >> n >> k >> v;
	dp[0] [0]=1;
	doso[0] [0]=make_pair(-1, -1);
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		int ost=a[i]%k;
		for (int j=0; j<k; j++) {
			int novi=j-ost;
			if (novi<0) novi+=k;
			if (ost==j) {
				dp[i] [j]=1;
				doso[i] [j]=make_pair(-1, -1);
			} else if (dp[i-1] [j]) {
				dp[i] [j]=1;
				doso[i] [j]=make_pair(i-1, j);
			} else if (dp[i-1] [novi]) {
				dp[i] [j]=1;
				doso[i] [j]=make_pair(i-1, novi);
			}
		}
	}
	if (!dp[n] [v%k]) {
		cout << "NO";
		return 0;
	}
	int pos=f(n, v%k);
	if (v%k==0 && !naso) {
		bio[1]=1;
		pos=1;
		premjesti(1, 2);
	}
	int ost=1;
	for (int i=1; i<=n; i++) {
		if (bio[i]==0) ost=i;
	}
	for (int i=1; i<=n; i++) {
		if (bio[i]==0 && i!=ost) premjesti(i, ost);
	}
	if (a[pos]<v) {
		int d=v-a[pos];
		int cnt=d/k;
		if (a[ost]<cnt*k) {
			cout << "NO";
		} else {
			cout << "YES" << endl;
			ispis();
			if (cnt) cout << cnt << " " << ost << " " << pos;
		}
	} else {
		int d=a[pos]-v;
		int cnt=d/k;
		cout << "YES" << endl;
		ispis();
		if (cnt) cout << cnt << " " << pos << " " << ost;
	}
	return 0;
}