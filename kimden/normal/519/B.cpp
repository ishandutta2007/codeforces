#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<int, int> mp;
    map<int, int> mp2;
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        mp[a]++;
    }
    for(int i = 0; i < n - 1; i++){
        cin >> a;
        mp[a]--;
        if(mp[a] == 0){
            mp.erase(a);
        }
        mp2[a]++;
    }
    for(int i = 0; i < n - 2; i++){
        cin >> a;
        mp2[a]--;
        if(mp2[a] == 0){
            mp2.erase(a);
        }
    }
    int b, c;
    b = mp.begin()->first;
    c = mp2.begin()->first;
    cout << b << endl << c << endl;
    return 0;
}