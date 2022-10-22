#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,s,v,j,s1,s2;
    cin >> t >> s >> v >> j >> s1 >> s2;
    int a1 = t;
    int a2 = s;
    if (v < s) a2 = v;
    long res = 0;
    if (s1 > s2){
        if (j > a1){
            res += a1*s1;
            j -= a1;
        }else{
            res += j*s1;
            j = 0;
        }
        if (j > a2){
            res += a2*s2;
        }else{
            res += j*s2;
        }
    }else{
        if (j > a2){
            res += a2*s2;
            j -= a2;
        }else{
            res += j*s2;
            j = 0;
        }
        if (j > a1){
            res += a1*s1;
        }else{
            res += j*s1;
        }
    }
    cout << res;
    
    
    return 0;
}