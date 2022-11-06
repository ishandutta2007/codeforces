#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int ax[8], ay[8];

bool good(int x, int y){
    return !((ax[3] <= x && ax[4] >= x && ay[3] <= y && ay[4] >= y)||(ax[5] <= x && ax[6] >= x && ay[5] <= y && ay[6] >= y));
}

int main(){
    for(int i = 1; i <= 6; i++){
        cin >> ax[i] >> ay[i];
        ax[i] *= 2;
        ay[i] *= 2;
    }
    for(int x = ax[1]; x <= ax[2]; x++){
        if(good(x, ay[1]) || good(x, ay[2])){
            cout << "YES\n"; return 0;
        }
    }
    for(int y = ay[1]; y <= ay[2]; y++){
        if(good(ax[1], y) || good(ax[2], y)){
            cout << "YES\n"; return 0;
        }
    }
    cout << "NO\n";
    return 0;
}