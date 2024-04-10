#include <bits/stdc++.h>
#define maxn 200010
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
string s,a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    cin >> s;

    for(int i=0; i<s.size(); i++){
        if( a.size() % 2 == 0 ) a += s[i];
            else
                if( s[i] != a[(int)a.size()-1] )
                    a += s[i];
    }

    cout << n - ( (int)a.size() - (int)a.size() % 2 ) << '\n';
    for(int i=0; i<(int)a.size() - (int)a.size() % 2; i++)
        cout << a[i];

    return 0;
}