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

int main(int argc, char** argv)
{
	int n, k;
	int freq[101];

	memset(freq, 0, 101 * sizeof(int));

	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;

		++freq[temp];
	}

	int a = 0;

	for(int i = 1; i <= 100; ++i)
	{
		int a_ = freq[i] / k;

		if(freq[i] % k != 0)
			++a_;

		a = max(a, a_);
	}

	int cnt = 0;

	for(int i = 1; i <= 100; ++i)
		if(freq[i] > 0)
			cnt += k * a - freq[i];

	cout << cnt << endl;

    return 0;
}