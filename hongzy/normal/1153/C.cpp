#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 3e5 + 10;

int n, top;
char s[N];

int main() {
    scanf("%d%s", &n, s + 1);
    bool tag = 1;
    if(n % 2 == 1 || s[1] == ')' || s[n] == '(') tag = 0;
    int L = (n - 2) / 2, R = (n - 2) / 2;
    for(int i = 2; i < n; i ++)
        if(s[i] == '(') L --;
        else if(s[i] == ')') R --;
    for(int i = 2; i < n; i ++) {
        if(s[i] == '(') {
            top ++;
        }
        if(s[i] == ')') {
            if(!top) {
                tag = 0;
                break ;
            }
            top --;
        }
        if(s[i] == '?') {
            if(L) {
                L --;
                top ++, s[i] = '(';
            } else {
                if(!top) {
                    tag = 0;
                    break ;
                }
                top --, s[i] = ')';
            }
        }
    }
    if(top) tag = 0;
    if(tag) {
        s[1] = '('; s[n] = ')';
        puts(s + 1);
    } else puts(":(");
    return 0;
}