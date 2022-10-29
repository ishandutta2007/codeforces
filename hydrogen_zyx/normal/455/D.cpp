#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 100;
int n, len, bcnt;
int a[N];
list<list<int> > blist;
int cnt[500][N];

void list_init() {
    for (int i = 1; i <= bcnt; ++i) {
        list<int> block;
        for (int j = (i - 1) * len + 1; j <= i * len; ++j) {
            block.push_back(a[j]);
            cnt[i][a[j]]++;
            if (j == n)break;
        }
        blist.push_back(block);
    }
}

int blist_delete(int pos) {
    int ans = 0;
    int pos1 = (pos - 1) / len + 1;
    int pos2 = pos - (pos1 - 1) * len;
    int flag = 0;
    list<list<int>>::iterator IT, front;
    int xb = 0;
    for (IT = blist.begin(); IT != blist.end(); ++IT) {
        xb++;
        if (flag) {
            front->push_back(IT->front());
            cnt[xb - 1][IT->front()]++;
            cnt[xb][IT->front()]--;
            IT->erase(IT->begin());
        }
        if (pos1 == xb) {
            list<int>::iterator it;
            for (it = IT->begin(); it != IT->end(); ++it) {
                pos2--;
                if (pos2 == 0) {
                    ans = *it;
                    cnt[xb][ans]--;
                    IT->erase(it);
                    flag = 1;
                    break;
                }
            }
        }
        front = IT;
    }
    if (blist.back().empty()) {
        blist.pop_back();
        bcnt--;
    }
    return ans;
}

void blist_insert(int pos, int val) {
    int pos1 = (pos - 1) / len + 1;
    int pos2 = pos - (pos1 - 1) * len;
    int flag = 0;
    int xb = 0;
    list<list<int>>::iterator IT, front;
    for (IT = blist.begin(); IT != blist.end(); ++IT) {
        xb++;
        if (flag) {
            cnt[xb][front->back()]++;
            cnt[xb - 1][front->back()]--;
            IT->push_front(front->back());
            front->pop_back();
        }
        if (pos1 == xb) {
            list<int>::iterator it;
            for (it = IT->begin(); it != IT->end(); ++it) {
                pos2--;
                if (pos2 == 0) {
                    cnt[xb][val]++;
                    IT->insert(it, val);
                    flag = 1;
                    break;
                }
            }
        }
        front = IT;
    }
    if (flag == 0)
        blist.back().push_back(val);
    if (blist.back().size() > len) {
        list<int> l;
        l.push_back(blist.back().back());
        blist.back().pop_back();
        blist.push_back(l);
        cnt[bcnt][l.front()]--;
        cnt[++bcnt][l.front()]++;
    }
}

int work(int l, int r, int k) {
    int lpos1 = (l - 1) / len + 1;
    int lpos2 = l - (lpos1 - 1) * len;
    int rpos1 = (r - 1) / len + 1;
    int rpos2 = r - (rpos1 - 1) * len;
    int ans = 0;
    if (lpos1 == rpos1) {
        int xb = 0;
        for (auto &x: blist) {
            xb++;
            if (xb == lpos1) {
                int _xb = 0;
                for (auto &y: x) {
                    _xb++;
                    if (_xb >= lpos2 && _xb <= rpos2) {
                        if (y == k)ans++;
                    }
                    if (_xb >= rpos2)return ans;
                }
            }
        }
    } else {
        int xb = 0;
        for (auto &x: blist) {
            xb++;
            if (xb == lpos1) {
                int _xb = 0;
                for (auto &y: x) {
                    _xb++;
                    if (_xb >= lpos2) {
                        if (y == k)ans++;
                    }
                }
            }
            if (xb > lpos1 && xb < rpos1) {
                ans += cnt[xb][k];
            }
            if (xb == rpos1) {
                int _xb = 0;
                for (auto &y: x) {
                    _xb++;
                    if (_xb <= rpos2) {
                        if (y == k)ans++;
                    }
                }
            }
        }
    }
    return ans;
}

signed main() {
    cin >> n;
    len = pow(n*2, 0.5);
    bcnt = (n - 1) / len + 1;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    list_init();
    int q;
    cin >> q;
    int lastans = 0;
    for (int i = 1; i <= q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            l = ((l + lastans - 1) % n) + 1;
            r = ((r + lastans - 1) % n) + 1;
            if (l > r)swap(l, r);
            int num = blist_delete(r);
            blist_insert(l, num);
        } else if (op == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            l = ((l + lastans - 1) % n) + 1;
            r = ((r + lastans - 1) % n) + 1;
            k = ((k + lastans - 1) % n) + 1;
            if (l > r)swap(l, r);
            int ans = work(l, r, k);
            cout << ans << '\n';
            lastans = ans;
        }
    }
    return 0;
}