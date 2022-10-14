#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n;
map<pair<int,char>,vector<string>> mp;
string a[maxn];
vector<pair<string,string>> good,bad;
vector<pair<int,string>> tmp;
vector<pair<pair<string,string>,pair<string,string>>> ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        int cv = 0; char lv;
        for( auto j : a[i] )
            if( j == 'a' || j == 'e' || j == 'o' || j == 'i' || j == 'u' )
                cv++, lv = j;
        if( mp[{cv,lv}].size() != 0 ){
            string mc = mp[{cv,lv}][mp[{cv,lv}].size()-1];
            good.push_back({a[i],mc});
            mp[{cv,lv}].pop_back();
            continue;
        }
        mp[{cv,lv}].push_back(a[i]);
    }

    for( auto i : mp )
        for( auto j : i.s )
            tmp.push_back({i.f.f,j});

    for(int i=1; i<tmp.size(); ){
        if( tmp[i].f == tmp[i-1].f ){
            bad.push_back({tmp[i].s,tmp[i-1].s});
            i += 2;
        }
        else i++;
    }

    for(int i=0; i<min(good.size(),bad.size()); i++)
        ans.push_back({{bad[i].f,good[i].f},{bad[i].s,good[i].s}});

    for(int i=min(good.size(),bad.size()); i+1<good.size(); i+=2 )
        ans.push_back({{good[i].f,good[i+1].f},{good[i].s,good[i+1].s}});

    cout << ans.size() << '\n';
    for( auto i : ans )
        cout << i.f.f << ' ' << i.f.s << '\n' << i.s.f << ' ' << i.s.s << '\n';

    return 0;
}