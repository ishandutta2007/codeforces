#include <bits/stdc++.h>
using namespace std;

vector<bool> columns;

int main() {
    int t;
    cin >> t;
    while(t--) {
        bool AWESOME=true;
        string s;
        int r, c, ans=5;
        cin >> r >> c;
        getline(cin, s);
        for(int a=0; a<r; a++) {
            getline(cin, s);
            bool check=true;
            for(int b=0; b<c; b++) {
                if(s.at(b)=='A') {
                    if(a==0) columns.push_back(true);
                    int x = (a==0 || a==r-1) + (b==0 || b==c-1);
                    ans=min(ans, 4-x);
                }
                else {
                    if(a==0) columns.push_back(false);
                    else columns[b]=false;
                    check=false;
                }
            }
            if(check==true)  {
                if(a==0 || a==r-1) ans=min(ans, 1);
                else ans=min(ans, 2);
            }
            else AWESOME=false;
        }
        for(int b=0; b<c; b++) {
            if(columns[b]==true) {
                if(b==0 || b==c-1) ans=min(ans, 1);
                else ans=min(ans, 2);
            }
        }
        if(AWESOME) ans=0;
        if(ans==5) cout << "MORTAL\n";
        else cout << ans << '\n';
        vector<bool>().swap(columns);
    }
}