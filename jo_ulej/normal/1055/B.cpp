#include <bits/stdc++.h>

#define INF 1e9
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
 
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    for(auto elem: vec)
        cout << elem << " ";
 
    return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, const set<T>& a)
{
	for(auto elem: a)
		cout << a << " ";
 
    return os;
}
 
template<typename T>
T max3(T a, T b, T c)
{
    return max(max(a, b), c);
}
 
template<typename T>
T min3(T a, T b, T c)
{
    return min(min(a, b), c);
}
 
template<typename T>
void read_vector(vector<T>& vec, int size)
{
    vec.resize(size);
 
    for(int i = 0; i < size; ++i)
        cin >> vec[i];
}

inline bool check(int k, string s, string t)
{
	if(s.size() > t.size())
		swap(s, t);

	int j = 0;

	while(j < s.size() && s[j] == t[j])
		++j;

	int a = s.size() + t.size() - 2 * j - k;

	return a % 2 == 0 && a <= 0;
}

int main(int argc, char** argv)
{
	ll n, m, L;
	vector<ll> state;
	int segs = 0;

	FAST_IO

	cin >> n >> m >> L;
	state.resize(n);

	for(int i = 0; i < n; ++i)
	{
		ll temp;
		cin >> temp;

		state[i] = temp;
	}

	int i = 0;

	while(i < n)
	{
		if(state[i] <= L)
		{
			++i;
			continue;
		}

		int j = i;

		while(j + 1 < n && state[j + 1] > L)
			++j;

		++segs;
		i = j + 1;
	}

	for(int k = 0; k < m; ++k)
	{
		int type;
		cin >> type;

		if(type == 0)
		{
			cout << segs << endl;
		}
		else
		{
			int p;
			ll d;

			cin >> p >> d;
			--p;

			state[p] += d;

			if(state[p] > L && state[p] - d <= L)
			{
				if(p == 0)
				{
					if(state[p + 1] <= L)
						++segs;
				}
				else if(p == n - 1)
				{
					if(state[p - 1] <= L)
						++segs;
				}
				else
				{
					if(state[p - 1] > L && state[p + 1] > L)
						--segs;
					else if(state[p - 1] <= L && state[p + 1] <= L)
						++segs;
				}
			}
		}
	}

	return 0;
}