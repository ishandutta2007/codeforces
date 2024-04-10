#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int x[200005], y[200005];
vector < pair < pair <int, int>, int > > v;
vector <int> saz;
int fen[400005];
int sol[400005];

void ubaci (int num, int k) {
	for (; num<400005; num+=num&-num) fen[num]+=k;
}

int upit (int num) {
	int res=0;
	for (; num>0; num-=num&-num) res+=fen[num];
	return res;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		v.push_back(make_pair(make_pair(y[i], x[i]), i));
		saz.push_back(x[i]);
		saz.push_back(y[i]);
	}
	sort(saz.begin(), saz.end());
	sort(v.begin(), v.end());
	for (int i=0; i<n; i++) {
		int x=lower_bound(saz.begin(), saz.end(), v[i].first.second)-saz.begin()+1;
		int y=lower_bound(saz.begin(), saz.end(), v[i].first.first)-saz.begin()+1;
		sol[v[i].second]=upit(y)-upit(x);
		ubaci(x, 1);
	}
	for (int i=0; i<n; i++) {
        cout << sol[i] << endl;
	}
	return 0;
}