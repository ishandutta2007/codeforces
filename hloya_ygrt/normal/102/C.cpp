#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7,maxm= 1e4+5;

bool used[maxn];
bool del[26];
pair<int,char> cnt[26];
int main()
{
    string s;
    int k;
    cin >> s >> k;
    for (int i=0;i<26;i++)
        cnt[i].s = i;
    for (int i=0;i<s.size();i++)
        cnt[s[i]-'a'].f++;
    sort(cnt, cnt + 26);
    for (int i=0;i<26 && k > 0;i++){
        if ( cnt[i].f <= k ){
            k -= cnt[i].f;
            del[cnt[i].s] = 1;
        }
    }
    int dif = 0;
    string ans;
    for (int i=0;i<s.size();i++)
        if (!del[s[i]-'a'])
            ans.pb(s[i]);
    for (int i=0;i<ans.size();i++)
        if (!used[ans[i]-'a']){
            used[ans[i]-'a'] = 1;
            dif++;
    }
    cout<<dif<<endl<<ans;
}