#include <iostream>
#include <set>

using namespace std;

#define MOD  1000000009ll

typedef long long ll;
struct block;

struct block2
{
	ll id;
	int x;
	int y;
	block2(ll I, int X, int Y) : id(I), x(X), y(Y)
	{ }
	bool operator< (const block2& oth) const
	{
		return (id < oth.id);
	}
	operator block() const;
};

struct block
{
	ll id;
	int x;
	int y;
	block(ll I, int X, int Y) : id(I), x(X), y(Y)
	{ }
	bool operator< (const block& oth) const
	{
		if (x != oth.x) return (x < oth.x);
		return (y < oth.y);
	}
	operator block2() const
	{
		return block2(id, x, y);
	}
};

block2::operator block() const
{
	return block(this->id, this->x, this->y);
}

set<block2> open;
set<block> todo;
ll ans;
ll n;

bool can(const block& u)
{
	for (int i = -1;i <= 1;i++) if (todo.find(block(-1, u.x+i, u.y+1)) != todo.end())
	{
		int num = 0;
		for (int j = -1;j <= 1;j++) if (i+j != 0 && todo.find(block(-1, u.x+i+j, u.y)) != todo.end())
			num++;
		if (num == 0)
			return false;
	}
	return true;
}

void revalidate(int x, int y)
{
	auto it = todo.find(block(-1, x, y));
	if (it != todo.end())
	{
		if (open.find(*it) != open.end())
			return;
		if (can(*it))
			open.insert(*it);
	}
}

void recheck(int x, int y)
{
	auto it = todo.find(block(-1, x, y));
	if (it != todo.end())
	{
		if (open.find(*it) == open.end())
			return;
		if (!can(*it))
			open.erase(*it);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin >> n;
	for (ll i = 0;i < n;i++)
	{
		int x, y; cin >> x >> y;
		todo.insert(block(i, x, y));
	}
	for (const block& u : todo) if (can(u))
		open.insert(u);
	for (int i = 0;i < n;i++)
	{
		block2 u(0, 0, 0);
		if (i&1)
		{ u = *open.begin(); open.erase(open.begin()); }
		else
		{ u = *open.rbegin(); open.erase(--open.end()); }
		ans = (ans*n+u.id) % MOD;
		todo.erase(u);
		for (int j = -1;j <= 1;j++)
			revalidate(u.x+j, u.y-1);
		for (int j = -2;j <= 2;j++)
			recheck(u.x+j, u.y);
	}
	cout << ans << "\n";
	return 0;
}