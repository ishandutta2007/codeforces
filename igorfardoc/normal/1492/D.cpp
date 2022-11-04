#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, k;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> b >> a >> k;
    vector<bool> k1(a + b, false);
    vector<bool> y1(a + b, false);
    if(a - 1 <= k)
    {
    	for(int i = 0; i < k; i++)
    	{
    		k1[a + b - 1 - i] = true;
    	}
    	y1[0] = 1;
    	for(int i = 0; i < a - 1; i++)
    	{
    		y1[a + b - 1 - i] = true;
    	}
    }
    else
    {
    	for(int i = 0; i < k; i++)
    	{
    		k1[a + b - 1 - i] = true;
    		y1[a + b - 1 - i] = true;
    	}
    	for(int i = 0; i < a - k; i++)
    	{
    		y1[i] = true;
    	}
    }
    int now = 0;
    int am1 = 0;
    int am2 = 0;
    vector<bool> x1(a + b, false);
    for(int i = a + b - 1; i >= 0; i--)
    {
    	if(y1[i])
    	{
    		++am1;
    	}
    	int here = now + y1[i] + k1[i];
    	x1[i] = here % 2;
    	if(x1[i])
    	{
    		++am2;
    	}
    	if(here > 1)
    	{
    		now = 1;
    	}
    	else
    	{
    		now = 0;
    	}
    }
    if(now == 0 && x1[0] == 1 && y1[0] == 1 && am1 == a && am2 == a)
    {
    	cout << "Yes\n";
    	for(int i = 0; i < a + b; i++)
    	{
    		cout << (int)x1[i];
    	}
    	cout << '\n';
    	for(int i = 0; i < a + b; i++)
    	{
    		cout << (int)y1[i];
    	}
    }
    else
    {
    	cout << "No\n";
    }
}