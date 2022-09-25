#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

const int MAXLEN = 5010;

bool cmp(int x, int y);

struct automata {
    struct state {
        int len, link, cnt;
        map<char,int> next;
    };
    state st[MAXLEN*2];
    int sz, last;

    void sa_init() {
        sz = last = 0;
        st[0].len = 0;
        st[0].link = -1;
        ++sz;
    }
    
    automata() {
        sa_init();
    }
    
    automata(string s) {
        sa_init();
        for (int i = 0; i < s.length(); i++) sa_extend(s[i]);
    }
    
    
    
    void sa_extend (char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].cnt = 1;
        int p;
        for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
            st[p].next[c] = cur;
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                    st[p].next[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    
    void push() {
        vector<int> p(sz);
        for (int i = 0; i < sz; i++) p[i] = i;
        sort(p.begin(), p.end(), cmp);
        for (int i = 0; i < sz; i++) {
            if (st[p[i]].link != p[i] && st[p[i]].link != -1) {
                st[st[p[i]].link].cnt += st[p[i]].cnt;
            }
        }
    }
};

automata *cur;

bool cmp(int x, int y) {
    return cur->st[x].len > cur->st[y].len;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    string s[2];
    while (cin >> s[0] >> s[1]) {
        automata a1(s[0]);
        cur = &a1;
        a1.push();
        automata a2(s[1]);
        cur = &a2;
        a2.push();
        
        int ans = 100100;
        int n = s[0].length();
        for (int l = 0; l < n; l++) {
            int cur1 = 0, cur2 = 0;
            for (int r = l; r < n; r++) {
                if (!a1.st[cur1].next.count(s[0][r]) || !a2.st[cur2].next.count(s[0][r])) break;
                cur1 = a1.st[cur1].next[s[0][r]];
                cur2 = a2.st[cur2].next[s[0][r]];
                if (a1.st[cur1].cnt == 1 && a2.st[cur2].cnt == 1) ans = min(ans, r - l + 1);
            }
        }
        if (ans == 100100) ans = -1;
        cout << ans << endl;
    }

	return 0;
}