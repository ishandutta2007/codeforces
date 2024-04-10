#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

char in1[100005], in2[100005];

int a1[100005], a2[100005];

double phi;

int main(){
    phi = (1 + sqrt(5)) / 2;
    scanf("%s%s", in1, in2);
    for (int i = 0; i <= 100000; ++i) a1[i] = a2[i] = 0;
    int l = 0;
    while (in1[l] != '\0') ++l;
    for (int i = 0; i < l; ++i) a1[l - 1 - i] = in1[i] - '0';
    l = 0;
    while (in2[l] != '\0') ++l;
    for (int i = 0; i < l; ++i) a2[l - 1 - i] = in2[i] - '0';
    for (int i = 100000; i >= 2; --i){
        int x = min(a1[i], a2[i]);
        a1[i] -= x;
        a2[i] -= x;
        if (a1[i] > 3){printf(">\n"); return 0;}
        if (a2[i] > 3){printf("<\n"); return 0;}
        a1[i - 1] += a1[i];
        a1[i - 2] += a1[i];
        a2[i - 1] += a2[i];
        a2[i - 2] += a2[i];
    }
    if (a1[1] == a2[1] && a1[0] == a2[0]) printf("=\n");
    else {
         if (a1[1] * phi + a1[0] > a2[1] * phi + a2[0]) printf(">\n");
         else printf("<\n");
    }
    return 0;
}