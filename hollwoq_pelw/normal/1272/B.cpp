#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    cin >> t;
    while(t){
        t--;
        cin >> s;
        int l=0,r=0,d=0,u=0;
        
        for (char c:s){
            if(c=='L')l++;
            if(c=='R')r++;
            if(c=='U')u++;
            if(c=='D')d++;
        }
        
        if (l > r) l = r;
        else r = l;
        if (u > d) u = d;
        else d = u;
        
        if (d == 0 && r > 0){
            cout << 2 << endl << "LR" << endl;
        }
        else if (d > 0 && r == 0){
            cout << 2 << endl << "UD" << endl;
        }
        else {
            cout << l+r+d+u << endl;
            while(l) {cout << "L"; l--;}
            while(d) {cout << "D"; d--;}
            while(r) {cout << "R"; r--;}
            while(u) {cout << "U"; u--;}
            cout << endl;
        }
    }
    return 0;
}