#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    
    int s1 = 5*(h % 12) + 1;
    int s2 = m;
    int s3 = s;
    if (s2 % 5 == 0 && s3 > 0)
        s2++;

    t1 *= 5;
    t2 *= 5;

    vector<int> v = {s1, s2, s3};
    sort(v.begin(), v.end());
    
    bool possible = false;
    if (v[0] < t1 && t1 < v[1] && v[0] < t2 && t2 < v[1]) {
        possible = true;
    }
    if (v[1] < t1 && t1 < v[2] && v[1] < t2 && t2 < v[2]) {
        possible = true;
    }
    if ((t1 > v[2] || t1 < v[0]) && (t2 > v[2] || t2 < v[0])) {
        possible = true;
    }

    if (possible) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}