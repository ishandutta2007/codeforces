#include <iostream>
#include <algorithm>
using namespace std;

long long MOD = 1e9 + 9;

long long powermod(long long a, long long e) {
    long long result = 1;
    a %= MOD;
    while (e) {
        if (e & 1) result = (result * a) % MOD;
        e /= 2;
        a = (a*a) % MOD;
    }
    return result;
}

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    
    long long wrong = n - m;
    long long correct = m;
    
    long long score = 0;
    
    /*if (correct >= k-1 && wrong > 0)
    {
        score += k-1;
        correct -= k-1;
    }*/
    
    //std::cout << score << ", " << wrong << ", " << correct << endl;
    // at the end wc...c
    if (correct && wrong) {
        long long cnt = std::min(correct / (k-1), wrong);
        score += (k-1)*cnt;
        correct -= (k-1)*cnt;
        wrong -= (k-1);
    }
    
    if (correct == 0) {
        std::cout << score % MOD << std::endl;
    }
    else {
        long long score_before = 0;
        score_before += correct % k;
        score_before += (((powermod(2, correct / k + 1) - 2 + MOD) % MOD) * k ) % MOD;
        std::cout << (score_before + score) % MOD << std::endl;
    }
}