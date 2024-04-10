#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int br[5];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> s;
    int n = s.size();
    int prvo2=-1;
    for(int i=0; i<n; i++){
        if(s[i] == '2' && prvo2 == -1){
            prvo2 = i;
        }
        else if(s[i] == '1'){
            br[1]++;
        }
        else br[0]++;
    }
    if(prvo2 == -1){
        while(br[0]--) cout << 0;
        while(br[1]--) cout << 1;
        return 0;
    }
    for(int i=0; i<n; i++){
        if(s[i] == '1') continue;
        if(prvo2 == i){
            while(br[1]--) cout << 1;
        }
        cout << s[i];
    }
    return 0;
}