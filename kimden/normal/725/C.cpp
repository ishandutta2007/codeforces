#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char arr[2][13];

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ind;
    for(ind = 0; ind < t.length() - 1; ind++){
        if(t[ind] == t[ind + 1]){
            break;
        }
    }
    char c = t[ind];
    for(int i = 0; i < s.length(); i++){
        if(s[0] == c){
            break;
        } else {
            s += s[0];
            s = s.substr(1, s.length() - 1);
        }
    }
    if(s[0] == s[1]){
        cout << "Impossible";
        return 0;
    }
    for(ind = 2; ind < s.length(); ind++){
        if(s[ind] == c){
            break;
        }
    }
    if(ind == 2){
        arr[0][0] = s[0];
        arr[1][0] = s[1];
        for(int i = 1; i < 13; i++){
            arr[1][i] = s[i + 2];
        }
        for(int i = 12; i > 0; i--){
            arr[0][i] = s[27 - i];
        }
    }else {
        int x = (ind - 1) / 2, y = 0, cnt = 0;
        while (cnt < 27) {
            arr[y][x] = s[cnt];
            if (y == 0) {
                x--;
                if (x < 0) {
                    x = 0;
                    y = 1;
                }
            } else {
                x++;
                if (x >= 13) {
                    x = 12;
                    y = 0;
                }
            }
            cnt++;
            if (cnt == ind) {
                cnt++;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        if(i){
            cout << endl;
        }
        for(int j = 0; j < 13; j++){
            cout << arr[i][j];
        }
    }
    return 0;
}