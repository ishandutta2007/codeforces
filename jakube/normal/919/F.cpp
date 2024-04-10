#include <bits/stdc++.h>
using namespace std;

enum Status { LOOSING, WINNING, DRAW };

struct State {
    Status status = DRAW;
    bool finalized = false;
    int outgoing_finished = 0;
    vector<pair<int, int>> outgoing, incomming;
};

long long power(long long base, int e)
{
    long long result = 1;
    while (e) {
        if (e & 1)
            result = (result * base);
        base = (base * base);
        e >>= 1;
    }
    return result;
}

struct Hand : array<int, 5> {
    Hand() {
        std::fill(begin(), end(), 0);
    }
};

int idx[9][9][9][9][9];

int& get_idx(Hand hand) {
    return idx[hand[0]][hand[1]][hand[2]][hand[3]][hand[4]];
}

using Hand_uncomp = array<int, 8>;

Hand_uncomp to_base(int idx) {
    Hand_uncomp hand;
    for (int i = 0; i < 8; i++) {
        hand[i] = idx % 5;
        idx /= 5;
    }
    return hand;
}

Hand compress(Hand_uncomp hand) {
    Hand comp;
    for (int x : hand)
        comp[x]++;
    return comp;
}

int main() {
    set<Hand> hand_set;
    for (int i = 0; i < power(5, 8); i++)
        hand_set.insert(compress(to_base(i)));
    vector<Hand> hands(hand_set.begin(), hand_set.end());
    int n = hands.size();
    for (int i = 0; i < n; i++)
        get_idx(hands[i]) = i;

    vector<vector<State>> state(n, vector<State>(n));
    Hand all_zeros = compress({{0, 0, 0, 0, 0, 0, 0, 0}});;

    queue<pair<int, int>> q;
    for (int pl = 0; pl < n; pl++) {
        for (int pr = 0; pr < n; pr++) {
            if (hands[pl] == all_zeros) continue;

            auto first = hands[pr];
            auto second = hands[pl];
            for (int old_first = 1; old_first < 5; old_first++) {
                for (int old_second = 1; old_second < 5; old_second++) {
                    int new_first = (old_first + old_second) % 5;
                    if (first[new_first] && second[old_second]) {
                        first[new_first]--;
                        first[old_first]++;
                        auto& old_state = state[get_idx(first)][get_idx(second)];
                        old_state.outgoing.push_back({pl, pr});
                        auto& new_state = state[pl][pr];
                        new_state.incomming.push_back({get_idx(first), get_idx(second)});
                        first[new_first]++;
                        first[old_first]--;
                    }
                }
            }

            if (hands[pr] == all_zeros) {
                state[pl][pr].status = LOOSING;
                state[pl][pr].finalized = true;
                q.push({pl, pr});
            }
        }
    }

    while (!q.empty()) {
        auto [l, r] = q.front();
        q.pop();

        auto& st = state[l][r];
        if (st.status == LOOSING) {
            for (auto p : st.incomming) {
                auto& st2 = state[p.first][p.second];
                if (st2.finalized) continue;
                st2.status = WINNING;
                st2.finalized = true;
                q.push(p);
            }
        } else {
            for (auto p : st.incomming) {
                auto& st2 = state[p.first][p.second];
                if (st2.finalized) continue;
                st2.outgoing_finished++;
                if (st2.outgoing_finished == (int)st2.outgoing.size()) {
                    st2.status = LOOSING;
                    st2.finalized = true;
                    q.push(p);
                }
            }
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T --> 0) {
        int f;
        cin >> f;
        Hand_uncomp a, b;
        for (int& x : a)
            cin >> x;
        for (int& x : b)
            cin >> x;
        if (f)
            swap(a, b);
        int idx1 = get_idx(compress(a));
        int idx2 = get_idx(compress(b));
        auto s = state[idx1][idx2];
        if (s.status == DRAW)
            cout << "Deal\n";
        else {
            if ((s.status == WINNING && f == 0) || (s.status == LOOSING && f == 1))
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
}