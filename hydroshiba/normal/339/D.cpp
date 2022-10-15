#include "bits/stdc++.h"
using namespace std;

const int maxn = (1 << 17) + 6;
int n, tree[maxn << 1];

void update(int pos, int val){
    pos += n;
    tree[pos] = val;

    bool flag = 1;
    for(pos /= 2; pos > 0; pos /= 2){
        if(flag) tree[pos] = tree[2 * pos] | tree[2 * pos + 1];
        else tree[pos] = tree[2 * pos] ^ tree[2 * pos + 1];

        flag = !flag;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> n >> m;

    n = (1 << n);
    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        update(i, val);
    }

    while(m--){
        int pos, val;
        cin >> pos >> val;
        update(--pos, val);
        cout << tree[1] << '\n';
    }
}