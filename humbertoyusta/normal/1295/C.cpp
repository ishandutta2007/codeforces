#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define maxn 100010
#define mod 1000000007
using namespace std;

vector<int> v[26];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    int tc, n;
    cin >> tc;
    string s1, s2;
    while( tc-- ){
        for(int i=0; i<26; i++)
            v[i].clear();
        cin >> s1 >> s2;
        for(int i=0; i<26; i++){
            v[i].push_back(-1);
            //v[i].push_back(mod+1);
        }
        for(int i=0; i<s1.size(); i++)
            v[s1[i]-'a'].push_back(i);
        for(int i=0; i<26; i++){
            v[i].push_back(mod);
            //v[i].push_back(mod+1);
        }
        int id = 0, nxt = -1, ans = 1;
        for(int i=0; i<s2.size(); i++){
            id = ( upper_bound((v[s2[i]-'a']).begin(),(v[s2[i]-'a']).end(),nxt) - (v[s2[i]-'a']).begin() );
            nxt = v[s2[i]-'a'][id];
            if( nxt != mod ) continue;
            ans++;
            id = 0;
            nxt = -1;
            id = ( upper_bound(v[s2[i]-'a'].begin(),v[s2[i]-'a'].end(),nxt) - v[s2[i]-'a'].begin() );
            nxt = v[s2[i]-'a'][id];
            if( nxt == mod ){ ans = -1; break; }
        }
        cout << ans << '\n';
    }

    return 0;
}