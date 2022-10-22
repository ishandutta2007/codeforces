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
    char mn = 'z'+1;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] > mn){
            cout << "Ann\n";
        }
        else{
            mn = s[i];
            cout << "Mike\n";
        }
    }
    return 0;
}