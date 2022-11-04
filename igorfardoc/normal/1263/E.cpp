#include<bits/stdc++.h>
#define INF 1000000000
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[4000007], lp1[4000007], lp2[4000007];
int mass[1000007];

void update(int now, int l, int r, int l1, int r1, int val) {
    if(l1 > r || l > r1) {
        return;
    }
    if(l1 <= l && r <= r1) {
        t[now] += val;
        lp1[now] += val;
        lp2[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
    lp1[now] = min(lp1[now * 2], lp1[now * 2 + 1]) + t[now];
    lp2[now] = max(lp2[now * 2], lp2[now * 2 + 1]) + t[now];
}
int get_min(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) {
        return INF;
    }
    if(l1 <= l && r <= r1) {
        return lp1[now];
    }
    int mid = (l + r) / 2;
    return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1)) + t[now];
}
int get_max(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) {
        return -INF;
    }
    if(l1 <= l && r <= r1) {
        return lp2[now];
    }
    int mid = (l + r) / 2;
    return max(get_max(now * 2, l, mid, l1, r1), get_max(now * 2 + 1, mid + 1, r, l1, r1)) + t[now];
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int now = 0;
    int op = 0;
    int clos = 0;
    for(const auto& c : s) {
        if(c == 'R') {
            ++now;
        }
        else if(c == 'L') {
            now = max(0, now - 1);
        }
        else {
            if(mass[now] == 1) {
                --op;
                update(1, 0, MAX - 1, now, MAX - 1, -1);
            } else if(mass[now] == -1) {
                --clos;
                update(1, 0, MAX - 1, now, MAX - 1, 1);
            }
            if(c == '(') {
                ++op;
                mass[now] = 1;
            } else if(c == ')') {
                mass[now] = -1;
                ++clos;
            } else {
                mass[now] = 0;
            }
            if(mass[now] == 1) {
                update(1, 0, MAX - 1, now, MAX - 1, 1);
            } else if(mass[now] == -1) {
                update(1, 0, MAX - 1, now, MAX - 1, -1);
            }
        }
        if(op == clos && get_min(1, 0, MAX - 1, 0, MAX - 1) >= 0) {
            cout << get_max(1, 0, MAX - 1, 0, MAX - 1) << ' ';
        } else {
            cout << "-1 ";
        }
    }
}