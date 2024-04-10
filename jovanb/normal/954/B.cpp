#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, minres;
    string str;
    cin >> n;
    cin >> str;
    minres = n;
    for(int i=1; i<n; i+=2){
        int len = (i+1)/2;
        string str1 = "";
        string str2 = "";
        for(int j=0; j<len; j++){
            str1 += str[j];
        }
        for(int j=len; j<2*len; j++){
            str2 += str[j];
        }
        if(str1 == str2) minres = min(minres, n-len+1);
    }
    cout << minres;
    return 0;
}