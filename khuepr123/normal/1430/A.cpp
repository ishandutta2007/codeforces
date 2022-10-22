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
int n; int cnt3, cnt5, cnt7;



int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; int temp = n;
        if(n == 3){cout << "1 0 0" << "\n"; continue;}
        if(n == 6){cout << "2 0 0" << "\n"; continue;}
        
        if(n == 5){cout << "0 1 0" << "\n"; continue;}
        
        if(n < 7){cout << "-1\n"; continue;}
        if(n == 7){cout << "0 0 1" << "\n"; continue;}
        for(int j = 0; j <= 1000; j++){
            if(temp % 3 == 0){
                cnt5 = (n - temp) / 5; cnt3 = temp / 3; cout << cnt3 << " " << cnt5 << " 0\n"; break;
            }
            else{
                temp-=5;
            }
        }
    }
}