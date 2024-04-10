#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<char> C(26, 'a');
    vector<int> ret;
    for (auto s : S) {
        int t = 0;
        while (C[t] > s) t++;
        C[t] = s;
        ret.push_back(t + 1);
    }
    printf("%d\n", *max_element(ret.begin(), ret.end()));
    for (auto x : ret) printf("%d ", x);
    puts("");
}