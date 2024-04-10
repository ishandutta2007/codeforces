
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 100005;
int a[N], t[N];

int main(){
    int n, m;
    sd(n); sd(m);
    swap(n, m);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int c;
        sd(c);
        a[c]++;
        bool ok = 1;
        for(int j = 1; j <= m; j++) if(!a[j])ok = 0;
        if(ok){
            ans++;
            for(int j = 1; j <= m; j++) a[j]--;
        }
    }
    printf("%d\n", ans);
}