#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    long long sol(0),n;

    cin >> n >> s;

    for(int i=0; i<n; i++){
        if( ( int(s[i] - '0') ) % 2 == 0 ) sol += i+1;
    }

    cout << sol;

    return 0;
}