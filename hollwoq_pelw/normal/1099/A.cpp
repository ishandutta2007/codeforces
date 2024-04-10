#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    IOS;
    int w,h,w1,d1,w2,d2;
    cin >> w >> h >> w1 >> d1 >> w2 >> d2;
    for (int i = h; i>=0; i--){
        w += i;
        if (i == d1) w = max(0, w-w1);
        if (i == d2) w = max(0, w-w2);
    }
    cout << w;
    return 0;
}