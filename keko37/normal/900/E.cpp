#include<iostream>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 100005;

int n, m;
string s;
int a[MAXN], b[MAXN], bio[MAXN];
par dp[MAXN];

int geta (int x, int y) {
	if (x<2) return a[y]; return a[y]-a[x-2];
}

int getb (int x, int y) {
	if (x<2) return b[y]; return b[y]-b[x-2];
}

int ok (int x) {
	if (x+m>n) return -1;
	if (m==1) if (s[x]=='a') return 0; else if (s[x]=='?') return 1; else return -1;
	int res=0;
	if (m&1) {
		if (getb(x, x+m-1)>0) return -1; else res+=geta(x, x+m-1);
		if (geta(x+1, x+m-2)>0) return -1; else res+=getb(x+1, x+m-2);
	} else {
		if (getb(x, x+m-2)>0) return -1; else res+=geta(x, x+m-2);
		if (geta(x+1, x+m-1)>0) return -1; else res+=getb(x+1, x+m-1);
	}
	return m-res;
}

par f (int x) {
	if (x==n) return make_pair(0, 0);
	if (bio[x]) return dp[x];
	bio[x]=1;
	par t=f(x+1);
	int maxi=t.first, br=t.second;
	int val=ok(x);
	if (val!=-1) {
		par r=f(x+m);
		if (r.first+1==maxi) {
			br=min(br, val+r.second);
		} else if (r.first+1>maxi) {
			maxi=r.first+1;
			br=val+r.second;
		}
	}
	dp[x]=make_pair(maxi, br);
	return dp[x];
}

int main () {
	cin >> n >> s >> m;
	for (int i=0; i<n; i++) {
		if (i>=2) {
			a[i]=a[i-2];
			b[i]=b[i-2];
		}
		if (s[i]=='a') a[i]++;
		if (s[i]=='b') b[i]++;
	}
	cout << f(0).second;
	return 0;
}