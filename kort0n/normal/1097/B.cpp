#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
int n;
int a[20];

bool bfs(int index, int val){
    if(index == 0){
        return (val % 360 == 0);
    }
    return bfs(index - 1, val + a[index]) || bfs(index - 1, val + 360 - a[index]);
}

int main() {
    //cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(bfs(n, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}