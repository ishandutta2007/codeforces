#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, m, k, temp, temp1, temp2;
int a[maxN]; int b[maxN]; bool chk[maxN];

void typre(){ // typical reset
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        
        int cnt = 0; int sum = 0;
        string s; cin >> s;n = s.length(); int cursor = s.length();
        typre();
        for(int i = s.length() - 1; i > -1; i--){
            if(s[i] == 66){
                cursor = i; break;
            }
        }
        if(cursor == s.length()){
            cout << s.length() << endl; continue;
        }
        cursor++; int bomb; int A = 0; int B = 0; B++;
        for(int i = 1; i < n; i++){
            if((s[i] == 66 && A == B) || s[i] == 65){
                B++;
            }
            else{
                A++;
            }
        }
        cout << n - 2 * A << endl;
    }
}