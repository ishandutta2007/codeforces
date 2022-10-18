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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    vector<int> counts(26, 0);
    for (char c : s)
    {
        counts[c - 'a']++;
    }
    
    vector<char> result(s.size(), '.');

    for (int prime = 2; prime <= s.size(); prime++)
    {
        bool is_prime = true;
        for (int divisor = 2; divisor*divisor <= prime; divisor++)
        {
            if (prime % divisor == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            set<char> se;
            for (int i = prime; i <= s.size(); i+=prime)
            {
                for (int divisor = 2; divisor*divisor <= i; divisor++)
                {
                    if (i % divisor == 0)
                        se.insert(result[divisor-1]);
                }
            }
            se.erase('.');
            if (se.size() > 1)
            {
                cout << "NO" << endl;
                return 0;
            }

            char c;
            if (se.size() == 1)
            {
                char c = *se.begin();
            }
            else
            {
                int m = 0;
                FOR(k, 26)
                {
                    if (counts[m] < counts[k])
                        m = k;
                }
                c = 'a' + m;                
            }

            for (int i = prime; i <= s.size(); i+=prime)
            {
                if (result[i-1] == '.')
                {
                    if (!counts[c - 'a'])
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
                    counts[c - 'a']--;
                    result[i-1] = c;
                }
            }
        }
    }
    
    FOR(i, 26)
    {
        if (counts[i])
            result[0] = 'a' + i;
    }

    DBG("YES");
    DBG(string(ALL(result)));
}