#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<char> C(3, 'a');
    vector<int> ret;
    for (auto s : S) {
        int t = 0;
        while (C[t] > s) t++;
        if (t > 1) {
            puts("NO");
            return 0;
        }
        C[t] = s;
        ret.push_back(t);
    }
    puts("YES");
    for (auto x : ret) printf("%d", x);
    puts("");
}