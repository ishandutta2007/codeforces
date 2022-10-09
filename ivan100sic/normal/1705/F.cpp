// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

struct testing {
    string sol;
    int qry;
    bool guessed;

    testing(int n) : sol(n, 0), qry(0), guessed(false) {
        for (int i : ra(0, n)) sol[i] = eng() & 1;
    }

    int operator() (string_view s) {
        int z = 0, n = ssize(s);
        for (int i : ra(0, n)) {
            z += s[i] == sol[i];
        }

        // print query
        // for (int x : sol) cerr << x;
        // cerr << '\n';
        // for (int x : s) cerr << x;
        // cerr << '\n';

        cerr << "ans = " << z << '\n';
        qry++;
        if (z == n) guessed = true;
        return z;
    }

    ~testing() {
        cerr << "asked " << qry << " queries.\n";
        if (guessed) {
            cerr << "OK\n";
        } else {
            cerr << "FAILED\n";
        }
    }
};

struct codeforces {
    int qry;
    int n;

    codeforces(int n) : qry(0), n(n) {

    }

    int operator() (string_view s) {
        qry++;
        if (qry == 675) {
            // thank you Nikola Pesic
            while (1);
        }

        for (bool x : s) cout << (x ? 'T' : 'F');
        cout << '\n' << flush;

        int z;
        cin >> z;
        if (z == n) {
            exit(0);
        }
        return z;
    }
};

void solver(int n, auto ask) {
    string a0(n, 0), a_sol;
    for (int i : ra(0, n)) a0[i] = eng() & 1;

    int w0 = ask(a0);
    a_sol = a0;

    vector<int> s;
    for (int i : ra(0, n)) {
        s.push_back(i);
    }
    R::shuffle(s, eng);

    /*
    Spend 500 queries to create ~250 pairs
    while there are more pairs than quads, process 2 pairs
    this will stop after around 80% of the pairs were processed or in about 100 queries
    you will be left with about 50 pairs and 50 quads
    each pair-quad pair can be processed in one query
    this is a total of 650 queries expected
    */

    vector<array<int, 2>> p;

    for (int i=0; i+1<n; i+=2) {
        int x = s[i];
        int y = s[i+1];
        
        int w;
        {
            auto a = a0;
            a[x] ^= 1;
            a[y] ^= 1;
            w = ask(a);
        }

        if (w == w0) {
            // pair
            p.push_back({x, y});
        } else {
            // solved
            int f = (w == w0 + 2);
            a_sol[x] ^= f;
            a_sol[y] ^= f;
        }
    }

    // solo s
    if (n % 2) {
        int x = s.back();
        int w;
        {
            auto a = a0;
            a[x] ^= 1;
            w = ask(a);
        }
        if (w == w0 + 1) {
            a_sol[x] ^= 1;
        }
    }

    // pairing
    vector<array<int, 4>> q;

    while (p.size() >= 2 && p.size() > q.size()) {
        auto [x1, y1] = p[p.size() - 2];
        auto [x2, y2] = p[p.size() - 1];
        p.pop_back();
        p.pop_back();

        int w;
        {
            auto a = a0;
            a[x1] ^= 1;
            a[x2] ^= 1;
            w = ask(a);
        }

        if (w == w0) {
            // quad
            q.push_back({x1, y1, x2, y2});
        } else {
            // solved
            int f = (w == w0 + 2);
            a_sol[x1] ^= f;
            a_sol[y1] ^= f ^ 1;

            a_sol[x2] ^= f;
            a_sol[y2] ^= f ^ 1;
        }
    }

    // Join pair-quads
    while (p.size() > 0 && q.size() > 0) {
        auto [x1, y1] = p.back();
        p.pop_back();
        auto [x2, y2, z2, t2] = q.back();
        q.pop_back();

        int w;
        {
            auto a = a0;
            a[x1] ^= 1;
            a[x2] ^= 1;
            a[t2] ^= 1;
            w = ask(a);
        }

        array<int, 3> flip;
        if (w == w0 + 3) {
            // flip all asked
            flip = {x1, x2, t2};
        } else if (w == w0 + 1) {
            // flip q asked
            flip = {y1, x2, t2};
        } else if (w == w0 - 1) {
            // flip s asked
            flip = {x1, y2, z2};
        } else {
            // flip non asked
            flip = {y1, y2, z2};
        }

        for (int x : flip) {
            a_sol[x] ^= 1;
        }
    }

    // Finish off leftovers
    while (p.size() > 0) {
        auto [x, y] = p.back();
        p.pop_back();

        int w;
        {
            auto a = a0;
            a[x] ^= 1;
            w = ask(a);
        }

        if (w == w0 + 1) {
            a_sol[x] ^= 1;
        } else {
            a_sol[y] ^= 1;
        }
    }

    while (q.size() > 0) {
        auto [x, y, z, t] = q.back();
        q.pop_back();

        int w;
        {
            auto a = a0;
            a[x] ^= 1;
            w = ask(a);
        }

        if (w == w0 + 1) {
            a_sol[x] ^= 1;
            a_sol[t] ^= 1;
        } else {
            a_sol[y] ^= 1;
            a_sol[z] ^= 1;
        }
    }

    ask(a_sol);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    solver(n, codeforces{n});
}