#include<bits/stdc++.h>
using namespace std;

int num[200010] , N;

int main(){
    scanf("%d" , &N);
    for(int i = 1 ; i <= N << 1 ; ++i)
        cin >> num[i];
    sort(num + 1 , num + (N << 1) + 1);
    long long ans = 1ll * (num[N] - num[1]) * (num[N << 1] - num[N + 1]);
    for(int i = 1 ; i <= N ; ++i)
        ans = min(ans , 1ll * (num[N << 1] - num[1]) * (num[i + N - 1] - num[i]));
    cout << ans;
}