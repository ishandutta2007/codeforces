#include <bits/stdc++.h>
using namespace std;

void NO()
{
    puts("-1");
    exit(0);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    set<int> now, today;
    vector<int> ret;
    for (auto x : A)
    {
        if (x > 0)
        {
            if (now.count(x) or today.count(x)) NO();
            now.insert(x);
        }
        else
        {
            if (!now.count(-x)) NO();
            now.erase(-x);
            today.insert(-x);
            if (now.empty())
            {
                ret.push_back(today.size() * 2);
                today.clear();
            }
        }
    }
    if (!now.empty()) NO();
    printf("%d\n", (int)ret.size());
    for (auto x : ret) printf("%d ", x);
    puts("");
}