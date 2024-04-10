#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    int N;
    cin >> N;
    map<int, vector<int>> cou;
    REP(i, N) {
        int s;
        cin >> s;
        cou[s].push_back(i);
    }

    string ret(N, 'A');
    vector<int> once;
    vector<vector<int>> twice;
    vector<vector<int>> many;
    for (auto p : cou) {
        if (p.second.size() == 1) once.push_back(p.second[0]);
        else if (p.second.size() == 2) twice.push_back(p.second);
        else many.push_back(p.second);
    }
    if (once.size() % 2 and many.empty()) puts("NO");
    else
    {
        bool b = 0;
        for (auto x : once)
        {
            ret[x] = char('A' + b);
            b = !b;
        }
        if (once.size() % 2)
        {
            ret[many[0][0]] = 'B';
        }
        cout << "YES" << endl;
        cout << ret << endl;
    }
}