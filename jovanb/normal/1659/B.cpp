#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int uses[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(k%2){
            for(int i=0; i<n; i++) s[i] = '0' + ('1' - s[i]);
        }
        for(int i=0; i<n; i++) uses[i] = 0;
        for(int i=0; i<n; i++){
            if(k > 0 && s[i] == '0'){
                k--;
                s[i] = '1';
                uses[i] = 1;
            }
        }
        if(k%2) s.back() = '0';
        uses[n - 1] += k;
        cout << s << "\n";
        for(int i=0; i<n; i++) cout << uses[i] << " ";
        cout << "\n";
    }
    return 0;
}