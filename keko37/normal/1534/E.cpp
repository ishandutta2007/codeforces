#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 505;

int n, k, cnt = 1, m, sol, flg;
int bio[MAXN];
vector <int> v;

int pitaj () {
    if (flg) {
        for (int i = 1; i <= n; i++) bio[i] = 0;
        for (auto x : v) bio[x] = 1;
        v.clear();
        for (int i = 1; i <= n; i++) {
            if (bio[i] == 0) v.push_back(i);
        }
    }
    cout << "? ";
    for (auto x : v) cout << x << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void idi (int br) {
    for (int i = 0; i < br; i++) {
        v.clear();
        for (int j = 0; j < k; j++) {
            v.push_back(cnt);
            cnt++;
        }
        sol ^= pitaj();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    m = n / k + 1;
    if (m == 2 && (n - k) % 2 == 1) k = n - k, flg = 1;
    m = n / k + 1;
    if (n % k == 0) {
        idi(n / k);
    } else {
        if (m >= 3) {
            if ((k * m - n) % 2 == 0) {
                idi(m - 2);
                int ost = (k * m - n) / 2;
                for (int i = 0; i < 2; i++) {
                    v.clear();
                    for (int j = 0; j < ost; j++) {
                        v.push_back(j + 1);
                    }
                    for (int j = 0; j < k - ost; j++) {
                        v.push_back(cnt);
                        cnt++;
                    }
                    sol ^= pitaj();
                }
            } else {
                idi(m - 1);
                int ost = (n - (m - 1) * k) / 2;
                for (int i = 0; i < 2; i++) {
                    v.clear();
                    for (int j = 0; j < k - ost; j++) {
                        v.push_back(j + 1);
                    }
                    for (int j = 0; j < ost; j++) {
                        v.push_back(cnt);
                        cnt++;
                    }
                    sol ^= pitaj();
                }
            }
        } else {
            idi(1);
            int ost = (n - k) / 2;
            for (int i = 0; i < 2; i++) {
                v.clear();
                for (int j = 0; j < k - ost; j++) {
                    v.push_back(j + 1);
                }
                for (int j = 0; j < ost; j++) {
                    v.push_back(cnt);
                    cnt++;
                }
                sol ^= pitaj();
            }
        }
    }
    cout << "! " << sol << endl;
    return 0;
}