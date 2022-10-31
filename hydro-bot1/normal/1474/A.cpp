// Hydro submission #628c79d857906f28b5b34971@1653373400948
// Problem: A. Puzzle From the Future
// Contest: Codeforces - Codeforces Round #696 (Div. 2)
// URL: https://codeforces.com/contest/1474/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;

const int N = 50007;

int n, m, t;
string a, b;

int main()
{
    scanf("%d", &t);
    while(t -- ) {
        scanf("%d", &n);
        cin >> b;
        string a = "";
        a += '1';
        int last = 1 + b[0] - '0';
        for(int i = 1; i < b.length(); ++ i) {
            if(last == 2) {
                if(b[i] == '1')
                    a += '0';
                else a += '1';
            }
            else if(last == 1) {
                if(b[i] == '1')
                    a += '1';
                else a += '0';
            }
            else a += '1';
            last = a[i] - '0' + b[i] - '0';
        }
        cout << a << endl;
    }
    return 0;
}