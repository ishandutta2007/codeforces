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

char m = int( 'a' - 1 );
int tmp = -1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    string s;

    int n;cin >> n;

    cin >> s;

    for(int i=0; i<s.size(); i++){
        if( s[i] > m ){
            tmp = i+1;
            m = s[i];
        }
        if( s[i] < m ){
            if( tmp == -1 ){ continue; }
                else{
                    cout << "YES\n";
                    cout << tmp << ' ' << i+1 << '\n';
                    return 0;
                }
        }
    }

    cout << "NO";

    return 0;
}