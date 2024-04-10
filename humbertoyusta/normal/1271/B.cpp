#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    string s;

    cin >> s;

    string a = s;
    vector<int> ans;
    for( int i=0; i<a.size()-1; i++){
        if( a[i] == 'B' ){
            a[i] = 'W';
            ans.push_back(i+1);
            if( a[i+1] == 'W' ){ a[i+1] = 'B'; continue; }
            if( a[i+1] == 'B' ){ a[i+1] = 'W'; continue; }
        }
    }
    if( a[a.size()-1] == 'W' ){
        cout << ans.size() << '\n';
        for( auto i : ans )
            cout << i << ' ';
        return 0;
    }

    ans.clear();
    for( int i=0; i<s.size()-1; i++){
        if( s[i] == 'W' ){
            s[i] = 'B';
            ans.push_back(i+1);
            if( s[i+1] == 'W' ){ s[i+1] = 'B'; continue; }
            if( s[i+1] == 'B' ){ s[i+1] = 'W'; continue; }
        }
    }
    if( s[s.size()-1] == 'B' ){
        cout << ans.size() << '\n';
        for( auto i : ans )
            cout << i << ' ';
        return 0;
    }

    cout << -1 << '\n';

    return 0;
}