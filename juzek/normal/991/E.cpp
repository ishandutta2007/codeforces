#include <cstdio>
#include <iostream>

int ile[10];
int akt[10];

long long silnia[20];

long long policz() {
    int s = 0;
    for (int i = 0; i < 10; i++)
        s += akt[i];
    long long ret = silnia[s];
    for (int i = 0; i < 10; i++)
        ret /= silnia[akt[i]];
    return ret;
}

long long kkk() {
    if (akt[0] == 0)
        return policz();
    long long a = policz();
    akt[0]--;
    a -= policz();
    akt[0]++;
    return a;
}

long long sum = 0;

void adam(int a) {
    if (a == 10) {
        sum += kkk();
        return;
    }
    if (ile[a] == 0)
        adam(a + 1);
    for (int i = 1; i <= ile[a]; i++) {
        akt[a] = i;
        adam(a + 1);
    }
}

int main() {
    std::string s;
    std::cin >> s;
    for (auto it : s)
        ile[it - '0']++;
    silnia[0] = 1;
    for (int i = 1; i <= 19; i++)
        silnia[i] = silnia[i - 1] * i;
    adam(0);
    printf("%I64d", sum);
    return 0;
}