#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N >> s;
    sort(s.begin(), s.end());
    cout << s;
    return 0;
}