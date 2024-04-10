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

int main(int argc, char** argv)
{
	int n, cnt = 0;
	vector<int> arr;

	cin >> n;
	read_vector(arr, n);

	for(int i = 1; i < n - 1; ++i)
	{
		if(arr[i] == 0 && arr[i - 1] == 1 && arr[i + 1] == 1)
		{
			arr[i + 1] = 0;
			++cnt;
		}
	}

	cout << cnt << endl;

    return 0;
}