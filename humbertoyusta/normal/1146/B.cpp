/** Name: Humberto Yusta Gomez
    Pais: Cuba
    Prov: Villa Clara
    Grado: 11no
    Copyright              **/
#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

string s,t;
int c[maxn],a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> s;
    s = '&' + s;

    for(int i=1; i<s.size(); i++){
        c[i] = c[i-1] + ( s[i] != 'a' );
        a[i] = a[i-1] + ( s[i] == 'a' );
    }

    for(int i=1; i<s.size(); i++){
        if( s[i] != 'a' ) t += s[i];
        if( a[i] == a[s.size()-1] && c[i] == c[s.size()-1] / 2 ){
            for(int j=i+1; j<s.size(); j++)
                if( s[j] != t[j-i-1] ){ cout << ":("; return 0; }
            for(int j=1; j<=i; j++)
                cout << s[j];
            return 0;
        }
    }

    cout << ":(";

    return 0;
}