#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, t, first_number, first_idx=0, second_number=-1, second_idx, idx=0;
    cin >> n;

    cin >> first_number;
    int max_length = 0;
    FORR(i, 1, n) {
        cin >> t;
        if (t == first_number)
        {
            idx = i;
        }
        else if (second_number == -1)
        {
            second_idx = i;
            second_number = t;
            swap(first_number, second_number);
        }
        else if (t == second_number)
        {
            second_idx = i;
            swap(first_number, second_number);
        }
        else
        {
            max_length = max(max_length, i-first_idx);
            first_idx = second_idx;
            second_idx = i;


            second_number = first_number;
            first_number = t;
        }
    }
    max_length = max(max_length, n-first_idx);

    cout << max_length;
}