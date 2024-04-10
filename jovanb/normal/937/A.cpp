#include <bits/stdc++.h>
using namespace std;

bool bio[700];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    bio[0] = true;
    int br=0;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(bio[x]) continue;
        bio[x] = true;
        br++;
    }
    cout << br;
    return 0;
}