#include <bits/stdc++.h>
using namespace std;

int f(int x) {
	if (x == 1) return 0;
	else if (x%2 == 1) return f(x+1)+1;
	else return 1+f(x/2);
}

int main () {
	int n;
	cin >> n;
	int op=0;
	int ans = 1;
	set<int> st;
	for (int i=2;i<=n;++i) {
		int cnt=0;
		while (n%i == 0) {
			++cnt;
			n /= i;
		}
		if (!cnt) continue;
		ans *= i;
		st.insert(cnt);
		cerr << "i = " << i << " , cnt = " << cnt << endl;
		//op = max(op,f(cnt));
	}
	if (st.size() == 0) {
		cout << ans << ' ' << 0 << endl;
		return 0;
	}
	if (st.size() == 1) {
		int x = *st.begin();
		int p=1;
		int xx=x;
		while (x) {
			x>>=1;
			p<<=1;
		}
		int pre=1;
		if (xx == p/2) p = xx,pre=0;
		cerr << "p = " << p << endl;
		cout << ans << ' ' << f(p)+pre << endl;
		return 0;
	}
	int x = *(--st.end());
	int p=1;
	int xx=x;
	while (x) {
		x>>=1;
		p<<=1;
	}
	if (xx == p/2) p = xx;
	cout << ans << ' ' << f(p)+1 << endl;
}