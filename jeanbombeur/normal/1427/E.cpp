#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//<|_|>

const int MAX_OPERATIONS = (100 * 1000);

vector <int> A;
vector <char> op;
vector <int> B;

int x;

int Inverse(int a, int b) {
    a %= b;
    if (a <= 1)
    {
        return a;
    }
    return b - ((b * Inverse(b, a) - 1) / a);
}

void Add(int a, char o, int b) {
    if (a == 0 || b == 0)
    {
        return;
    }
    A.push_back(a);
    op.push_back(o);
    B.push_back(b);
    return;
}

int Sum(int a, int b) {
    Add(a, '+', b);
    return a + b;
}

int Xor(int a, int b) {
    Add(a, '^', b);
    return a ^ b;
}

int Mult(int a, int n) {
    int cur = a;
    int tot = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            tot = Sum(cur, tot);
        }
        cur = Sum(cur, cur);
        n /= 2;
    }
    return tot;
}

void Read() {
    cin >> x;
    int m = x;
    for (int i = 2; i < x; i *= 2)
    {
        m = Sum(m, m);
    }
    int y = Xor(m, x);
    int a = Mult(x, Inverse(x, y));
    if (a % 2 == 0)
    {
        a = Sum(a, Mult(x, y));
    }
    int b = Mult(y, (a - 1) / y);
    int c = Xor(a, b);
    c ++;
    int n = (int)A.size();
    cout << n << '\n';
    for (int i = 0; i < n; i ++)
    {
        cout << A[i] << " " << op[i] << " " << B[i] << '\n';
    }
    return;
}

signed main() {
    Read();
    return 0;
}