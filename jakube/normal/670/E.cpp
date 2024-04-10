#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int move_L(int p, vector<bool> &removed, vector<int> &next)
{
    p--;
    if (removed[p])
    {
        int outer = p;
        p = next[p];
        p--;

        while (removed[p])
        {
            p = next[p];
            next[outer] = p;
            next[p] = outer;
            p--;
        }
    }
    return p;
}

int move_R(int p, vector<bool> &removed, vector<int> &next)
{
    p++;
    if (removed[p])
    {
        int outer = p;
        p = next[p];
        p++;
        while (removed[p])
        {
            p = next[p];
            next[outer] = p;
            next[p] = outer;
            p++;
        }
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, p;
    cin >> n >> m >> p;

    string s;
    cin >> s;
    string seq;
    cin >> seq;

    stack<int> st;
    vector<int> next(n, -1);
    FOR(i, n)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            int tmp = st.top();
            st.pop();
            next[i] = tmp;
            next[tmp] = i;
        }
    }

    vector<bool> removed(n, false);
    p--;

    for (auto c : seq)
    {
        if (c == 'L')
        {
            p = move_L(p, removed, next);
        }
        else if (c == 'R')
        {
            p = move_R(p, removed, next);
        }
        else
        {
            removed[p] = true;
            removed[next[p]] = true;
            p = max(p, next[p]);
            p = move_R(p, removed, next);
            if (p == s.size())
                p = move_L(p, removed, next);
        }
    }

    p = 0;
    string out = "";
    while (p < n)
    {
        if (!removed[p])
            out += s[p];
        else
            p = next[p];
        p++;
    }
    cout << out << endl;
}