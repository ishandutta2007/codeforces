#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    string m1[N], m2[N];
    for (int i = 0; i < n; i++)
        cin >> m1[i] >> m2[i];

    int pos[N];
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
        --pos[i];
    }

    string tek = "";

    for (int i = 0; i < n; i++)
    {
        int j = pos[i];
             if (m1[j] > tek && m2[j] < tek) tek = m1[j];
        else if (m1[j] < tek && m2[j] > tek) tek = m2[j];
        else if (m1[j] > tek && m2[j] > tek) tek = min(m1[j], m2[j]);
        else {cout << "NO\n"; return 0;}
    }

    cout << "YES\n";
    return 0;

}