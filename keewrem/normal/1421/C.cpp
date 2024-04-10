#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;

int main(){
    string s;
    cin >> s;
    N=s.size();

    cout << "4\n";
    cout << "L 2\nL 2\n";
    N+=2;
    cout << "R 2\n";
    N+=N-2;
    cout << "R "<<N-1;
    return 0;
}