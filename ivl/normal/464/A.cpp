#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, p;

int main(){
    cin >> n >> p;
    if (p == 1){printf("NO\n"); return 0;}
    string s;
    cin >> s;
    if (p == 2){
        if (n == 1){
            if (s == "a") printf("b\n");
            else printf("NO\n");
        } else {
            if (s == "ab") printf("ba\n");
            else printf("NO\n");
        } return 0;
    }
    for (auto &x : s) x -= 'a';
    for (int i = n-1; i >= 0; --i){
        string t(s.begin(), s.begin()+i);
        REP(p,j) if (j > s[i] && (!i || j != t[i-1]) && (i < 2 || j != t[i-2])){t.pb(j); break;}
        if ((int)t.size() == i) continue;
        REP(n-i-1,j){
            int x = 0;
            if (x == t.back() || (t.size() >= 2 && t[t.size() - 2] == x)) ++x;
            if (x == t.back() || (t.size() >= 2 && t[t.size() - 2] == x)) ++x;
            t.pb(x);
        }
        REP(n,j) printf("%c", t[j] + 'a'); printf("\n"); return 0;
    } printf("NO\n");
    return 0;
}