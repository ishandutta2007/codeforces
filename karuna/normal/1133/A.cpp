#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int h1, h2, m1, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);

    int time = (h2*60+m2 + h1*60+m1)/2;
    printf("%02d:%02d", time/60, time%60);
}