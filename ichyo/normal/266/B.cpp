#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    while(m --> 0){
        vector<bool> check(n, false);
        for(int i = 0; i < n - 1; i++){
            if(s[i] == 'B' && s[i + 1] == 'G'){
                check[i] = true;
            }
        }
        for(int i = 0; i < n - 1; i++){
            if(check[i]){
                s[i] = 'G';
                s[i + 1] = 'B';
            }
        }
    }
    cout << s << endl;
    return 0;
}