#include <bits/stdc++.h>

#ifndef OCT_MODINT_HPP
#define OCT_MODINT_HPP

namespace Oct {

template <typename DataType, DataType Mod, typename OperType = DataType>
class ModInt {
   public:
    using CurrentType = ModInt<DataType, Mod, OperType>;
    using ThisType = CurrentType;

   protected:
    DataType Data;

   public:
    inline ModInt() : Data(0) {}
    inline ModInt(const DataType Val) : Data(Val) {}

    inline const DataType Value() const { return this->Data; }
    inline DataType &LValue() { return this->Data; }

    inline bool operator==(CurrentType x) const {
        return this->Value() == x.Value();
    }
    inline bool operator!=(CurrentType x) const {
        return this->Value() != x.Value();
    }

    inline CurrentType operator+(CurrentType x) const {
        return (x.LValue() += this->Value()) >= Mod ? x.Value() - Mod
                                                    : x.Value();
    }
    inline CurrentType &operator+=(CurrentType x) {
        if ((this->LValue() += x.Value()) >= Mod) this->LValue() -= Mod;
        return *this;
    }

    inline CurrentType operator-(CurrentType x) const {
        x.LValue() = this->Value() + Mod - x.Value();
        return x.Value() >= Mod ? x.Value() - Mod : x.Value();
    }
    inline CurrentType &operator-=(CurrentType x) {
        this->LValue() += Mod - x.Value();
        if (this->Value() >= Mod) this->LValue() -= Mod;
        return *this;
    }

    inline CurrentType operator+() { return *this; }
    inline CurrentType operator-() { return 0 - *this; }

    inline CurrentType operator*(CurrentType x) const {
        return this->Value() * OperType(x.Value()) % Mod;
    }
    inline CurrentType &operator*=(CurrentType x) {
        this->LValue() = this->Value() * OperType(x.Value()) % Mod;
        return *this;
    }

    inline CurrentType Pow(DataType Exp) const {
        CurrentType x = *this, ret = 1;
        while (Exp) {
            if (Exp & 1) ret *= x;
            x *= x, Exp >>= 1;
        }
        return ret;
    }

    inline CurrentType Inv() const { return this->Pow(Mod - 2); }

    inline CurrentType operator/(CurrentType x) const {
        return *this * x.Inv();
    }
    inline CurrentType &operator/=(CurrentType x) { return *this *= x.Inv(); }
};

}  // namespace Oct

#endif

using int32 = int;
using int64 = long long;
using uint64 = unsigned long long;

const int D = 20;
const int N = 1 << D;
const int32 P = 998244353;

using MInt = Oct::ModInt<int32, P, int64>;
const int32 Q = P - 1;

using Answer = std::vector<int>;

const int G = 3;

int n, ea = 1, eb = 1, Num, cb, cw;
int Rev[N], w[N];

MInt Ans, rAns;
MInt Fac[N], FacR[N];

std::string s;

inline bool Check(int x) { return (Num & x) == x; }

inline MInt C(int m, int n) { return Fac[m] * FacR[n] * FacR[m - n]; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    Fac[0] = 1;
    for (int i = 1; i < N; ++i) Fac[i] = Fac[i - 1] * i;
    FacR[N - 1] = Fac[N - 1].Inv();
    for (int i = N - 1; i; --i) FacR[i - 1] = FacR[i] * i;
    std::cin >> n, rAns = 1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s;
        Num = 0;
        if (s[0] == 'B') Num |= 0b0001, ++cb;
        if (s[0] == 'W') Num |= 0b0010, ++cw;
        if (s[0] == '?') Num |= 0b0011;
        if (s[1] == 'B') Num |= 0b0100, ++cb;
        if (s[1] == 'W') Num |= 0b1000, ++cw;
        if (s[1] == '?') Num |= 0b1100;
        rAns *= (Check(0b0110) + Check(0b1001));
        ea &= Check(0b0110), eb &= Check(0b1001);
    }
    Ans = cb > n || cw > n ? 0 : C(n + n - cb - cw, n - cb);
    Ans -= rAns -= ea + eb;
    std::cout << Ans.Value() << std::endl;
    return 0;
}