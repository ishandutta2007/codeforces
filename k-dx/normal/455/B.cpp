#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 0;

int n, k;

struct TRIE {
    struct node {
        char letter;
        int win = -1,
            lose = -1;
        node* children[27] = { nullptr };
    };

    node* root = new node();

    void add_string (string &s, int pos, node* v) {
        if (pos == s.size()) return;
        int c = (s[pos] - 'a');

        if (v->children[c] == nullptr) {
            deb("pos = %d, uninitialized!\n", pos);
            v->children[c] = new node();
            v->children[c]->letter = s[pos];
        }
        else {
            deb("pos = %d, initialized!\n", pos);
        }

        add_string(s, pos+1, v->children[c]);
    }

    void add_string (string &s) {
        add_string(s, 0, this->root);
    }

    void calc_lose (node* v) {
        int res = 0;
        bool leaf = true;
        for (int c = 0; c <= (int)('z' - 'a'); c++) {
            if (v->children[c] != nullptr) {
                if (v->children[c]->lose == -1) calc_lose(v->children[c]);
                // jesli moge sprowadzic przeciwnika na poz wygrywajaca to przegrywam 
                res = res or !(v->children[c]->lose);
                leaf = false;
            }
        }

        if (leaf) v->lose = 1;
        else v->lose = res;
    }

    void calc_lose () {
        calc_lose(this->root);
    }

    void calc_win (node* v) {
        int res = 0;
        for (int c = 0; c <= (int)('z' - 'a'); c++) {
            if (v->children[c] != nullptr) {
                if (v->children[c]->win == -1) calc_win(v->children[c]);
                // jesli moge sprowadzic przeciwnika na poz przegrywajaca to wygrywam
                res = res or !(v->children[c]->win);
            }
        }

        v->win = res;
    }

    void calc_win () {
        calc_win(this->root);
    }

    void traverse (node *v, int depth) {
        deb("jestem w literce %c, win = %d, depth = %d: ", v->letter, v->win, depth);
        for (int c = 0; c <= (int)('z' - 'a'); c++) {
            if (v->children[c] != nullptr) {
                deb("%c ", (char)(c + 'a'));
            }
        }
        deb("\n");
        
        for (int c = 0; c <= (int)('z' - 'a'); c++) {
            if (v->children[c] != nullptr) {
                traverse(v->children[c], depth+1);
            }
        }
    }

    void traverse () {
        traverse(this->root, 0);
    }
};

int main () {
    // scanf("%d %d", &n, &k);
    // string a = "abaab";
    // string b = "abcd";

    // TRIE trie;

    // trie.add_string(a);
    // trie.add_string(b);

    // trie.traverse();
    
    BOOST;
    cin >> n >> k;

    TRIE trie;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.add_string(s);
    }

    // trie.traverse();

    trie.calc_win();
    trie.calc_lose();

    // trie.traverse();

    deb("trie.root->win = %d\n", trie.root->win);

    int can_win = trie.root->win;
    int can_lose = trie.root->lose;
    // da sie i wygrac, i przegrac
    if (can_win == 1 and can_lose == 1) {
        // first k-1 razy przegra i w ostatniej grze wygra
        cout << "First\n";
    } 
    // da sie tylko wygrac
    else if (can_win == 1) {
        // first wygra, wiec second zaczyna
        // second wygra, wiec first zaczyna itd.
        if (k&1) cout << "First\n";
        else cout << "Second\n";
    }
    // da sie tylko przegrac
    else {
        cout << "Second\n";
    }

    return 0;
}