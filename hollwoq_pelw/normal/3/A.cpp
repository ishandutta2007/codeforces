#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int a = s1[0]-s2[0];
    int b = s1[1]-s2[1];
    
    string l1="", l2="";
    
    for (int i = 0; i < abs(a); i++){
        if (a < 0) l1+='R';
        if (a > 0) l1+='L';
    }
    for (int i = 0; i < abs(b); i++){
        if (b < 0) l2+='U';
        if (b > 0) l2+='D';
    }
    
    cout << max(abs(a), abs(b)) << endl;
    
    for (int i = 0; i < max(abs(a), abs(b)); i++){
        if (i < abs(a)) cout << l1[i];
        if (i < abs(b)) cout << l2[i];
        cout << endl;
    }
}