#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

using namespace std;

string dm = "tylbga";

int n, e;
vector<pair<string,int> > loc;
set<string> ftb;
set<string> btf;
set<string> utb;
set<string> utf;

map<string,int> fn;
set<string> ef, eb;

vector<pair<string,string> > res;

void move(string a, string b) {
    //printf("mv %s %s\n", a.c_str(), b.c_str());
    if (fn.count(a)) {
        int l = fn[a];
        if (l <= e) {
            ef.insert(a);
        } else {
            eb.insert(a);
        }
    }
    if (ef.count(b)) {
        ef.erase(b);
    }
    if (eb.count(b)) {
        eb.erase(b);
    }
    if (ftb.count(a)) {
        ftb.erase(a);
    }
    if (btf.count(a)) {
        btf.erase(a);
    }
    if (utf.count(a)) {
        utf.erase(a);
    }
    if (utb.count(a)) {
        utb.erase(a);
    }
    res.emplace_back(a, b);
}

int main() {
    scanf("%d ", &n);
    fo(i,0,n) {
        string s;
        int x;
        cin >> s >> x;
        loc.emplace_back(s,x);
        e += x;
    }
    fo(i,1,n+1) {
        char buf[6];
        sprintf(buf, "%d", i);
        fn[buf] = i;

        if (i <= e) ef.emplace(buf);
        else eb.emplace(buf);
    }

    fo(i,0,n) {
        string s; int x;
        tie(s,x) = loc[i];

        if (fn.count(s)) {
            int l = fn[s];
            if (x && l > e) {
                btf.insert(s);
            } else if (!x && l <= e) {
                ftb.insert(s);
            }
            if (l > e) eb.erase(s);
            else ef.erase(s);
        } else if (x) {
            utf.insert(s);
        } else {
            utb.insert(s);
        }
    }

    while (1) {
        if (sz(utf) == 0 && sz(utb) == 0 && sz(ftb) == 0 && sz(btf) == 0) {
            break;
        }

        if (sz(ef) == 0 && sz(eb) == 0) {
            string tmp = *ftb.begin();
            move(tmp, dm);
            utb.insert(dm);
        } else if (sz(ef) && sz(btf)) {
            string frm = *btf.begin();
            string to = *ef.begin();
            move(frm, to);
        } else if (sz(ftb) && sz(eb)) {
            string frm = *ftb.begin();
            string to = *eb.begin();
            move(frm, to);
        } else if (sz(ef) && sz(utf)) {
            string frm = *utf.begin();
            string to = *ef.begin();
            move(frm, to);
        } else if (sz(eb) && sz(utb)) {
            string frm = *utb.begin();
            string to = *eb.begin();
            move(frm, to);
        } else {
            assert(false);
        }
    }
    printf("%d\n", sz(res));
    for (auto p : res) {
        printf("move %s %s\n", p.first.c_str(), p.second.c_str());
    }
}