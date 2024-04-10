#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, N, S, P;
    cin >> K >> N >> S >> P;
    int nb = (N + S - 1) / S;
    cout << (nb * K + P - 1) / P << "\n";
}