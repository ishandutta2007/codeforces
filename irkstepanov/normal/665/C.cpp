#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");

    string s;
    cin >> s;

    for (int i = 1; i < sz(s); ++i) {
        if (s[i] == s[i - 1]) {
            for (char c = 'a'; ; ++c) {
                if (i == sz(s) - 1 && s[i - 1] != c) {
                    s[i] = c;
                    break;
                }
                if (s[i - 1] != c && s[i + 1] != c) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << "\n";

}