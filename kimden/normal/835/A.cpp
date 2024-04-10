#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int x1 = t1 + s * v1 + t1;
    int x2 = t2 + s * v2 + t2;
    if(x1 < x2){
        cout << "First" << endl;
        return 0;
    }
    if(x1 > x2){
        cout << "Second" << endl;
        return 0;
    }
        cout << "Friendship" << endl;


    return 0;
}