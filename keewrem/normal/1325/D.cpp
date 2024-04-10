#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
int N,t;
ll x,s;
ll k;
ll act_xor,act_sum;
using namespace std;
int main(){
    cin >> x >> s;
    ll a=0,b=0,c=0;
    if(x > s || s%2!=x%2){
        cout << "-1\n";
        return 0;
    }

    if(x==s){
        if(x==0)cout << "0";
        else cout << "1\n"<< x;
        return 0;
    }
    if(((s-x)/2 & x)==0){
        cout<<"2\n" << x+(s-x)/2<<" "<<(s-x)/2;
        return 0;
    }
    else{
        cout << "3\n";
        cout << x << " "<<(s-x)/2<<" "<<(s-x)/2;
    }
    return 0;
}