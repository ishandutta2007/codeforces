#include <bits/stdc++.h>

using namespace std;

vector<long long int> divisors;

long long int factorNum(long long int n) {
	long long int ans=1;
	for(long long int b=2; b*b<=n; b++) {
		long long int curr=1;
		while(n%b==0) {
			n/=b;
			curr++;
		}
		ans*=curr;
	}
	if(n==1) return ans;
	return ans*2;
}

int main() {
	//for(int a=1; a<100; a++) cout << a << " | " << factorNum(a) << '\n';
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int a=0; a<n; a++) {
			long long int d, ans;
			cin >> d;
			divisors.push_back(d);
		}
		sort(divisors.begin(), divisors.end());
		long long int ans=divisors[0]*divisors[n-1];
		for(int a=1; a<=n/2; a++) {
			int b=n-a-1;
			if(divisors[a]*divisors[b]!=ans) {
				ans=-1;
				break;
			}
		}
		if(ans>0) {
			if(factorNum(ans)!=n+2) ans=-1;
		}
		cout << ans << '\n';
		vector<long long int>().swap(divisors);
	}
}