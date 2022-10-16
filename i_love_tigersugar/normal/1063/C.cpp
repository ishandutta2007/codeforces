#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Fraction {
    int nom, denom;
    Fraction(int nom = 0, int denom = 1) {
        this->nom = nom;
        this->denom = denom;
    }

    int compare(const Fraction &f) const {
        long long tmp = 1LL * nom * f.denom - 1LL * f.nom * denom;
        return (tmp > 0) - (tmp < 0);
    }

    #define DEFINE_COMPARE(x) bool operator x (const Fraction &f) const { return compare(f) x 0; }
    DEFINE_COMPARE(<) DEFINE_COMPARE(>) DEFINE_COMPARE(==)
//    DEFINE_COMAPRE(<=) DEFINE_COMPARE(>=) DEFINE_COMPARE(!=)
};

#define NUM_PRIME   22
const int MAX_COST = (int)1e9;
const string BLACK = "black";
const string WHITE = "white";

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; 1LL * i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

vector<int> denoms;
long long numPoint;
void prepare(void) {
    int x = MAX_COST;
    while (denoms.size() < NUM_PRIME) {
        if (isPrime(x)) denoms.push_back(x); x--;
    }
//    FORE(it, denoms) cout << *it << " "; cout << endl;
    FORE(it, denoms) numPoint += *it - 1;
//    cerr << numPoint << endl;
}

int countLess(int nom, int denom, int other) {
    return denom == other ? nom : 1LL * nom * other / denom;
}
long long getIndex(const Fraction &f) {
    long long res = 0;
    FORE(it, denoms) res += countLess(f.nom, f.denom, *it);
    return res;
}

int getNom(long long index, long long denom) {
    int L = 1, R = denom;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return getIndex(Fraction(L, denom)) >= index ? L : R;
        int M = (L + R) >> 1;
        if (getIndex(Fraction(M, denom)) >= index) R = M; else L = M + 1;
    }
}

Fraction getFraction(long long index) {
    int tmp = getNom(index, denoms[0]);
    Fraction res(tmp, denoms[0]);
    FORE(it, denoms) {
        int nom = getNom(index, *it);
        minimize(res, Fraction(nom, *it));
    }
    return res;
}

map<Fraction, string> points;
string getColor(long long index) {
    Fraction frac = getFraction(index);
    cout << frac.nom << " " << frac.denom << endl;
    string color; cin >> color;
    points[frac] = color;
    return color;
}

void process(void) {
    int n; cin >> n;
    string firstColor = getColor(1);
    long long left = 2, right = numPoint;
    REP(love, n - 1) {
        assert(left < right);
        long long mid = (left + right) >> 1;
        string newColor = getColor(mid);
        if (newColor == firstColor) left = mid + 1;
        else right = mid - 1;
    }
    long long mid = (left + right) >> 1;
    Fraction frac = getFraction(mid);
    points[frac] = "divide";
    cout << "0 0 " << frac.nom << " " << frac.denom << endl;
//    FORE(it, points) cerr << it->se << " "; cerr << endl;
}

int main(void) {
    prepare();
//    REP(j, 2) FOR(i, 1, 10) printf("index of (%d / %d) is %lld\n", i, denoms[j], getIndex(Fraction(i, denoms[j])));
//
//    FOR(i, 1, 200) {
//        Fraction frac = getFraction(i);
//        printf("at %d is (%d / %d)\n", i, frac.nom, frac.denom);
//    }

    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/