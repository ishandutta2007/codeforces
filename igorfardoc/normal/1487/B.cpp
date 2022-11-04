#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	--k;
    	if(n % 2 == 0)
    	{
    		cout << k % n + 1 << '\n';
    		continue;
    	}
    	int mid = n / 2;
    	int amount = k / mid;
    	cout << (amount + k) % n + 1 << '\n';
    }
}