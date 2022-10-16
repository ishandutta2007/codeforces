#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;

int n, k, n1, n2;
long long x, x1, x2;
priority_queue <long long> p;
long long ans1, ans2;

int main()
{
	ios_base::sync_with_stdio(false);


	cin >> n >> n1 >> n2;

	if(n1 > n2)
		swap(n1, n2);
	x1 = n1;
	x2 = n2;

	for(int i=1;i <=n; i++)
		cin >> x, p.push(x);

	while(n1 > 0)
	{
		ans1 += p.top();
		n1--;
		p.pop();
	}
	while(!p.empty() && n2 > 0)
	{
		ans2 += p.top();
		n2--;
		p.pop();
	}
	double ans = 1.*(1.*ans1/x1 + 1.*ans2/x2);
	cout << setprecision(6) << fixed << ans;


	return 0;
}