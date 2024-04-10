#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

typedef long long int ll;

using namespace std;

struct Seq
{
	string s;

	int d;
};

vector<Seq> seqs;

void add_str(const string& s)
{
	int d = 0;
	int min_d = 0;

	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '(')
			++d;
		else
			--d;

		if(d < min_d)
			min_d = d;
	}

	if(d <= 0 && min_d - d < 0)
		return;

	if(d >= 0 && min_d < 0)
		return;

	Seq seq;
	seq.s = s;
	seq.d = d;

	seqs.push_back(seq);
}

int main(int argc, char** argv)
{
	int n;
	string s;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		add_str(s);
	}

	sort(seqs.begin(), seqs.end(), [](Seq a, Seq b) {
		return abs(a.d) < abs(b.d);
	});

	ll ans = 0;

	for(int i = 0; i < seqs.size();)
	{
		int abs_d = abs(seqs[i].d);
		int j;

		ll pos = 0;
		ll neg = 0;
		ll zer = 0;

		for(j = i; abs(seqs[j].d) == abs_d && j < seqs.size(); ++j)
		{
			if(seqs[j].d > 0)
			{
				++pos;
			}
			else if(seqs[j].d < 0)
			{
				++neg;
			}
			else
			{
				++zer;
			}
		}

		//cout << "j=" << j << endl;
		//cout << "pos,neg,zer=" << pos << "," << neg << "," << zer << endl;

		ans += pos * neg + zer * zer;

		i = j;
	}

	cout << ans << endl;

	return 0;
}