#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int convert(int val, int p)
{
    int sum = 0;
    while (val) {
        sum += val % p;
        val /= p;
    }
    return sum;
}

int gcd(int a, int b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int a;
    cin >> a;

    int sum = 0;
    int cnt = 0;
    for (int i = 2; i < a; ++i) {
        sum += convert(a, i);
        ++cnt;
    }

    int d = gcd(sum, cnt);
    cout << sum / d << "/" << cnt / d << "\n";

}