/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

string s;
int open(inf),close,rp,lp(inf),len,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> s;

    for(int i=0; i<s.size(); i++){
        if( s[i] == '[' ) open = min( open , i );
        if( s[i] == ']' ) close = max( close , i );
        if( s[i] == ':' && open < i ) lp = min( lp , i );
    }

    for(int i=0; i<s.size(); i++){
        if( s[i]  == ':' && i < close ) rp = max( rp , i );
    }

    for(int i=0; i<s.size(); i++)
        if( s[i] == '|' && i > lp && i < rp ) ans++;

    if( open > close || lp >= rp ){ cout << -1; return 0; }

    cout << ans + 4;

    return 0;
}