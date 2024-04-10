#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[1111];

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x = a[3];
    sort(a + 1, a + n + 1);
    int y = a[1];
    cout << (x ^ y) + 2 << endl;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}