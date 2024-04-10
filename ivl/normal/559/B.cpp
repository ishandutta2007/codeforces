#include <cstdio>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <unistd.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pii pair < int, int >
#define x first
#define y second
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

string A, B;

string Lower(string s){
    int t = s.size();
    if (t % 2 == 1) return s;
    string x = Lower(string(s.begin(), s.begin() + t/2));
    string y = Lower(string(s.begin() + t/2, s.begin() + t));
    if (x < y) return x + y;
    else return y + x;
}

int main(){
    cin >> A >> B;
    A = Lower(A), B = Lower(B);
    if (A == B) printf("YES\n"); else printf("NO\n");
    return 0;
}