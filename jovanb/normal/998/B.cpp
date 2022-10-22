#include <bits/stdc++.h>
using namespace std;

int niz[1000];
vector <int> vec;

int main(){
    int n;
    cin >> n;
    int b;
    cin >> b;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    int cnte=0;
    int cnto=0;
    int x=0;
    for(int i=1; i<=n; i++){
        if(niz[i]%2 == 0) cnte++;
        else cnto++;
        if(cnte == cnto){
            if(i != n) vec.push_back(abs(niz[i]-niz[i+1]));
        }
    }
    sort(vec.begin(), vec.end());
    for(auto c : vec){
        if(b >= c){
            b -= c;
            x++;
        }
    }
    cout << x;
    return 0;
}