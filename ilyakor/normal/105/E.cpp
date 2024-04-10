#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int H = 999997;
const int X = 57;

struct Pos {
    int x, y, z;
    Pos(){}
    Pos(vi v) {
        x = v[0];
        y = v[1];
        z = v[2];
    }
    vi toV() {
        vi res(3);
        res[0] = x;
        res[1] = y;
        res[2] = z;
        return res;
    }

    friend bool operator<(Pos p, Pos q) {
        if (p.x != q.x) return p.x < q.x;
        if (p.y != q.y) return p.y < q.y;
        return p.z < q.z;
    }

};

int myhashmy(Pos& p, int mask) {
    int res = (((mask * X % H + p.x) % H * X + p.y) % H * X + p.z) % H;
    return res;
}

//set<Pos> d[1 << 9];

vector<Pos> d[H];

void add(int mask, Pos& p) {
    int h = myhashmy(p, mask);
    d[h].pb(p);
}

bool contains(int mask, Pos& p) {
    int h = myhashmy(p, mask);
    for (int i = 0; i < sz(d[h]); ++i)
        if (d[h][i].x == p.x && d[h][i].y == p.y && d[h][i].z == p.z) return true;
    return false;
}



int main()
{
    time_t tst = clock();
    int x[3], f[3], th[3];
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> f[i] >> th[i];
    int res = max(x[0], x[1]);
    res = max(res, x[2]);
    vi cur(3);
    cur[0] = x[0];
    cur[1] = x[1];
    cur[2] = x[2];
    //d[0].insert(Pos(cur));
    Pos pc(cur);
    add(0, pc);
    queue<pair<int, vi> > q;
    q.push(mp(0, cur));
    int IT = 0;
    while (!q.empty()) {
        int mask = q.front().first;
        vi cur = q.front().second;      
        q.pop();
        ++IT;
        if (IT % 100 == 0) {
            if (clock() - tst > 2.5 * CLOCKS_PER_SEC) break;
        }
        //if (mask == 1 && cur[0] == 6 && cur[1] == 4 && cur[2] == 2) cerr << "ok1\n";
        //if (mask == 65 && cur[0] == 6 && cur[1] == 4 && cur[2] == 5) cerr << "ok2\n";
        //if (mask == 321 && cur[0] == 6 && cur[1] == -102 && cur[2] == 5) cerr << "ok3\n";
        for (int i = 0; i < 3; ++i)
            res = max(res, cur[i]);
        for (int i = 0; i < 3; ++i) {           
            bool we = false, us = false;
            for (int j = 0; j < 3; ++j)
                if (cur[j] == -i - 100)
                    we = true;
            if (cur[i] <= -100)
                us = true;
            if (!us && !we && !((mask >> (3 * i)) & 1)) {
                for (int j = -f[i]; j <= f[i]; ++j) {
                    bool bad = false;
                    for (int t = 0; t < 3; ++t) if (cur[i] + j == cur[t]) bad = true;
                    if (!bad) {
                        cur[i] += j;
                        res = max(res, cur[i]);
                        int nm = mask | (1 << (3 * i));
                        Pos pc(cur);
                        //if (!d[nm].count(pc)) {
                        //  d[nm].insert(pc);
                        if (!contains(nm, pc)) {
                            add(nm, pc);
                            q.push(mp(nm, cur));
                        }
                        cur[i] -= j;
                    }
                }
            }

            
            if (!us && we && !((mask >> (3 * i + 1)) & 1)) {
                int who = -1;
                for (int j = 0; j < 3; ++j)
                    if (cur[j] == -i - 100)
                        who = j;
                for (int j = -th[i]; j <= th[i]; ++j) {
                    bool bad = false;
                    for (int t = 0; t < 3; ++t) if (cur[i] + j == cur[t]) bad = true;
                    if (!bad) {
                        cur[who] = cur[i] + j;
                        res = max(res, cur[who]);
                        int nm = mask | (1 << (3 * i + 1));
                        Pos pc(cur);
                        //if (!d[nm].count(pc)) {
                        //  d[nm].insert(pc);
                        if (!contains(nm, pc)) {
                            add(nm, pc);
                            q.push(mp(nm, cur));
                        }
                        cur[who] = -i - 100;
                    }
                }
            }
            

            if (!us && !we && !((mask >> (3 * i + 2)) & 1)) {
                    
                for (int j = 0; j < 3; ++j)
                    if (cur[j] > -100 && abs(cur[j] - cur[i]) == 1) {
                        int tmp = cur[j];
                        cur[j] = -100 - i;
                        int nm = mask | (1 << (3 * i + 2));                         
                        Pos pc(cur);
                        //if (!d[nm].count(pc)) {
                        //  d[nm].insert(pc);
                        if (!contains(nm, pc)) {
                            add(nm, pc);
                            q.push(mp(nm, cur));
                        }
                        cur[j] = tmp;
                    }
            }

        }
    }
    cout << res << "\n";
    return 0;
}