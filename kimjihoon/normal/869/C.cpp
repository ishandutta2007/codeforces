#include <iostream>
using namespace std;

long long m[5009][5009];

long long ch(long long n, long long k)
{
    if (n < k){
        long long t = n; n = k; k = t;
    }
    for (int i = 0; i <= n; i++){
        m[0][i] = m[i][0] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k && j <= i; j++){
            if (i == j)
                m[i][j] = (m[i-1][j-1] * j + m[i][j-1]) % 998244353;
            else
                m[i][j] = (m[i-1][j-1] * j + m[i-1][j]) % 998244353;
        }
    }
    return m[n][k];
}

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    cout<<(((ch(a, b) * ch(b, c)) % 998244353) * ch(a, c)) % 998244353<<endl;
    return 0;
}