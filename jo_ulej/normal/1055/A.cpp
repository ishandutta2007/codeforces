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
	int n, s;
	vector<int> a, b;

	cin >> n >> s;

	read_vector(a, n);
	read_vector(b, n);

	--s;

	if(!a[0])
	{
		cout << "NO" << endl;

		return 0;
	}

	if(a[s])
	{
		cout << "YES" << endl;

		return 0;
	}

	if(b[s])
	{
		for(int i = s + 1; i < n; ++i)
		{
			if(a[i] && b[i])
			{
				cout << "YES" << endl;

				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}