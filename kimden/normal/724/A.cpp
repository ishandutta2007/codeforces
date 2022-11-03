#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
    int a[3] = {28, 30, 31};
    int b[2];
    bool ans = false;
    string s;
    for(int i = 0; i < 2; i++){
        cin >> s;
        if(s == "monday"){
            b[i] = 0;
        }else if(s == "tuesday"){
            b[i] = 1;
        }else if(s == "wednesday"){
            b[i] = 2;
        }else if(s == "thursday"){
            b[i] = 3;
        }else if(s == "friday"){
            b[i] = 4;
        }else if(s == "saturday"){
            b[i] = 5;
        }else if(s == "sunday"){
            b[i] = 6;
        }
    }
    for(int i = 0; i < 3; i++){
        if((b[0] + a[i] + 7 - b[1]) % 7 == 0){
            ans = true;
            break;
        }
    }
    if(ans){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}