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
	string str;
	cin >> str;

	int s = str.size();
	//int s;
	//cin >> s;

	//string str;

	for(int i = 0; i < s; ++i)
		str += 'A';

	int best_rows = INF;
	int best_cols = INF;

	for(int rows = 1; rows <= 5; ++rows)
	{
		int cols = s / rows;

		if(s % rows != 0)
			++cols;

		if(cols <= 20)
		{
			if(rows < best_rows || rows == best_rows && cols < best_cols)
			{
				best_rows = rows;
				best_cols = cols;
			}
		}
	}

	cout << best_rows << " " << best_cols << endl;
	int t = best_rows * best_cols - s;

	vector<string> answer;

	for(int start = 0; start < s;)
	{
		int len = best_cols;

		if(answer.size() >= best_rows - t)
			--len;

		//cout << "len=" << len << endl;

		int end = start + len - 1;

		answer.push_back(str.substr(start, len));

		while(answer[answer.size() - 1].size() < best_cols)
			answer[answer.size() - 1] += '*';

		start = end + 1;
	}

	for(string elem: answer)
		cout << elem << endl;

    return 0;
}