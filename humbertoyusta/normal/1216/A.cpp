#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    string a;
    cin >> a;
    for(int i=0; i<a.size(); i+=2){
        if( a[i] == 'a' && a[i+1] == 'a' )
            a[i] = 'b', ans++;
        if( a[i] == 'b' && a[i+1] == 'b' )
            a[i] = 'a', ans++;
    }
    cout << ans << '\n' << a << '\n';

    return 0;
}