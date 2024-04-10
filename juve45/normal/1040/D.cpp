#include <bits/stdc++.h>

using namespace std;

long long n, k;
string ans;

int main() {
	cin >> n >> k;
	srand(time(0));
	long long l = 1LL;
	long long r = n;

	while(true) {
		while(r - l + 1 > 99 + 1) {
			long long mid = (l + r) / 2;
			cout << mid << ' ' << r << endl;
			cin >> ans;
			if(ans == "Bad") return 0;
			if(ans == "Yes")
				l = mid - k, r += k;
			else l -= k, r = mid + k;
			l = max(l,1LL);
			r = min(r,n);
		}
		long long kk = l + (rand() % (r - l + 1)); 
		cout << kk << ' ' << kk << endl;
		cin >> ans;
		
		l -= k;
		r += k;
		l = max(l,1LL);
		r = min(r,n);
		if(ans == "Yes") return 0;
		if(ans == "Bad") return 0;
	}
}