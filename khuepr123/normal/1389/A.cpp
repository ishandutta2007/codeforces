#include<bits/stdc++.h>
using namespace std;

int t; long l, r;

int main(){
    cin >> t; for(int o=0; o<t; o++){
        cin >> l >> r; r = r / 2;
        if(r >= l){
            cout << l << " ";
            l = l * 2; cout << l << "\n";
        }
        else{
            cout << "-1 -1" << "\n";
        }
    }
}