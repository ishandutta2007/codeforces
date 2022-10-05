#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 1005;

int n;
pii a[N], b[N];
map<pii, int> mp;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &b[i].x, &b[i].y);
        for(int j = 0; j < n; j++){
            mp[pii(b[i].x + a[j].x, b[i].y + a[j].y)]++;
        }
    }
    for(auto i : mp){
        if(i.y == n){
            printf("%d %d\n", i.x.x, i.x.y);
            return 0;
        }
    }
}