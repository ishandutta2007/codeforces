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

lint n, m;

lint to(pair<int, int> i)
{
    return i.first*m + i.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int k, x, y;
    cin >> n >> m >> k;

    vector<string> v;
    FOR(i, n)
    {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    unordered_map<lint, int> map1;

    int d1[] = {0, 1, 0, -1};
    int d2[] = {1, 0, -1, 0};

    FOR(i, k)
    {
        cin >> x >> y;

        pair<int, int> q(x-1, y-1);
        lint index = to(q);

        if (map1.count(index))
        {
            cout << map1[index] << endl;
            continue;
        }

        unordered_set<lint> set1;
        stack<pair<int, int>> stack;

        stack.push(q);
        set1.insert(index);
        int count = 0;

        while (stack.size())
        {
            auto p = stack.top();
            stack.pop();

            FOR(a, 4)
            {
                if (v[p.first+d1[a]][p.second+d2[a]] == '.') {
                    auto P = make_pair(p.first + d1[a], p.second + d2[a]);
                    lint idx = to(P);
                    if (!set1.count(idx)) {
                        stack.push(P);
                        set1.insert(idx);
                    }
                }
                else
                    count++;

            }

        }

        for(auto p : set1)
            map1[p] = count;

        cout << count << endl;

    }
}