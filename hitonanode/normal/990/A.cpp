#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    lint N, M, A, B;
    cin >> N >> M >> A >> B;
    cout << min(N % M * B, (M - N % M) % M * A) << endl;
}