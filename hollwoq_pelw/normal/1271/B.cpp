#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int wc=0, bc=0;
    for (char c:s){
        wc += (c=='W');
        bc += (c=='B');
    }
    //cout << wc << ' ' << bc << endl;
    char a,b;
    if (wc % 2 == 1 && bc % 2 == 1){
        cout << -1;
        return 0;
    }else if (wc % 2 == 0){
        a = 'W', b = 'B';
    }else {
        a = 'B', b = 'W';
    }
    //cout << a << ' ' << b << endl;
    vector<int> res;
    for (int i = 0; i < n-1; i++){
        if (s[i] == a){
            s[i] = b;
            if (s[i+1] == a) s[i+1] = b;
            else s[i+1] = a;
            res.push_back(i+1);
        }
    }
    cout << res.size() << endl;
    for (auto i:res){
        cout << i << ' ';
    }
}