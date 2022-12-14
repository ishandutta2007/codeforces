#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7; long long N , K , A[_];

int main(){
    cin >> N >> K; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; A[i] += A[i - 1];}
    long long ans = A[N]; sort(A + 1 , A + N); while(--K) ans += A[N] - A[K];
    cout << ans; return 0;
}