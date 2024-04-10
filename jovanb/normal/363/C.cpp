#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string str;
    long i;
    cin >> str;
    for(i=str.size()-1; i>=0; i--){
        if(str[i] == str[i-1] && str[i-1] == str[i-2]) str.erase(i,1);
    }
    for(i=0; i<str.size(); i++)
        if(str[i] == str[i+1] && str[i+2] == str[i+3]){
            str.erase(i+2, 1);
            i++;
        }
    cout<<str;
    return 0;
}