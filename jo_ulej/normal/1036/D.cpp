#include <bits/stdc++.h>
 
#define INF 1e9
 
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
    cout << "{";
    int i = 0;
 
    for(auto elem: a)
    {
        cout << elem;
 
        if(i != a.size() - 1)
            cout << ", ";
 
        ++i;
    }
 
    cout << "}";
 
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

int main(int argc, char** argv)
{
	int n, m;
	vector<int> a, b;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	read_vector(a, n);

	cin >> m;
	read_vector(b, m);

	int i = 0;
	int j = 0;
	int ans = 1;

	ll a_sum = a[i];
	ll b_sum = b[j];

	for(;;)
	{
		if(a_sum < b_sum)
		{
			if(i + 1 < n)
			{
				a_sum += a[++i];
			}
			else
			{
				cout << "-1" << endl;

				return 0;
			}
		}
		else if(a_sum > b_sum)
		{
			if(j + 1 < m)
			{
				b_sum += b[++j];
			}
			else
			{
				cout << "-1" << endl;

				return 0;
			}
		}
		else
		{
			if(i == n - 1 && j == m - 1)
				break;

			if(i == n - 1 || j == m - 1)
			{
				cout << "-1" << endl;

				return 0;
			}

			++ans;

			a_sum = a[++i];
			b_sum = b[++j];
		}
	}

	cout << ans << endl;

    return 0;
}