#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool check(int a, int b)
{
	if(__builtin_popcount(a) < __builtin_popcount(b))
	{
		return false;
	}
	if(__builtin_popcount(a) == __builtin_popcount(b))
	{
		int i0 = 0;
    	int i1 = 0;
    	bool ok = false;
    	for(int j = 0; j < __builtin_popcount(a); j++)
    	{
    		while(!((a >> i0) & 1))
    		{
    			++i0;
    		}
    		while(!((b >> i1) & 1))
    		{
    			++i1;
    		}
    		if(i0 > i1)
    		{
    			return false;
    		}
    		++i0;
    		++i1;
    	}
    	return true;
	}
	else
	{
		int need = __builtin_popcount(a) - __builtin_popcount(b) + 1;
		int now1 = 0;
		while((1 << now1) <= a)
		{
			++now1;
		}
		int now2 = 0;
		while((1 << now2) <= b)
		{
			++now2;
		}
		--now1;
		--now2;
		if(now1 > now2)
		{
			return false;
		}
		if(now1 == now2)
		{
			return check(a ^ (1 << now1), b ^ (1 << now1));
		}
		int here = 1;
		int ch = (1 << now1);
		for(int i = now1 - 1; (i >= 0) && need > here; i--)
		{
			if((a >> i) & 1)
			{
				++here;
				ch |= (1 << i);
			}
		}
		return check(a ^ ch, b ^ (1 << now2));
	}
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
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	if(check(a, b))
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}