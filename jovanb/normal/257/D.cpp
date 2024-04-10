#include <bits/stdc++.h>
using namespace std;

char s[100005];
int niz[100005];

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    s[n] = '+';
    int sum = niz[n];
    for(int i=n-1; i>=1; i--){
        if(sum < 0){
            sum += niz[i];
            s[i] = '+';
        }
        else{
            sum -= niz[i];
            s[i] = '-';
        }
    }
    if(sum < 0){
        for(int i=1; i<=n; i++){
            if(s[i] == '+') s[i] = '-';
            else s[i] = '+';
        }
    }
    for(int i=1; i<=n; i++) cout << s[i];
    return 0;
}