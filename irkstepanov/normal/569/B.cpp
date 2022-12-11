#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;

int main()
{

    int n;
    cin >> n;

    vector <int> a(n);
    vector <int> free(n, true);
    vector <int> cnt(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n) ++cnt[a[i] - 1];
        else ++cnt[n];
    }

    int ptr = 0;
    for (int i = 0; i <= n; i++)
        if (cnt[i]) free[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= n)
        {
            if (cnt[a[i] - 1] == 1) {cout << a[i] << " "; continue;}
            while (!free[ptr]) ++ptr;
            cout << ptr + 1 << " ";
            free[ptr] = false;
            ++cnt[ptr];
            --cnt[a[i] - 1];
        }
        else
        {
            while (!free[ptr]) ++ptr;
            cout << ptr + 1 << " ";
            free[ptr] = false;
            ++cnt[ptr];
            --cnt[n];
        }
    }

    cout << "\n";

}