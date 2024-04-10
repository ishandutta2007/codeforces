#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int m01 = 0, m02 = 0;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        switch(a) {
        case 0:
            m01 = m02 = min(m01, m02) + 1;
            break;
        case 1: {
            int t02 = m02;
            m02 = min(m01, m02) + 1;
            m01 = min(m02, t02);
            break; }
        case 2: {
            int t01 = m01;
            m01 = min(m02, m01) + 1;
            m02 = min(m01, t01);
            break; }
        case 3:
            int o01 = m01, o02 = m02;
            m01 = min(min(o01, o02) + 1, o02);
            m02 = min(min(o02, o01) + 1, o01);
            break;
        }
    }
    printf("%d\n", min(m01, m02));
}