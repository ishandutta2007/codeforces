#include <bits/stdc++.h>

using namespace std;

#define long long long


long fun(long x) {
    if (x < 2)
        return -1;

    for (long i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            while (x % i == 0)
                x /= i;
            if (x == 1)
                return i;
            else
                return -1;
        }
    return x;
}

vector<long> d, ps;
map<long, vector<long>> t;
long A;


void addDivisor(long x) {
    d.push_back(x);
    long p = fun(x - 1);
    if (p != -1) {
        t[p].push_back(x);
        ps.push_back(p);
    }
}

void getD() {
    for (long i = 1; i * i <= A; ++i)
        if (A % i == 0) {
            addDivisor(i);
            if (i * i != A)
                addDivisor(A / i);
        }

    sort(d.begin(), d.end());
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

}

int getInd(long x) {
    return lower_bound(d.begin(), d.end(), x) - d.begin();
}

void din() {

    //cerr << "D = " << d.size() << "\n";

    vector<long> prev(d.size());
    vector<long> cur(d.size());

    prev[0] = cur[0] = 1;



    for (int i = 1; i <= (int) ps.size(); ++i) {
        vector<long> a = t[ps[i - 1]];

        /*cout << ps[i - 1] << ": ";
        for (auto x : a)
            cout << x << ", ";
        cout << endl;*/
        for (int j = 0; j < (int) d.size(); ++j)
            for (auto x : a)
                if (d[j] % x == 0)
                    cur[j] += prev[getInd(d[j] / x)];

        prev = cur;
        //fill(cur.begin(), cur.end(), 0);
    }

    cout << prev.back() << "\n";
}

int main() {
    cin >> A;

    getD();

    din();

    return 0;
}