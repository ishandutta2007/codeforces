#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;
const int N = 1000000 + 100;

int main()
{

    //ifstream cin ("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    vector <int> gr(N);

    int l = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            gr[l] = i + 1;
            ++l;
        }
    }

    int m;
    cin >> m;

    while (m--)
    {
        int x;
        cin >> x;
        cout << gr[x - 1] << "\n";
    }

}