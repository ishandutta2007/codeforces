
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

struct chuj {

int len;
int leftmost;
int value;
chuj* lewy = nullptr;
chuj* prawy = nullptr;

chuj(int len1, int leftmost1, int value1) : len(len1), leftmost(leftmost1), value(value1) {}

};

struct kurwa {

bool operator() (const chuj& a, const chuj& b) {
    if (a.len == b.len) return a.leftmost < b.leftmost;
    return a.len > b.len;
}

};

void jebaj() {

    int n;
    cin >> n;
    int ostatni = -1, len = 0, pocz = -1;
    vector<chuj> chuje;
    REP(i, n) {
        int a;
        cin >> a;
        if (a == ostatni) {
            len++;
        } else {
            if (pocz != -1) {
                chuje.PB(chuj(len, pocz, ostatni));
            }
            pocz = i;
            len = 1;
            ostatni = a;
        }
    }
    chuje.PB(chuj(len, pocz, ostatni));

    FOR(i,1, SIZE(chuje) - 1) chuje[i].lewy = &(chuje[i - 1]);
    FOR(i,0, SIZE(chuje) - 2) chuje[i].prawy = &(chuje[i + 1]);

    set<chuj, kurwa> secik(chuje.begin(), chuje.end());

    int res = 0;
    while (!secik.empty()) {
        res++;
        auto it = secik.begin();

        //cerr << it->len << " " << it->leftmost << " " << it->value << "\n";

        chuj* l = it->lewy;
        chuj* r = it->prawy;
        secik.erase(it);
        if (l != nullptr) {
                secik.erase(*l);
                l->prawy = r;
        }
        if (r != nullptr) {
            secik.erase(*r);
            r->lewy = l;
        }


        if (l != nullptr && r != nullptr) {
            if (l->value == r->value) {

                secik.erase(*l);
                secik.erase(*r);

                chuj* rr = r->prawy;
                if (rr != nullptr) {
                        secik.erase(*rr);
                        rr->lewy = l;
                }
                l->prawy = rr;
                l->len += r->len;
                secik.insert(*l);
                if (rr != nullptr) secik.insert(*rr);
            }
            else {
                secik.insert(*l);
                secik.insert(*r);
            }
        } else {
    if (l != nullptr) {
                secik.insert(*l);
        }
        if (r != nullptr) {
            secik.insert(*r);
        }

        }


    }
    cout << res << "\n";
}
#undef int
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}