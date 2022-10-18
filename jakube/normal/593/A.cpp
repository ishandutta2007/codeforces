#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;

typedef long long int lint;
typedef long double ld;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>

template<typename T>
vector<T> reads(int count){
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n = readi();
    vector<string> words = reads<string>(n);

    vector<vector<int>> v(26, vector<int>(26, 0));

    int max_total = 0;

    for (string word : words)
    {
        set<char> s;
        for (char c : word)
            s.insert(c);
        if (s.size() == 2)
        {
            int idx1t = *s.begin() - 'a';
            int idx2t = *(++s.begin()) - 'a';
            int idx1 = min(idx1t, idx2t);
            int idx2 = max(idx1t, idx2t);
            v[idx1][idx2] += word.length();
            if (v[idx1][idx2] > max_total)
            {
                max_total = v[idx1][idx2];
            }
        }
        if (s.size() == 1)
        {
            int idx1t = *s.begin() - 'a';
            for (int i = 0; i < 26; i++)
            {
                int idx1 = min(idx1t, i);
                int idx2 = max(idx1t, i);
                v[idx1][idx2] += word.length();
                if (v[idx1][idx2] > max_total)
                {
                    max_total = v[idx1][idx2];
                }
            }
        }
    }

    cout << max_total;

}