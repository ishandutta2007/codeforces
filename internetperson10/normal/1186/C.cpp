#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int asum=0, bsum=0, ans=0;
	string a, b;
	cin >> a >> b;
	for(int x=0; x<b.size(); x++) {
		asum+=(int)(a.at(x)-'0');
		bsum+=(int)(b.at(x)-'0');
	}
	ans+=(1-(abs(asum-bsum)%2));
	for(int x=0; x<((int)a.size()-(int)b.size()); x++) {
		asum-=(int)(a.at(x)-'0');
		asum+=(int)(a.at(x+b.size())-'0');
		ans+=(1-(abs(asum-bsum)%2));
	}
	cout << ans << '\n';
}