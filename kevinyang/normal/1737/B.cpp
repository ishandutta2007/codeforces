#include <bits/stdc++.h>
using namespace std;
#define int long long
int bs(int x){
    int low = 1; int high = (int)2e9; int mid = (low+high)/2;
    while(low+1<high){
        if(mid*mid<=x){
            low = mid;
        }
        else{
            high = mid;
        }
        mid = (low+high)/2;
    }
    return low;
}
int bs2(int x){
    int low = 1; int high = (int)2e9; int mid = (low+high)/2;
    while(low+1<high){
        if(mid*mid-1<=x){
            low = mid;
        }
        else{
            high = mid;
        }
        mid = (low+high)/2;
    }
    return low-1;
}
int bs3(int x){
    int low = 0; int high = (int)2e9; int mid = (low+high)/2;
    while(low+1<high){
        if(mid*(mid+1)<=x){
            low = mid;
        }
        else{
            high = mid;
        }
        mid = (low+high)/2;
    }
    return low;
}
int f(int x){
    if(x==0) return 0;
    return bs(x)+bs2(x)+bs3(x);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        cout << f(y) - f(x-1) << "\n";
    }
    return 0;
}