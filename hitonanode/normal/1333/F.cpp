#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> cnt(N + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i * 2; j <= N; j += i) cnt[j]++;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i * 2; j <= N; j += i)
        {
            cnt[j]--;
            if (!cnt[j]) printf("%d ", i);
        }
    }
}