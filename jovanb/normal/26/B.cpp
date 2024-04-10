#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int res=0;
    int br=0;
    for(auto c : s){
        if(c == '('){
            br++;
        }
        else if(br > 0){
            br--;
            res++;
        }
    }
    cout << res*2;
    return 0;
}