#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N , M , K;

bool check(ll mid){
    ll sum = 0;
    for(int i = 1 ; i <= N && sum < K ; i++)
        sum += min(M , mid / i);
    return sum >= K;
}

int main(){
    cin >> N >> M >> K;
    ll L = 1 , R = N * M;
    while(L < R){
        ll mid = L + R >> 1;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << L;
    return 0;
}