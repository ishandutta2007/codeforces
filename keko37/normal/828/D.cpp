#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 200005;

int n, k;
int l[MAXN];
vector < pair <int, int> > v;

int main () {
	cin >> n >> k;
	n--;
	int cnt=1, pos=0;
	for (; n; n--) {
		cnt++;
		if (2<=cnt && cnt<=k+1) {
			v.push_back(make_pair(cnt, 1));
		} else {
			v.push_back(make_pair(cnt, cnt-k));
		}
		l[pos]++;
		pos++;
		if (pos==k) pos=0;
	}
	cout << l[0]+l[1] << endl;
	for (int i=0; i<v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}