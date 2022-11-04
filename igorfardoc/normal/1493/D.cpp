#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> mn(int x)
{
	//cout << 1 << endl;
	vector<int> res;
	int now;
	for(now = 2; now * now <= x; now++)
	{
		while(x % now == 0)
		{
			res.push_back(now);
			x /= now;
		}
	}
	if(x != 1)
	{
		res.push_back(x);
	}
	//cout << 2 << endl;
	return res;
}

vector<set<pair<int, int> > > s(200001);
vector<unordered_map<int, int> > d(200001);
int gcd1 = 1;
int mod = 1000000007;
int n, q;
void add(int pos, int x)
{
	auto mass = mn(x);
	for(int i = 0; i < mass.size(); i++)
	{
		//cout << pos << ' ' << mass[i] << endl;
		//cout << 1 << endl;
		int here = mass[i];
		int am = d[here][pos]++;
		int bef = 0;
		if(s[here].size() == n)
		{
			bef = (*(s[here].begin())).first;
		}
		//cout << 2 << endl;
		if(am != 0)
		{
			s[here].erase(s[here].find({am, pos}));
		}
		s[here].insert({am + 1, pos});
		int after = 0;
		if(s[here].size() == n)
		{
			after = (*(s[here].begin())).first;
		}
		if(bef != after)
		{
			gcd1 = ((ll)gcd1 * here) % mod;
		}
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
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
    	add(i, a[i]);
    }
    //cout << 123 << endl;
    for(int i = 0; i < q; i++)
    {
    	int pos, x;
    	cin >> pos >> x;
    	--pos;
    	add(pos, x);
    	cout << gcd1 << '\n';
    }
}