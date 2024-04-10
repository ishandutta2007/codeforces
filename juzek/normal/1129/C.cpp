#include <cstdio>
#include <algorithm>
#include <set>

long long ile[3007][3007];
long long sumIle[3007];
char s[3007];

std::set<std::pair<long long, long long>> byly;

bool sprawdz(int pos) {
    if (s[pos] == 1 && s[pos - 1] == 1 && s[pos - 2] == 0 && s[pos - 3] == 0)
        return false;
    if (s[pos] == 1 && s[pos - 1] == 0 && s[pos - 2] == 1 && s[pos - 3] == 0)
        return false;
    if (s[pos] == 0 && s[pos - 1] == 1 && s[pos - 2] == 1 && s[pos - 3] == 1)
        return false;
    if (s[pos] == 1 && s[pos - 1] == 1 && s[pos - 2] == 1 && s[pos - 3] == 1)
        return false;
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        s[i] = (char) a;
    }
    int pot = 7;
    int pot2 = 11;
    const int mod = 1000000007;
    long long terHash = 0, terHash2 = 0;
    for (int dl = 1; dl <= N; dl++) {
        long long wsp = pot;
        long long wsp2 = pot2;
        terHash = 0;
        terHash2 = 0;
        for (int i = 1; i < dl; i++) {
            wsp *= pot;
            wsp %= mod;
            terHash *= pot;
            terHash += s[i];
            terHash %= mod;

            wsp2 *= pot2;
            wsp2 %= mod;
            terHash2 *= pot2;
            terHash2 += s[i];
            terHash2 %= mod;
        }
        for (int i = dl; i <= N; i++) {
            terHash *= pot;
            terHash += s[i];
            terHash -= s[i - dl] * wsp;
            terHash %= mod;
            if (terHash < 0)
                terHash += mod;

            terHash2 *= pot2;
            terHash2 += s[i];
            terHash2 -= s[i - dl] * wsp2;
            terHash2 %= mod;
            if (terHash2 < 0)
                terHash2 += mod;
            for (int kon = 1; kon < 4; kon++)
                if (kon < dl)
                    ile[dl][i] += ile[dl - kon][i - kon];
            if (dl < 4)
                ile[dl][i] += 1;
            if (dl == 4 && sprawdz(i))
                ile[dl][i] += 1;
            if (dl > 4 && sprawdz(i))
                ile[dl][i] += ile[dl - 4][i - 4];
            ile[dl][i] %= mod;
            if (byly.count({terHash, terHash2}) == 1) {
                continue;
            }
            byly.insert({terHash, terHash2});
            sumIle[i] += ile[dl][i];
            sumIle[i] %= mod;
        }
        byly.clear();
    }
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += sumIle[i];
        sum %= mod;
        if (sum < 0)
            sum += mod;
        printf("%lld\n", sum);
    }
    return 0;
}