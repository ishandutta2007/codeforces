#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
using namespace std;

void solve(string s, int c){
    // c to ILE MA EXTRA KRATEK <=> ROZRZUT
    // mozemy tworzyc bloki <= ROZRZUT = c
    vector<pii> inter;
    int n = s.size();
    for(int i=0;i<n;i++){
        pii cur;
        while(s[i] != '#' && i < n) i++;
        if(i < n){
            int l = i;
            while(s[i] == '#') i++;
            i--;
            int r = i;
            inter.pb(mp(l+1, r+1));
        }
    }
    vector<int> ans;
    int done = 0;
    bool dbg = (c == 2);
    for(pii cur : inter){
        // dobrze przed, potem wrzuc cur
        int need = cur.st - c - 1;
        if(need < done) return;
        int build = need - done;
        if(build == 1) return;
        if(build != 0 && c == 0) return;
        if(c == 1 && build % 2 != 0) return;
        // else sie da xD
        while(build){
            if(build <= c + 1){
                ans.pb(build - 1);
                build = 0;
            }
            else{
                ans.pb(1);
                build -= 2;
            }
        }
        done = need;
        int len = cur.nd - cur.st + 1;
        done += len + c + 1;
        ans.pb(len + c);

    }

    int LEFT = n - c;
    done--;
    if(LEFT < done) return;
    int need = LEFT - done;

    int build = need;
    if(build == 1) return;
    if(build != 0 && c == 0) return;
    if(c == 1 && build % 2 != 0) return;
    // else sie da xD

    while(build){
        if(build <= c + 1){
            ans.pb(build - 1);
            build = 0;
        }
        else{
            ans.pb(1);
            build -= 2;
        }
    }
    cout<<ans.size()<<"\n";
    for(int x : ans) cout << x << " ";
    cout<<"\n";
    exit(0);


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    for(char x : s){
        if(x == '#') cnt++;
    }
    if(cnt == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int c=0;c<15;c++){
        solve(s, c);
    }
    cout << -1 << endl;
    return 0;



    return 0;
}