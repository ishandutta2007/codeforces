#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 305;

int n, t, s[N], p;

int main(){
    scanf("%d%d", &n, &t);
    for(int i = 1, a = 0, l; i < n; i++){
        a += s[i-1];
        l = i;
        int cnt = 32;
        while(true){
            cnt--;
            printf("? %d %d\n", i+1, n);
            fflush(stdout);
            int v; scanf("%d", &v);
            if(v<0) return 0;
            p^=1;
            if((p && n-t != v) || (!p && t != v)){
                int d;
                if(p) d = v-(n-t);
                else d = t-v;
                s[i] = (d+l-2*a)/2;
                break;
            }
            if(!cnt){
                s[i] = l/2 - a;
                break;
            }
        }
        while(true){
            printf("? %d %d\n", i+1, n);
            fflush(stdout);
            int v; scanf("%d", &v);
            if(v<0) return 0;
            p^=1;
            if((p && n-t == v) || (!p && t == v)) break;
        }
    }
    s[n] = t - count(s+1, s+n, 1);
    printf("! ");
    for(int i = 1; i <= n; i++) printf("%d", s[i]);
    puts("");
    fflush(stdout);
    return 0;
}