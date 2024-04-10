#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fail return 0*printf("NO\n")

struct vec
{
	ll x, y;
	ll sz() const { return x*x+y*y; }
	ll operator^ (const vec oth) const { return x*oth.y-y*oth.x; }
	ll operator* (const vec oth) const { return x*oth.x+y*oth.y; }
	vec operator- (const vec oth) const { return vec{x-oth.x, y-oth.y}; }
};

vector<vec> rd(int n)
{
	vector<vec> pt(n), res;
	for (int i = 0;i < n;i++) scanf("%lld%lld", &pt[i].x, &pt[i].y);
	sort(pt.begin(), pt.end(), [](vec a, vec b)->bool { return a.x!=b.x?a.x<b.x:a.y<b.y; });
	sort(pt.begin()+1, pt.end(), [&](vec a, vec b)->bool {
		if (((a-pt[0])^(b-pt[0])) != 0) return ((a-pt[0])^(b-pt[0])) > 0;
		return (a-pt[0]).sz() < (b-pt[0]).sz();
	});
	for (vec u: pt)
	{
#define m ((int)res.size())
		while (m >= 2 && ((u-res[m-2])^(res[m-1]-res[m-2])) >= 0) res.pop_back();
		res.push_back(u);
#undef m
	}
	return res;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	vector<vec> p1 = rd(n);
	vector<vec> p2 = rd(m);
	if (p1.size() != p2.size()) fail;
	n = p1.size();
	for (int i = 0;i < n;i++) p1.push_back(p1[i]), p2.push_back(p2[i]);
	for (int i = 0;i < n;i++) p1.push_back(p1[i]), p2.push_back(p2[i]);
	for (int i = 0;i < n;i++)
	{
		// integer coordinates so probably not too many chances to go astray?
		bool ok = true;
		for (int j = 0;j < n && ok;j++)
		{
			if ((p1[j+1]-p1[j]).sz() != (p2[i+j+1]-p2[i+j]).sz()) ok = false;
			if ((p1[j+2]-p1[j+1])*(p1[j]-p1[j+1]) != (p2[i+j+2]-p2[i+j+1])*(p2[i+j]-p2[i+j+1])) ok = false;
		}
		if (ok) return 0*printf("YES\n");
	}
	fail;
	return 0;
}