#include <cstdio>
#include <numeric>
using namespace std;

char buf[100001];

int n;
int a[100000];
int pa[100000];

void init() {
    char *c = buf, d = *c;
    while(*c) {
        if(*c != d)
            a[++n] = 1, d = *c;
        else
            a[n]++;
        c++;
    }
    n++;
}

long long f(int x) {
    if(x % 2)
        return (long long) (x + 1) * (x + 1) / 4;
    else
        return (long long) x * (x + 2) / 4;
}

int jsuma[100002];
int jodda[100002];
int odiffa[100002];
int ediffa[100002];

int main(){
    scanf("%s", buf);
    init();
    partial_sum(a, a + n, pa);
    for(int i = n - 1; i >= 0; i--) {
        jsuma[i] = jsuma[i + 2] + a[i];
        jodda[i] = jodda[i + 2] + (a[i] % 2);
        odiffa[i] = odiffa[i + 2] + (pa[i - 1] % 2) * (a[i] % 2);
        ediffa[i] = ediffa[i + 2] + (!(pa[i - 1] % 2)) * (a[i] % 2);
    }


    long long even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
        odd += f(a[i]);
        even += f(a[i] - 1);

        int jsum = jsuma[i + 2];

        long long diff = (long long) a[i] * jsum / 2;

        if(a[i] % 2)
            diff -= jodda[i + 2] / 2;

        odd += diff;
        even += diff;

        if(a[i] % 2) {
            int odiff = odiffa[i + 2], ediff = ediffa[i + 2];

            if(pa[i] % 2)
                swap(odiff, ediff);
            odd += odiff;
            even += ediff;
        }
    }
    printf("%I64d %I64d", even, odd);
}