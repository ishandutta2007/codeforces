#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void dfs(int height, bool state)
{
    if (height == 0) return;
    dfs(height - 1, !state);
    v.push_back(state);
    dfs(height - 1, state);
}

int main()
{
    int N;
    cin >> N;
    dfs(32 - __builtin_clz(N) - 1, 1);
    int n = v.size();
    for (int i = 0; i < (int)v.size() - 1; i++) n += (v[i] == v[i + 1]);
    cout << (n == N or n + 1 == N) << endl;
}