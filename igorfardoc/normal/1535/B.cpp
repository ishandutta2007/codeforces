#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int _gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return _gcd(b, a % b);
}

bool cmp(int a, int b)
{
	int am1 = 0;
	int a1 = a;
	while(a1 % 2 == 0 && a1 > 0)
	{
		++am1;
		a1 /= 2;
	}
	int am2 = 0;
	a1 = b;
	while(a1 % 2 == 0 && a1 > 0)
	{
		++am2;
		a1 /= 2;
	}
	if(am1 < am2)
	{
		return true;
	}
	if(am2 < am1)
	{
		return false;
	}
	return a < b;
}

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
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end(), cmp);
    	int ans = 0;
    	for(int i = 0; i < n; i++)
    	{
    		//cout << a[i] << endl;
    		for(int j = i + 1; j < n; j++)
    		{
    			///cout << _gcd(2 * a[i], a[j]) << endl;
    			if(_gcd(2 * a[i], a[j]) > 1)
    			{
    				++ans;
    			}
    		}
    	}
    	//cout << endl;
    	cout << ans << '\n';
    }
}