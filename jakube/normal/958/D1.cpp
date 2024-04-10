#include <bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    Fraction() : a(0), b(1) {}
    Fraction(long long a) : a(a), b(1) {}
    Fraction(long long num, long long den) : a(num), b(den) {
        long long g = gcd(a, b);
        if (b < 0)
            g = -g;
        a /= g;
        b /= g;
    }
    
    Fraction& operator+=(Fraction const& other) {
        long long g = gcd(b, other.b);
        a = a * (other.b / g) + (b / g) * other.a;
        b = b / g * other.b;
        return *this;
    }

    Fraction operator+(Fraction const& other) const {
        Fraction t = *this; t += other; return t;
    }

    Fraction& operator-=(Fraction const& other) {
        long long g = gcd(b, other.b);
        a = a * (other.b / g) - (b / g) * other.a;
        b = b / g * other.b;
        return *this;
    }

    Fraction operator-(Fraction const& other) const {
        Fraction t = *this; t -= other; return t;
    }

    Fraction& operator*=(Fraction const& other) {
        long long g1 = gcd(a, other.b);
        long long g2 = gcd(b, other.a);
        a = (a / g1) * (other.a / g2);
        b = (b / g2) * (other.b / g1);
        return *this;
    }

    Fraction operator*(Fraction const& other) const {
        Fraction t = *this; t *= other; return t;
    }

    Fraction& operator/=(Fraction const& other) {
        *this *= Fraction(copy_sign(other.b, other.a), std::abs(other.a));
        return *this;
    }

    Fraction operator/(Fraction const& other) const {
        Fraction t = *this; t /= other; return t;
    }

    bool operator<(Fraction const& other) const {
        return a * other.b < other.a * b;
    }

    bool operator<=(Fraction const& other) const {
        return a * other.b <= other.a * b;
    }

    bool operator>(Fraction const& other) const {
        return a * other.b > other.a * b;
    }

    bool operator>=(Fraction const& other) const {
        return a * other.b >= other.a * b;
    }

    bool operator==(Fraction const& other) const {
        return a * other.b == other.a * b;
    }

    bool operator!=(Fraction const& other) const {
        return a * other.b != other.a * b;
    }

    long long floor() const {
        return a / b;
    }

    operator double() const {
        return (double)a / b;
    }

    static long long gcd(long long a, long long b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    static long long copy_sign(long long a, long long b) {
        return b >= 0 ? a : -a;
    }

    long long a, b;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Fraction> fractions(n);
    map<Fraction, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto plus = s.find('+');
        auto div = s.find('/');
        string s1 = s.substr(1, plus - 1);
        string s2 = s.substr(plus + 1, div - plus - 2);
        string s3 = s.substr(div + 1);
        fractions[i] = {stoi(s1) + stoi(s2), stoi(s3)};
        m[fractions[i]]++;
    }

    for (auto f : fractions)
        cout << m[f] << ' ';
    cout << endl;
}