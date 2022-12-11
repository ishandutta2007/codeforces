#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << 1;
        cout << "\n";
        return 0;
    }

    vector <int> x(n, -1);

    vector <int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    for (int i = 1; i < n; i++)
    {
        int n_new = i + 1;
        int k_new = n_new - pi[i];
        if (n_new % k == 0 && (n_new / k) % k_new == 0) x[i] = n_new / k;
    }

    for (int i = 0; i < n;)
    {
        if (x[i] == -1) {cout << 0; ++i; continue;}
        cout << 1;
        int len = x[i];
        int j;
        for (j = 1; j <= len && i + j < n; j++)
        {
            if (x[i + j] != -1) break;
            if (s[i + j] == s[j - 1]) cout << 1;
            else break;
        }
        i += j;
    }

}