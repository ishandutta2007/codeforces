#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N , M , K;
    cin >> N >> M >> K;
    if(N * M % K && (K % 2 || N * M % (K / 2))){
        puts("NO");
        return 0;
    }
    puts("YES");
    K = 2 * N * M / K;
    long long L = K / N + (K % N ? 1 : 0) , R = L * N - K;
    cout << "0 0\n" << N << " 1\n" << R << ' ' << L;
    return 0;
}