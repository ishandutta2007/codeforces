#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;

bool ans(int x)
{
	cout << x << endl;
	int val;
	cin >> val;
	return val;
}

vector<int> get_ch(int a)
{
	vector<int> res(20, 0);
	for(int i = 0; i < 20; i++)
	{
		res[19 - i] = a % k;
		a /= k;
	}
	return res;
}
int get_good(vector<int> a)
{
	int res = 0;
	ll now = 1;
	for(int i = 0; i < 20; i++)
	{
		res += now * a[19 - i];
		now *= k;
		if(now > 300000000)
		{
			break;
		}
	}
	return res;
}

void invert(vector<int>& a)
{
	for(int i = 0; i < 20; i++)
	{
		a[i] = (k - a[i]) % k;
	}
}

vector<int> sum(vector<int> a, vector<int> b)
{
	vector<int> res(20);
	for(int i = 0; i < 20; i++)
	{
		res[i] = (a[i] + b[i]) % k;
	}
	return res;
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
    /*int a;
    cin >> a >> k;
    auto res = get_ch(a);
    for(int i = 0; i < 20; i++)
    {
    	cout << res[i] << ' ';
    }
    cout << endl << get_good(res) << endl;
    return 0;*/
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> k;
    	vector<int> now(20, 0);
    	for(int i = 0; i < n; i++)
    	{
    		auto ch = get_ch(i);
    		if(i % 2 == 1)
    		{
    			invert(ch);
    		}
    		auto here = sum(now, ch);
    		if(ans(get_good(here)))
    		{
    			break;
    		}
    		invert(now);
    		now = sum(now, here);
    	}
    }
}