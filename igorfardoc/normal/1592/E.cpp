#include<bits/stdc++.h>
#define LOG 19
using namespace std;
typedef long long ll;

bool get_bit(int a, int b)
{
	return (a >> b) & 1;
}
void set_bit(int& a, int b, bool val)
{
	if(get_bit(a, b) == val)
	{
		return;
	}
	a ^= (1 << b);
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pref(n + 1);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    for(int i = 0; i <= LOG; i++)
    {
    	for(int j = 1; j <= n; j++)
    	{
    		set_bit(pref[j], i, get_bit(pref[j - 1], i) ^ ((a[j - 1] >> i) & 1));
    	}
    }
    int ans = 0;
    for(int i = LOG; i >= 0; i--)
    {
    	int prev = -1;
    	for(int j = 0; j <= n; j++)
    	{
    		if(prev != -1 && (j == n || !((a[j] >> i) & 1)))
    		{
    			int l = prev;
    			int r = j - 1;
    			//cout << l << ' ' << r << ' ' << i << endl;
    			map<int, int> s1, s2;
    			for(int k = r; k >= l; --k)
    			{
    				map<int, int>* now;
    				map<int, int>* other;
    				if(k % 2 == 0)
    				{
    					now = &s1;
    					other = &s2;
    				}
    				else
    				{
    					now = &s2;
    					other = &s1;
    				}
    				auto it = now->find(pref[k] >> (i + 1) << (i + 1));
    				if(it != now->end())
    				{
    					ans = max(ans, (*it).second - k + 1);
    					//cout << l << ' ' << r << ' ' << ans << endl;
    				}
    				it = other->find(pref[k + 1] >> (i + 1) << (i + 1));
    				if(it == other->end())
    				{
    					//cout << (pref[k + 1] >> (i + 1) << (i + 1)) << ' ' << k << endl;
    					(*other)[pref[k + 1] >> (i + 1) << (i + 1)] = k;
    				}
    			}
    			prev = -1;
    		}
    		if((a[j] >> i) & 1)
    		{
    			if(prev == -1)
    			{
    				prev = j;
    			}
    		}
    	}
    }
    cout << ans;
}