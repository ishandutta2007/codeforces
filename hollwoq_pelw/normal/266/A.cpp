#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int m,res=0;
    string s;
    cin >> m >> s;
    for (int i = 0; i < m-1; i++){
        if (s[i] == s[i+1]) res ++;
    }
    cout << res;
    return 0;
}