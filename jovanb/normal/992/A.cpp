#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <int, bool> bio;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    bio[0] = 1;
    int br=0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(!bio[x]) br++;
        bio[x] = 1;
    }
    cout << br;
    return 0;
}