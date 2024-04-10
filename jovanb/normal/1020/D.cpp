#include <bits/stdc++.h>
using namespace std;

int n;

int ask(int a){
    cout << "? " << a << endl;
    int x;
    cin >> x;
    return x;
}

int f(int a){
    int drugi = a+n/2;
    if(drugi > n) drugi -= n;
    return ask(a)-ask(drugi);
    cout << "aaa";
}

int main(){

    cin >> n;
    if(n%4){cout << "! -1" << endl; return 0;}
    int l=1, r=n;
    while(l <= r){
        int a = (l+r)/2;
        int x = f(a);
        if(!x){cout << "! " << a << endl; return 0;}
        int p = f(l);
        //cerr << l << " " << r << endl << endl;
        if(x > 0){
            if(p < 0) r = a-1;
            else l = a+1;
        }
        else{
            if(p > 0) r = a-1;
            else l = a+1;
        }
    }
    cout << "! -1" << endl;
    return 0;
}