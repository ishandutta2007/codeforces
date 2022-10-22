#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n;
string s; int cnt;

char pick(char aa, char bb, char cc, char dd){
    for(char f = 'a'; f <= 'z'; f++){
        if(
        f != aa &&
        f != bb &&
        f != cc &&
        f != dd
        
        ) return f;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> s; cnt = 0; n = s.size();
        for(int i = 0; i < n; i++){
            bool kil = 0;
            for(int j = i - min(i, 2); j < i; j++){
                if(s[j] == s[i]) kil = 1;
            }
            if(kil){
                s[i] = pick(s[min(i + 1, n - 1)], s[min(i + 2, n - 1)],
                s[max(0, i - 1)], s[max(0, i - 2)]); cnt++;
            }
        }
        cout << cnt << endl;
    }
}