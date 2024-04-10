#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int m[999], r[100009][2];

int rc(int n)
{
    if (n == m[n]) return n;
    return m[n] = rc(m[n]);
}

int main()
{
    int n, p, q, cnt = 0;
    string a, b;
    cin>>n>>a>>b;
    for (int i = 'a'; i <= 'z'; i++)
        m[i] = i;
    for (int i = 0; i < n; i++){
        p = rc(a[i]); q = rc(b[i]);
        if (p != q){
            m[q] = p;
            cnt++;
            r[cnt][0] = a[i]; r[cnt][1] = b[i];
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%c %c\n", r[i][0], r[i][1]);
    return 0;
}