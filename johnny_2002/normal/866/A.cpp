#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define X first
#define Y second


const int N=1e5+10;
const double eps=1e-12;
const int inf=2e8+10;


int main(){
    int n;
    cin>>n;
    if (n==1) cout<<"1 1\n1";
    else cout<<2*n-2<<" 2\n1 2";
}