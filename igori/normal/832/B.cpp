#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll n, m, k;
ll good[100];

int main()
{
    string s, need;
    int have_smth = 0;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        good[s[i] - 'a'] = 1;
    }
    cin >> s;
    cin >> n;
    for (int i = 0; i <(int)s.size(); i++)
    {
        if (s[i] == '*')
            have_smth = 1;
    }
    int rez = 1;
    k = s.size();
    for (int i = 0; i < n; i++)
    {
        rez = 1;
        cin >> need;
        if ((int)need.size() < k - 1)
        {
            cout << "NO" << endl;
            continue;
        }
        if ((int)need.size() != (int)s.size() && have_smth == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int j = 0;
        while (j < k && j < (int)need.size() && s[j] != '*')
        {
            if (s[j] >= 'a' && s[j] <= 'z')
            {
                if (s[j] != need[j])
                {
                    cout << "NO" << endl;
                    rez = 0;
                    break;
                }
            }
            else
            {
                if (good[need[j] - 'a'] == 0)
                {
                    cout << "NO" << endl;
                    rez = 0;
                    break;
                }
            }
            j++;
        }
        if (rez == 0)
        {
            continue;
        }
        int end_j = k - 1;
        int end_need = (int)need.size() - 1;
        while (end_j >= 0 && end_need >= 0 && s[end_j] != '*')
        {
            if (s[end_j] >= 'a' && s[end_j] <= 'z')
            {
                if (s[end_j] != need[end_need])
                {
                    cout << "NO" << endl;
                    rez = 0;
                    break;
                }
            }
            else
            {
                if (good[need[end_need] - 'a'] == 0)
                {
                    cout << "NO" << endl;
                    rez = 0;
                    break;
                }
            }
            end_j--;
            end_need--;
        }
        if (rez == 0)
            continue;
        for (int x = j; x <= end_need; x++)
        {
            if (good[need[x] - 'a'] == 1)
            {
                cout << "NO" << endl;
                rez = 0;
                break;
            }
        }
        if (rez == 1)
            cout << "YES" << endl;
    }
}