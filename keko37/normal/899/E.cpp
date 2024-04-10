#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

const int MAXN = 200005;

int n, cnt, pos, sol;
int l[MAXN], val[MAXN];
set <int> s;
set <int> :: iterator it1, it2;
set < pair <int, int> > t;

void makni () {
	int ind=t.begin()->second;
	t.erase(t.begin());
	s.erase(ind);
	it2=s.upper_bound(ind);
	if (it2==s.begin() || it2==s.end()) return;
	it1=it2; it1--;
	if (l[*it1]!=l[*it2]) return;
	s.erase(it2);
	t.erase(make_pair(-val[*it1], *it1));
	t.erase(make_pair(-val[*it2], *it2));
	val[*it1]+=val[*it2];
	t.insert(make_pair(-val[*it1], *it1));
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	cnt=1;
	for (int i=0; i<n; i++) {
		if (i==n-1 || l[i]!=l[i+1]) {
			s.insert(pos);
			t.insert(make_pair(-cnt, pos));
			val[pos]=cnt;
			cnt=1;
			pos=i+1;
		} else {
			cnt++;
		}
	}
	while (!s.empty()) {
		makni();
		sol++;
	}
	cout << sol;
	return 0;
}