#include<bits/stdc++.h>


int main()
{
    long long n;
    std::cin >> n;
    long long ans = 0, q = 1;
    n--;
    while (n > 0)
    {
        ans += n * (q - q / 2);
        q *= 2;
        n /= 2;
    }
    std::cout << ans;
}