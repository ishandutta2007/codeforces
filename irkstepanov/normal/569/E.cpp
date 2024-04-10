#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

const int nmax = 26;

int n;
string alphabet;
char next_v[nmax], next_c[nmax];
char first_v = '!', first_c = '!';

struct rule
{
    int from, to;
    char a, b;
};

vector <rule> rules;
vector <vector <int> > g;

char change(char &t)
{
    if (t == 'C') t = 'V';
    else t = 'C';
}

string s;
vector <char> met;

bool dfs(int v)
{
    met[v] = true;
    //cout << v << "\n";
    for (int i = 0; i < sz(g[v]); i++)
    {
        rule r = rules[g[v][i]];
        //cout << r.from << " " << r.a << " " << r.to << " " << r.b << "\n";
        if (alphabet[s[v] - 'a'] != r.a) continue;
        if (s[r.to] == '?')
        {
            if (r.b == 'V')
            {
                if (first_v == '!') return false;
                s[r.to] = first_v;
                if (!dfs(r.to)) return false;
            }
            if (r.b == 'C')
            {
                if (first_c == '!') return false;
                s[r.to] = first_c;
                if (!dfs(r.to)) return false;
            }
        }
        else
        {
            if (alphabet[s[r.to] - 'a'] != r.b) return false;
            if (met[r.to]) continue;
            if (!dfs(r.to)) return false;
        }
    }
    return true;
}

bool solve()
{
    met.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!met[i])
    {
        if (s[i] == '?')
        {
            if (first_v == '!') s[i] = first_c;
            else if (first_c == '!') s[i] = first_v;
            else s[i] = min(first_v, first_c);
        }
        if (!dfs(i)) return false;
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> alphabet;
    for (int i = 0; i < nmax; i++)
        next_v[i] = next_c[i] = '!';

    for (int i = 0; i < sz(alphabet); i++)
    {
        if (alphabet[i] == 'V' && first_v == '!')
            first_v = (char) (i + 'a');
        if (alphabet[i] == 'C' && first_c == '!')
            first_c = (char) (i + 'a');
    }

    for (int i = 0; i < sz(alphabet); i++)
    {
        for (int j = i + 1; j < sz(alphabet); j++)
        {
            if (alphabet[j] == 'V' && next_v[i] == '!')
                next_v[i] = (char) (j + 'a');
            if (alphabet[j] == 'C' && next_c[i] == '!')
                next_c[i] = (char) (j + 'a');
        }
    }

    cin >> n;

    int m;
    cin >> m;
    rules.resize(m * 2);
    g.resize(n);

    for (int i = 0; i < m; i++)
    {
        rule r;
        cin >> r.from >> r.a >> r.to >> r.b;
        --r.from, --r.to;
        rules[i * 2] = r;
        g[r.from].pb(i * 2);
        change(r.a);
        change(r.b);
        swap(r.from, r.to);
        swap(r.a, r.b);
        rules[i * 2 + 1] = r;
        g[r.from].pb(i * 2 + 1);
    }

    string word;
    cin >> word;

    string ans = "";

    for (int pref = n; pref >= 0; pref--)
    {
        if (pref < n)
        {
            if (next_v[word[pref] - 'a'] != '!')
            {
                s = word;
                for (int i = pref; i < n; i++)
                    s[i] = '?';
                s[pref] = next_v[word[pref] - 'a'];
                if (solve() && (ans == "" || ans > s)) ans = s;
            }
            if (next_c[word[pref] - 'a'] != '!')
            {
                s = word;
                for (int i = pref; i < n; i++)
                    s[i] = '?';
                s[pref] = next_c[word[pref] - 'a'];
                if (solve() && (ans == "" || ans > s)) ans = s;
            }
        }
        else
        {
            s = word;
            if (solve() && (ans == "" || ans > s)) ans = s;
        }
    }

    if (ans == "") cout << "-1\n";
    else cout << ans << "\n";

}