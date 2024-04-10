#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 += s2;
    sort(s1.begin(), s1.end());
    sort(s3.begin(), s3.end());
    cout << (s1 == s3 ? "YES" : "NO") << endl;
    return 0;
}