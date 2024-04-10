#include <bits/stdc++.h>
 
#define INF 1e9
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
 
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

vector<pair<int, int>> pfreq;

bool check(int l, int k)
{
	int a = 0;

	for(auto elem: pfreq)
	{
		if(elem.first == 0)
			break;

		a += elem.first / l;
		
		if(a >= k)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	int n, k;
	vector<int> s, freq;

	FAST_IO

	cin >> n >> k;
	read_vector(s, n);

	freq.resize(200101);

	for(int x: s)
		++freq[x];

	for(int x = 1; x < freq.size(); ++x)
		if(freq[x] != 0)
			pfreq.emplace_back(freq[x], x);

	sort(pfreq.begin(), pfreq.end());
	reverse(pfreq.begin(), pfreq.end());

	int l = 1;
	int r = n;

	while(r - l > 1)
	{
		int m = (l + r) / 2;

		if(check(m, k))
			l = m;
		else
			r = m;
	}

	int d = l;

	if(check(r, k))
		d = r;
	
	int a = 0;
	for(auto elem: pfreq)
	{
		if(elem.first == 0)
			break;

		a += elem.first / d;

		if(a <= k)
		{
			for(int i = 0; i < elem.first / d; ++i)
				cout << elem.second << " ";

		}

		if(a > k)
		{
			for(int i = 0; i < k - a + elem.first / d; ++i)
				cout << elem.second << " ";
		}


		if(a >= k)
			break;
	}

    return 0;
}