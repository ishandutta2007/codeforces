#include <iostream>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;

struct upg
{
	int which;
	int typ;
	ll val;
	ll num;
	ll den;
	int id;
	upg(int W=0, int T=0, ll V=0, int I=-1) : which(W), typ(T), val(V), num(0), den(0), id(I)
	{ }
	bool operator< (const upg& oth) const
	{
		if (den != 0ll)
			return ((num-den)*oth.den > (oth.num-oth.den)*den);
		return (val < oth.val);
	}
};

multiset<pair<ll, int> > asgnmt[100002];
multiset<pair<int, int> > ans;
multiset<upg> add[100002];
multiset<upg> choose;
ll a[100002];
int k;
int n;
int m;

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	cin >> k >> n >> m;
	for (int i = 0;i < k;i++)
		cin >> a[i];
	for (int i = 0;i < n;i++)
	{
		upg tmp;
		cin >> tmp.typ >> tmp.which >> tmp.val;
		tmp.which--;
		tmp.id = i+1;
		if (tmp.typ == 1)
			asgnmt[tmp.which].insert(make_pair(tmp.val, tmp.id));
		else if (tmp.typ == 2)
			add[tmp.which].insert(upg(tmp.which, tmp.typ, tmp.val, tmp.id));
		else
		{
			tmp.num = tmp.val;
			tmp.den = 1ll;
			choose.insert(tmp);
		}
	}
	for (int i = 0;i < k;i++) if (!asgnmt[i].empty() && (*asgnmt[i].rbegin()).first > a[i])
		add[i].insert(upg(i, 1, (*asgnmt[i].rbegin()).first-a[i], (*asgnmt[i].rbegin()).second));
	for (int i = 0;i < k;i++)
	{
		ll tot = a[i];
		for (auto it = add[i].rbegin();it != add[i].rend();it++)
		{
			ll tmp = tot + (*it).val;
			upg toadd;
			toadd.which = i;
			toadd.typ = (*it).typ;
			toadd.num = tmp;
			toadd.den = tot;
			toadd.id = (*it).id;
			choose.insert(toadd);
			tot = tmp;
		}
	}
	while (choose.size() > m)
		choose.erase(--choose.end());
	for (const auto& tmp : choose)
		ans.insert(make_pair(tmp.typ, tmp.id));
	cout << ans.size() << "\n";
	for (auto& tmp : ans)
		cout << tmp.second << " ";
	cout << "\n";
	return 0;
}