#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, ret;
    cin >> S;
    int n1 = 0;
    for (auto c : S) n1 += (c == '1');
    for (auto c : S) {
        if (c == '2') ret += string(n1, '1'), n1 = 0;
        if (c != '1') ret += c;
    }
    ret += string(n1, '1');
    cout << ret << endl;
}