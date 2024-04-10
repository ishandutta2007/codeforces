#include <bits/stdc++.h>

using namespace std;

struct Node;
Node* nullNode;
Node* root;

int ans = 0;

struct Node {
    vector<Node*> to;
    bool marked;
    int children;

    Node() {
        to = *(new vector<Node*>(26, nullNode));
        marked = false;
        children = 0;
    }

    void go(const string& s, int pos, bool pressed_tab, bool passed_through_marked, int tab_saved) {
        /*
        cout << "go " << s << " " << pos << endl;
        */


        if (pos == s.size()) {
            if (!marked) {
                marked = true;
                ++children;

                /*
                cout << "made marked! children is " << children << endl;
                */
            } else {
                passed_through_marked = true;
                /*
                cout << "already marked" << endl;
                */
            }

            if (passed_through_marked) {
                /*
                cout << "added: " << min(s.size(), s.size() -  tab_saved) << endl;
                 */
                ans += min(s.size(), s.size() -  tab_saved);
            } else {
                /*
                cout << "added: " << s.size();
                 */
                ans += s.size();
            }


            return;
        }

        int c = (int)(s[pos] - 'a');
        if (to[c] == nullNode) {
            to[c] = new Node();
        }

        int children_prev = to[c] -> children;

        ////////////////////////////////////////////////////////////////
        if (pressed_tab) {
            if (marked) passed_through_marked = true;
            if (children == 1 && (to[c] -> children) == 1) {
                ++tab_saved;

                /*
                cout << "++tab saved" << endl;
                */
            }
        } else {
            if (children == 1 && (to[c] -> children) == 1) {
                pressed_tab = true;
                /*
                cout << "pressed tab" << endl;
                */
            }
        }
        ////////////////////////////////////////////////////////////////
        to[c] -> go(s, pos + 1, pressed_tab, passed_through_marked, tab_saved);

        children += ((to[c] -> children) - children_prev);


        /*

        cout << "children is " << children << endl;
        */
    }
};


inline bool is_sep(char c) {
    return (c == '.' || c == ',' || c == '?' || c == '!' || c == '\'' || c == '-');
}

void process_word(string s) {
    root -> go(s, 0, false, false, 0);
}

int separator_count = 0;

void process(string s) {
    s += ".";
    int start_pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (is_sep(s[i])) {
            if (i != s.length() - 1) {
                ++separator_count;

            }
            if (start_pos == -1) continue;
            process_word(s.substr(start_pos, i - start_pos));
            start_pos = -1;
        } else {
            if (start_pos != -1) continue;
            start_pos = i;
        }
    }
}

int32_t main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    root = new Node();
    root -> children = 1;

    string s;

    int number_of_words = 0;
    while (cin >> s) {
        ++number_of_words;
        process(s);
    }

    /*
    cout << "number of words : " << number_of_words << endl;
    cout << "separators : " << separator_count << endl;
    */

    cout << ans + number_of_words + separator_count << endl;

}