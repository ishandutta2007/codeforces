#include<bits/stdc++.h>
#define N 500000
#define P 29
#define MOD 1791791791
using namespace std;
typedef long long ll;
int n, k;
int pref[N + 1];
int p[N + 1];
string s;

void calc_hash()
{
	p[0] = 1;
	for(int i = 1; i <= N; i++)
	{
		p[i] = ((ll)p[i - 1] * P) % MOD;
	}
	pref[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		pref[i] = ((ll)pref[i - 1] * P + s[i - 1] - 'a') % MOD;
	}
}

int get_hash(int l, int r, int len)
{
	//cout << "Start hash " << l << ' ' << r << ' ' << len << endl;
	if(l <= r)
	{
		int len1 = r - l + 1;
		int minus = ((ll)pref[l] * p[len1]) % MOD;
		//cout << "End hash" << endl;
		return ((ll)pref[r + 1] - minus + MOD) % MOD;
	}
	int h1 = get_hash(l, len - 1, len);
	int h2 = get_hash(0, r, len);
	//cout << "End hash" << endl;
	return ((ll)h1 * p[r + 1] + h2) % MOD;
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
    cin >> n >> k >> s;
    n = min(n, k);
    calc_hash();
    int best = n - 1;
    for(int i = n - 2; i >= 0; i--)
    {
    	int now1 = 0;
    	int now2 = 0;
    	int now = 0;
    	while(now < k)
    	{
    		//cout << 1 << endl;
    		int step = min(best - now1 + 1, i - now2 + 1);
    		if(get_hash(now1, now1 + step - 1, best + 1) == get_hash(now2, now2 + step - 1, i + 1))
    		{
    			now1 = (now1 + step) % (best + 1);
    			now2 = (now2 + step) % (i + 1);
    			now += step;
    			//cout << 2 << endl;
    			continue;
    		}
    		//cout << 3 << endl;
    		int l = -1;
    		int r = step - 1;
    		while(r - l > 1)
    		{
    			int mid = (l + r) / 2;
    			if(get_hash(now1, now1 + mid, best + 1) == get_hash(now2, now2 + mid, i + 1))
    			{
    				l = mid;
    			}
    			else
    			{
    				r = mid;
    			}
    		}
    		if(s[now2 + r] < s[now1 + r])
    		{
    			best = i;
    		}
    		//cout << 4 << endl;
    		break;
    	}
    }
    int now = 0;
    for(int i = 0; i < k; i++)
    {
    	cout << s[now];
    	now = (now + 1) % (best + 1);
    }
}