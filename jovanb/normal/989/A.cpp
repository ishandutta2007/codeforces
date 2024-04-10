#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<n-2; i++){
        char a = s[i], b = s[i+1], c = s[i+2];
        if(a == 'A' && b == 'B' && c == 'C'){cout << "Yes"; return 0;}
        if(a == 'A' && b == 'C' && c == 'B'){cout << "Yes"; return 0;}
        if(a == 'B' && b == 'A' && c == 'C'){cout << "Yes"; return 0;}
        if(a == 'B' && b == 'C' && c == 'A'){cout << "Yes"; return 0;}
        if(a == 'C' && b == 'A' && c == 'B'){cout << "Yes"; return 0;}
        if(a == 'C' && b == 'B' && c == 'A'){cout << "Yes"; return 0;}
    }
    cout << "No";
    return 0;
    return 0;
}