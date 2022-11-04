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
    	int n;
    	cin >> n;
    	ll sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		int a;
    		cin >> a;
    		sum += a;
    	}
    	int fir = sum % n;
    	int sec = n - fir;
    	cout << (ll)fir * sec << '\n';
    }
}