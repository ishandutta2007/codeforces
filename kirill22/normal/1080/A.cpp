#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long INF = 1e16;
int gcd(int a,int b){

    if (a<b){
        swap(a,b);
    }
    if (b==0){
        return a;
    }

    return gcd(b,a%b);

}

int main() {
    int n,k,x,y,z,co=0,ans=0,ii=0,uu=0;
    char c;
    string s;
    cin >> n >> k;
    ans+=(n*2+k-1)/k;
    ans+=(n*5+k-1)/k;
    ans+=(n*8+k-1)/k;
    cout << ans;
}