#include <bits/stdc++.h>
#include <windows.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>

using namespace std;

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e4 + 5, base = 1e9+7;

void bad(string mes = "NO"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
	string ans = "";
	while (x > 0){
		ans += char('0' + x % 2);
		x /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans.empty() ? "0" : ans;
}

template<typename T = int >
T input(){
	T ans = 0, m = 1;
	char c = ' ';
	while (c == ' ' || c == '\n')
		c = getchar();
	if (c == '-')
		m = -1,	c = getchar();
	while (c != ' ' && c != '\n')
		ans = ans * 10 + c - '0', c = getchar();
	return ans * m;
}

template<typename T>
T sqr(T x)
{
	return x * x;
}

bool dp[maxn][2];
int main()
{
    set<string> q;
    string t;
    cin >> t;
    for (int st = 5; st < t.size(); st++){
        string cur = "";
        if (st + 1 < t.size()){
            cur += t[st];
            cur += t[st + 1];
            memset(dp, 0, sizeof(dp));
            dp[st][0] = 1;
            for (int i = st + 1; i < t.size(); i++){
                if (i + 1 < t.size() && i - 2 >= st && !(t[i - 2] == t[i] && t[i - 1] == t[i + 1])){
                    dp[i][0] |= dp[i - 2][0];
                }
                if (i + 1 < t.size() && i - 3 >= st){
                    dp[i][0] |= dp[i - 3][1];
                }
                if (i + 2 < t.size() && i - 3 >= st && !(t[i - 3] == t[i] && t[i - 2] == t[i + 1] && t[i - 1] == t[i + 2])){
                    dp[i][1] |= dp[i - 3][1];
                }
                if (i + 2 < t.size() && i - 2 >= st){
                    dp[i][1] |= dp[i - 2][0];
                }
            }
            if (dp[t.size() - 2][0] == 1 || dp[t.size() - 3][1] == 1){
                q.insert(cur);
            }
        }

        cur = "";
        if (st + 2 < t.size()){
            cur += t[st];
            cur += t[st + 1];
            cur += t[st + 2];
            memset(dp, 0, sizeof(dp));
            dp[st][1] = 1;
            for (int i = st + 1; i < t.size(); i++){
                if (i + 1 < t.size() && i - 2 >= st && !(t[i - 2] == t[i] && t[i - 1] == t[i + 1])){
                    dp[i][0] |= dp[i - 2][0];
                }
                if (i + 1 < t.size() && i - 3 >= st){
                    dp[i][0] |= dp[i - 3][1];
                }
                if (i + 2 < t.size() && i - 3 >= st && !(t[i - 3] == t[i] && t[i - 2] == t[i + 1] && t[i - 1] == t[i + 2])){
                    dp[i][1] |= dp[i - 3][1];
                }
                if (i + 2 < t.size() && i - 2 >= st){
                    dp[i][1] |= dp[i - 2][0];
                }
            }
            if (dp[t.size() - 2][0] == 1 || dp[t.size() - 3][1] == 1){
                q.insert(cur);
            }
        }

    }

    cout << q.size() << "\n";
    for (auto i = q.begin(); i != q.end(); i++)
        cout << *i << "\n";
    return 0;
}