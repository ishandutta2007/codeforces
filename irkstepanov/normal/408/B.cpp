#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main()
{

    int in[30], out[30];
    string s;
    int i;

    cin >> s;

    for (i = 0; i < 26; i++)
        in[i] = 0, out[i] = 0;

    for (i = 0; i < s.size(); i++)
        in[s[i] - 'a']++;

    cin >> s;
    for (i = 0; i < s.size(); i++)
        out[s[i] - 'a']++;

    int ans = 0;

    for (i = 0; i < 26; i++)
    if (out[i] != 0 && in[i] == 0) {ans = -1; break;}
    else ans += min(in[i], out[i]);

    cout << ans;

}