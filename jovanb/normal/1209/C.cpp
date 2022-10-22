#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int col[200005];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int k=0; k<=9; k++){
        string s1 = "", s2 = "";
        bool ima = 0;
        for(int i=0; i<n; i++){
            if(s[i]-'0' < k){
                s1 += s[i];
                col[i] = 1;
            }
            else if(s[i]-'0' > k){
                ima = 1;
                s2 += s[i];
                col[i] = 2;
            }
            else if(ima){
                s1 += s[i];
                col[i] = 1;
            }
            else{
                s2 += s[i];
                col[i] = 2;
            }
        }
        string str = s1+s2;
        bool moze = 1;
        for(int i=1; i<n; i++){
            if(str[i] < str[i-1]){
                moze = 0;
                break;
            }
        }
        if(moze){
            for(int i=0; i<n; i++) cout << col[i];
            cout << "\n";
            return;
        }
    }
    cout << "-\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}