#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    char c[100002];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    a--;
    b--;
    if(c[a] == c[b]){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
    return 0;
}