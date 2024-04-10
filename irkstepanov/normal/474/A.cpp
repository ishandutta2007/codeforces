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

    char d;
    cin >> d;

    string s;
    cin >> s;
    string m[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

    for (int i = 0; i < s.size(); i++)
    {
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < m[a].size(); b++)
            if (m[a][b] == s[i])
        {
            if (d == 'L') cout << m[a][b + 1];
            else cout << m[a][b - 1];
        }
    }

    cout << "\n";

}