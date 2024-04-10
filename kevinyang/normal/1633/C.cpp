#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int h,d;
        cin >> h >> d;
        int h2,d2;
        cin >> h2 >> d2;
        int k,w,a;
        cin >> k >> w >> a;
        bool f = false;
        for(int i = 0; i<=k; i++){
            int hp = i*a+h; int dmg = d+(k-i)*w;
            int rq = (h2+dmg-1)/dmg;
            int rq2 = (hp+d2-1)/d2;
            if(rq<=rq2)f = true;
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}