#include<bits/stdc++.h>
#define maxn 1000005
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr<<#x<<": "<<(x)<<'\n'
using namespace std;
typedef long long ll;

string s, a, b, t;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        cin >> a >> b;

        s.clear(); t.clear();

        for(int i=0; i<n; i++)
            if( a[i] != b[i] ){
                s += a[i];
                t += b[i];
            }

        if( s.size() == 0 ){ cout << "Yes\n"; continue; }
        if( s.size() != 2 ){ cout << "No\n"; continue; }
        if( s[0] == s[1] && t[0] == t[1] ){ cout << "Yes\n"; continue; }
        cout << "No\n";
    }

    return 0;
}