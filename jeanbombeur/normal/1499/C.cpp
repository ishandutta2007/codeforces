#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
 
//    <|_|>
 
const int MAX_SEGMENTS = (100 * 1000);
 
int Prix[MAX_SEGMENTS];
 
int nbSegments;
 
void Read() {
    scanf("%lld", &nbSegments);
    for (int i = 0; i < nbSegments; i ++)
    {
        scanf("%lld", &Prix[i]);
    }
    int minimum = 1LL << 60;
    int Mini[2] = {Prix[0], Prix[1]};
    int sum = 0;
    for (int i = 0; i < nbSegments; i ++)
    {
        Mini[i % 2] = min(Mini[i % 2], Prix[i]);
        sum += Prix[i];
        int cur = sum + (nbSegments - ((i + 2) / 2)) * Mini[0] + (nbSegments - ((i + 1) / 2)) * Mini[1];
        minimum = min(minimum, cur);
    }
    printf("%lld\n", minimum);
    return;
}
 
signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}