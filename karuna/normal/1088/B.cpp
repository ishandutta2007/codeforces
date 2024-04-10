#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    scanf("%lld %lld", &n, &k);

    ll arr[100005] = {0};
    for (ll i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }

    sort(arr, arr+n);
    ll temp = 0;
    ll cnt = 0;
    ll i = 0;

    while (cnt < k && i<n) {
        printf("%lld\n", arr[i]);
        temp += arr[i];
        cnt++;

        while (arr[i] <= temp && i<n) i++;
        arr[i] -= temp;
    }

    for (ll j=0; j<k-cnt; j++){
        printf("0\n");
    }
}