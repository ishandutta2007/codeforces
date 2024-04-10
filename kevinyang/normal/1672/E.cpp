#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int low = 0; int high = (int)1e7; int mid = (low+high)/2;
    int rq = 0;
    while(low+1<high){
        cout << "? " << mid << endl;
        int h;
        cin >> h;
        if(h==1){
            high = mid;
        }
        else{
            low = mid;
        }
        mid = (low+high)/2;
    }
    int len = high+1;//length + n
    int ans = high;
    for(int i = 2; i<=n; i++){
        int v = (len-1)/i;
        cout << "? " << v << endl;
        int h;
        cin >> h;
        if(h!=0){
            ans = min(ans,h*v);
        }
    }
    cout << "! " << ans << endl;
    return 0;
}