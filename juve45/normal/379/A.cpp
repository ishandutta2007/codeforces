#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	long long ans = 0, cnt = 0;
	while(n)
	{
		n--;
		ans++;
		cnt++;
		if(cnt == k){
			cnt = 0;
			n++;
		}
	}
	cout << ans;
	return 0;
}