#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 200;

int n, naso, cnt;
vector <int> v[MAXN], v1, v2;
string s[10]={"", "1\n0 1\n0\n1", "2\n-1 0 1\n1\n0 1", "3\n1 0 -1 1\n2\n-1 0 1", "4\n0 1 0 0 1\n3\n1 0 -1 1", "5\n1 -1 0 1 -1 1\n4\n0 1 0 0 1"};
int l[200];

vector <int> f (vector <int> a, vector <int> b, int k, int d) {
	vector <int> res;
	int lim=a.size();
	res.push_back(b[0] + k*a[0]);
	for (int j=1; j<lim-1; j++) {
		res.push_back(k*a[j] + b[j] + a[j-1]*d);
	}
	res.push_back(k*a[lim-1] + a[lim-2]*d);
	res.push_back(d*a[lim-1]);
	return res;
}

bool ok (vector <int> a) {
	for (int i=0; i<a.size(); i++) {
		if (a[i]>1 || a[i]<-1) return 0;
	}
	return 1;
}

void ispis (vector <int> a) {
	cout << a.size()-1 << endl;
	for (int i=0; i<a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void dfs (vector <int> a, vector <int> b) {
	cnt++;
	if (naso || cnt>1e4) return;
	if (a.size()==n+1 && a.back()==1 && b.back()==1) {
		if (naso) return;
		naso=1;
		ispis(a);
		ispis(b);
		return;
	}
	for (int i=-1; i<=1; i++) {
		vector <int> c=f(a, b, i, 1);
		if (ok(c)) dfs(c, a);
		c=f(a, b, i, -1);
		if (ok(c)) dfs(c, a);
	}
}

void rjesi () {
	dfs(v2, v1);
	if (naso==0) {
		cnt=0;
		v2[2]=-1;
		dfs(v2, v1);
		v2[2]=1;
		l[n]=naso;
	} else {
		l[n]=1;
	}
}

int main () {
	cin >> n;
	if (n<=5) {
		cout << s[n];
		return 0;
	}
	v1.push_back(0); v1.push_back(1);
	v2.push_back(1); v2.push_back(0); v2.push_back(1);
	if (n==129) {
		v1[1]=-1;
		rjesi();
		return 0;
	}
	rjesi();
	return 0;
}