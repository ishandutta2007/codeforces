#include <bits/stdc++.h>
using namespace std;

#define pt pair<pair<int, int>, int>
#define l first.first
#define r first.second
#define id second

pt arr[(int) 1e6 + 6];
int blk = 1000;

bool comp(pt a, pt b){
    if (a.l / blk != b.l / blk)
        return a.l / blk < b.l / blk;
    if (a.l / blk & 1)
        return a.r < b.r;
    return a.r > b.r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i].l >> arr[i].r;
        arr[i].id = i;
    }
    sort(arr + 1, arr + n + 1, comp);
    for (int i = 1; i <= n; i++)
        cout << arr[i].id << ' ';
}