#include <bits/stdc++.h>
using namespace std;

const int ALPH = 26;

struct Node
{
    vector<Node*> ch;
    Node* suf;
    int len;
    int suf_cnt, rgh;
    bool is_del;

    Node (int i = 0, int ln = -1) {
        rgh = i, suf_cnt = 0;
        is_del = false;
        suf = nullptr;
        ch.resize(ALPH, nullptr);
        len = ln;
    }
};

int len(Node *v) {
    if (v == nullptr) return 0;
    return v->len;
}

struct Eertree
{
    int cnt;
    Node* last;
    Node *odd, *even;
    vector<Node*> start;
    vector<int> s; int st;

    Eertree() {
        cnt = 0;
        st = 0;
        odd = new Node(1, -1);
        odd->suf_cnt = 2;
        odd->suf = odd;
        even = new Node(0, 0);
        even->suf = odd;
        last = even;
    }

    void push(int ch) {
        s.push_back(ch);
        start.push_back(nullptr);
        for (Node* v = last;; v = v->suf) {
            if ((int)s.size() >= v->len + 2 + st && ch == s[(int)s.size() - v->len - 2]) {
                if (v->ch[ch] == nullptr || v->ch[ch]->is_del) {
                    v->ch[ch] = new Node(s.size() - v->len - 2, v->len + 2);
                    cnt++;
                    if (v->len == -1) {
                        v->ch[ch]->suf = even;
                    } else {
                        for (Node *u = v->suf;; u = u->suf) {
                            if (ch == s[(int)s.size() - u->len - 2]) {
                                v->ch[ch]->suf = u->ch[ch];
                                u->ch[ch]->suf_cnt++;
                                break;
                            }
                        }
                    }
                } else {
                    v->ch[ch]->rgh = (int)s.size() - v->len - 2;
                }
                start[(int)s.size() - v->len - 2] = v->ch[ch];
                last = v->ch[ch];
                break;
            }
        }
    }

    void pop() {
        Node *v = start[st];
        if (v->rgh == st && v->suf_cnt == 0) {
            cnt--;
            v->is_del = true;
            if (last == v) {
                last = v->suf;
            }
            Node *u = v->suf;
            u->suf_cnt--;
            u->rgh = max(u->rgh, st + v->len - u->len);
        }
        Node *u = v->suf;
        if (u->len > 0 && u->len > len(start[st + v->len - u->len])) {
            start[st + v->len - u->len] = u;
        }
        st++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    Eertree tr;
    while (q--) {
        string tp;
        cin >> tp;
        if (tp == "push") {
            char ch;
            cin >> ch;
            tr.push(ch - 'a');
        } else {
            tr.pop();
        }
        cout << tr.cnt << '\n';
    }
    return 0;
}