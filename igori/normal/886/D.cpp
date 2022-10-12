#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define f(i, n) for (int i = 0; i < n; i++)
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define th third
#define a_ 1000000007
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
struct trio{
    int first;
    int second;
    int third;
};
struct long_trio{
    ll first;
    ll second;
    ll third;
};
const ll INF = 1e18 + 2;
const int LIT = 505;
const int BIG = 200001;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
ll st_10[10] = {1, 10, 100, 1000, 10000, 1000000, 10000000, 100000000, 1000000000};
//___________BAZE_________________
ll n, m, k, l, r, x, y, t, ans, k1, k2, k3, summ;
string s;
string after_those;
string before_those;
int kak[30];
string to_be_couted[30];
//___________VARIABLES____________

int main()
{
    for (int i = 0; i < 30; i++)
    {
        after_those = after_those + '.';
        before_those = before_those + '.';
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        kak[s[0] - 'a'] = 1;
        kak[s[s.sz - 1] - 'a'] = 1;
        for (int j = 0; j < s.sz - 1; j++)
        {
            kak[s[j] - 'a'] = 1;
            if (after_those[s[j] - 'a'] == '.' || after_those[s[j] - 'a'] == s[j + 1])
            {
                after_those[s[j] - 'a'] = s[j + 1];
            }
            else
            {
                r_NO;
            }
        }
        for (int j = 1; j < s.sz; j++)
        {
            kak[s[j] - 'a'] = 1;
            if (before_those[s[j] - 'a'] == '.' || before_those[s[j] - 'a'] == s[j - 1])
            {
                before_those[s[j] - 'a'] = s[j - 1];
            }
            else
            {
                r_NO;
            }
        }
    }
    //for (int i = 0; i < 26; i++)
    //{
    //    cout << (char)(i + 'a') << " " << after_those[i] << " " << before_those[i] << endl;
    //}
    x = 0;
    for (int i = 0; i < 26; i++)
    {
        if (kak[i] == 1 && before_those[i] == '.')
        {
            int copy_ = i;
            while (after_those[copy_] != '.')
            {
                to_be_couted[x] = to_be_couted[x] + (char)(copy_ + 'a');
                kak[copy_] = 0;
                copy_ = after_those[copy_] - 'a';
            }
            to_be_couted[x] = to_be_couted[x] + (char)(copy_ + 'a');
            kak[copy_] = 0;
            x++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (kak[i] == 1)
        {
            r_NO;
        }
    }
    sort(to_be_couted, to_be_couted + x);
    //cout << x;
    for (int i = 0; i < x; i++)
    {
        cout << to_be_couted[i];
    }
}