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
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    vector<pair<int, int>> ps;
    FOR(i, n) {
        pair<int, int> t;
        cin >> t.first >> t.second;
        ps.push_back(t);
    }

    sort(ALL(ps), [](pair<int,int> i, pair<int,int> j){return i.first < j.first;});

    vector<int> dp; // what happens, if we trow the rightmost
    vector<int> pos;
    dp.push_back(0);
    pos.push_back(ps.front().first);

    FORR(i, 1, n)
    {
        auto p = ps[i];

        int current_pos = p.first - p.second;

        int index = lower_bound(ALL(pos), current_pos) - pos.begin();

        int score;
        if (index >= 1) {
            score = i - index + dp[index - 1];
        }
        else
        {
            score = i - index;
        }
        dp.push_back(score);

        //cout << index << "   " << score << endl;
        pos.push_back(p.first);
    }


    //cout << endl;
    int result = n;
    FOR(i, n)
    {
        int t = n - i - 1 + dp[i];
      //  cout << t << endl;
        result = min(result, t);
    }

    //cout << endl;
    cout << result;
}