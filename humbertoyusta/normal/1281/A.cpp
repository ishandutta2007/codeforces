#include<bits/stdc++.h>
#define maxn 200010
#define mod 1000000007
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){
        string s;
        cin >> s;
        if( s.size() >= 2 ) if( s[s.size()-2] == 'p' && s[s.size()-1] == 'o' ) cout << "FILIPINO\n";
        if( s.size() >= 4 ) if( s[s.size()-4] == 'd' && s[s.size()-3] == 'e' && s[s.size()-2] == 's' && s[s.size()-1] == 'u' ) cout << "JAPANESE\n";
        if( s.size() >= 4 ) if( s[s.size()-4] == 'm' && s[s.size()-3] == 'a' && s[s.size()-2] == 's' && s[s.size()-1] == 'u' ) cout << "JAPANESE\n";
        if( s.size() >= 5 ) if( s[s.size()-5] == 'm' && s[s.size()-4] == 'n' && s[s.size()-3] == 'i' && s[s.size()-2] == 'd' && s[s.size()-1] == 'a' ) cout << "KOREAN\n";
    }

    return 0;
}