#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char input[100010];
int strSiz;
int cumUpper[100010], cumLower[100010];
int besAns (100010), cur;

int main() {
    scanf ("%s", input + 1);
    strSiz = strlen (input + 1);
    for (int i = 1; i <= strSiz; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            cumUpper[i]++;
        } else {
            cumLower[i]++;
        }
        cumUpper[i] += cumUpper[i-1];
        cumLower[i] += cumLower[i-1];
    }
    for (int i = 0; i <= strSiz; i++) {
        cur = (i - cumUpper[i]);
        cur += (cumUpper[strSiz] - cumUpper[i]);
        besAns = min (cur, besAns);
    }
    printf ("%d\n", besAns);
    return 0;
}