#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, c;
    cin >> n >> c;
    int a[500050];
    int ans = 0;
    int Default = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == c) Default++;
    }
    ans = Default;
    int number[500050];
    int mini[500050];
    int on = 0;
    for(int i = 1; i <= 500000; i++){
        number[i] = 0;
        mini[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        int now = a[i];
        if(now == c){
            on++;
            continue;
        }
        number[now]++;
        int New = number[now] - on;
        mini[now] = min(mini[now], New - 1);
        //cout << i << " " << now << " " << New << endl;
        ans = max(ans, Default + New - mini[now]);
    }
    cout << ans << endl;
    return 0;
}