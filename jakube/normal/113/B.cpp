#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, par, link;
    map<char,int> next;
 
    Node (int l=0, int r=0, int par=-1)
        : l(l), r(r), par(par), link(-1) {}
    int len()  {  return r - l;  }
    int &get (char c) {
        if (!next.count(c))  next[c] = -1;
        return next[c];
    }
};

struct State {
    int v, pos;
    State (int v, int pos) : v(v), pos(pos)  {}
};

class SuffixTree {
public:
    string s;
    int n;
    vector<Node> t;
    int sz = 0;
    State ptr{0, 0};

    SuffixTree(string str) {
        s = str;
        n = str.size();
        t.reserve(2*n);
        build_tree();
    }
     
    State go(State st, int l, int r) {
        while (l < r)
            if (st.pos == t[st.v].len()) {
                st = State (t[st.v].get(s[l]), 0);
                if (st.v == -1) return st;
            }
            else {
                if (s[t[st.v].l + st.pos] != s[l])
                    return State(-1, -1);
                if (r-l < t[st.v].len() - st.pos)
                    return State(st.v, st.pos + r-l);
                l += t[st.v].len() - st.pos;
                st.pos = t[st.v].len();
            }
        return st;
    }
     
    int split(State st) {
        if (st.pos == t[st.v].len())
            return st.v;
        if (st.pos == 0)
            return t[st.v].par;
        Node v = t[st.v];
        int id = sz++;
        t.push_back({v.l, v.l+st.pos, v.par});
        t[v.par].get(s[v.l]) = id;
        t[id].get(s[v.l+st.pos]) = st.v;
        t[st.v].par = id;
        t[st.v].l += st.pos;
        return id;
    }
     
    int get_link(int v) {
        if (t[v].link != -1) return t[v].link;
        if (t[v].par == -1) return 0;
        int to = get_link(t[v].par);
        return t[v].link = split(go(State(to,t[to].len()), t[v].l + (t[v].par==0), t[v].r));
    }
     
    void tree_extend(int pos) {
        for(;;) {
            State nptr = go(ptr, pos, pos+1);
            if (nptr.v != -1) {
                ptr = nptr;
                return;
            }
     
            int mid = split(ptr);
            int leaf = sz++;
            t.push_back({pos, n, mid});
            t[mid].get(s[pos]) = leaf;
     
            ptr.v = get_link(mid);
            ptr.pos = t[ptr.v].len();
            if (!mid) break;
        }
    }
     
    void build_tree() {
        sz = 1;
        t.push_back({});
        for (int i=0; i<n; ++i)
            tree_extend(i);
    }
};

bool check_end(Node node, int k, string &s, string &s_end, SuffixTree &suffixTree) {
    int sz = s_end.size();
    for (int i = 0; i < sz;) {
        while (node.l + k < node.r && i < sz) {
            if (s[node.l + k] != s_end[i]) return false;
            k++;
            i++;
        }
        if (i < sz) {
            int next = node.get(s_end[i]);
            if (next == -1) return false;
            node = suffixTree.t[next];
            k = 0;
        }
    }

    return true;
}

int recursive(Node node, int k, string &s, string &s_end, SuffixTree &suffixTree) {
    int cnt = 0;
    while (node.l + k < node.r) {
        if (check_end(node, k, s, s_end, suffixTree)) cnt++;
        k++;
    } 

    for (char c = 'a'; c <= 'z'; c++) {
        int next = node.get(c);
        if (next != -1) {
            cnt += recursive(suffixTree.t[next], 0, s, s_end, suffixTree);
        }
    }

    return cnt;
}

bool check_begin_end(Node node, int k, string &s, string &s_begin, int idx_begin, string &s_end, SuffixTree &suffixTree) {
    for (int i = 0; i < s_end.size();) {
        while (node.l + k < node.r && i < s_end.size()) {
            if (s[node.l + k] != s_end[i]) return false;
            if (idx_begin < s_begin.size() && s_begin[idx_begin] != s_end[i]) return false;
            i++;
            idx_begin++;
            k++;
        }

        if (i < s_end.size()) {
            int next = node.get(s_end[i]);
            if (next == -1) return false;
            node = suffixTree.t[next];
            k = 0;
        }
    }

    return idx_begin >= s_begin.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    SuffixTree suffixTree(s);
    string s_begin, s_end;
    cin >> s_begin >> s_end;

    int cnt = 0;
    Node node = suffixTree.t[0];
    int k = 0;
    int size_begin = s_begin.size();
    for (int i = 0; i < size_begin;) {
        while (node.l + k < node.r && i < size_begin) {
            if (check_begin_end(node, k, s, s_begin, i, s_end, suffixTree)) cnt++;
            if (s[node.l + k] != s_begin[i]) {
                cout << 0 << endl;
                return 0;
            }
            k++;
            i++;
        }

        if (i < size_begin) {
            int next = node.get(s_begin[i]);
            if (next == -1) {
                cout << 0 << endl;
                return 0;
            }
            node = suffixTree.t[next];
            k = 0;
        }
    }

    cnt += recursive(node, k, s, s_end, suffixTree);
    cout << cnt << endl;

    return 0;
}