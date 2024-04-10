#include <iostream>
#include <vector>

using namespace std;

int calc(string &s, int n)
{
    int ans = 0;
    vector<int> cnt(256);
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (cnt[i] + n < s.size())
            ans = max(ans, cnt[i] + n);
        else
            if (n == 1 && cnt[i] == s.size())
                ans = max(ans, (int)s.size() - 1);
            else
                ans = max(ans, (int)s.size());
    }
    if (n == s.size())
    {
        for (char c = 'a'; c <= 'z'; c++) if (cnt[c] == 0) return n;
        for (char c = 'A'; c <= 'Z'; c++) if (cnt[c] == 0) return n;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = calc(s, n);
    cin >> s;
    int y = calc(s, n);
    cin >> s;
    int z = calc(s, n);
    if (x > y && x > z)
    {
        cout << "Kuro";
        return 0;
    }
    if (y > x && y > z)
    {
        cout << "Shiro";
        return 0;
    }
    if (z > x && z > y)
    {
        cout << "Katie";
        return 0;
    }
    cout << "Draw";
}