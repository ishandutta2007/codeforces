#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[105];
string v = "aeiouy";

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    scanf(" ");
    FO(i,0,n) {
        string s;
        getline(cin, s);
        for (auto c : s) {
            if (v.find(c) != string::npos) {
                a[i]--;
            }
        }
        if (a[i] != 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}