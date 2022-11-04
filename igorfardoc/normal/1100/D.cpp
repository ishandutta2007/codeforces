#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int x, y;
int x1[666], y1[666];

bool get1() {
    int k, x, y;
    cin >> k >> x >> y;
    --k;
    if(k == -2) {
        return true;
    }
    x1[k] = x;
    y1[k] = y;
    return false;
}

void move(int dx, int dy) {
    cout << x + dx << ' ' << y + dy << endl;
    x += dx;
    y += dy;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> x >> y;
    for(int i = 0; i < 666; i++) {
        cin >> x1[i] >> y1[i];
    }
    while(x != 500 || y != 500) {
        if(x != 500) {
            if(x > 500) {
                move(-1, 0);
            } else {
                move(1, 0);
            }
        } else {
            if(y > 500) {
                move(0, -1);
            } else {
                move(0, 1);
            }
        }
        if(get1()) return 0;
    }
    int lu = 0;
    int ld = 0;
    int ru = 0;
    int rd = 0;
    for(int i = 0; i < 666; i++) {
        if(x1[i] > x && y1[i] > y) {
            ++rd;
        } else if(x1[i] > x) {
            ++ld;
        } else if(y1[i] > y) {
            ++ru;
        } else {
            ++lu;
        }
    }
    int dx = 0;
    int dy = 0;
    int mn = min(min(ld, lu), min(rd, ru));
    if(lu == mn) {
        dx = 1;
        dy = 1;
    } else if(ld == mn) {
        dx = -1;
        dy = 1;
    } else if(ru == mn) {
        dx = 1;
        dy = -1;
    } else {
        dx = -1;
        dy = -1;
    }
    while(true) {
        bool ok = true;
        for(int i = 0; i < 666; i++) {
            if(x1[i] == dx + x && y1[i] == dy + y) ok = false;
        }
        if(!ok) {
            dx = 0;
        }
        move(dx, dy);
        if(get1()) return 0;
    }
}