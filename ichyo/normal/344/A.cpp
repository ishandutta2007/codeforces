#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    string last;
    cin >> last;
    int ans = 1;
    for(int i = 0; i < n - 1; i++){
        string s;
        cin >> s;
        if(s != last){
            last = s;
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}