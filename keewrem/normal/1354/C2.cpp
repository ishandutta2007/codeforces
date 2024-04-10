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
const long double PI = 3.141592653589793;
int T;
ll N;


int main(){
    cin >> T;
    while(T--){
        cin >> N;
        cout << fixed << setprecision(15);
        if(N == 2){cout << "1.0\n"; continue;}
        long double n = 2*N;
        long double r = (long double)1.0/sinl(PI/n);
        long double a = r*cosl(PI/n);
        long double best = r;//cout << r;
        for(long double i = 0; i <= n; i+=1.0){
            long double ang = i*PI/(n*n);
            best = min(best,max(abs(r*cosl(ang)),abs(r*cosl((PI/n)-ang))));
        }
        cout << best<<"\n";
    }
    return 0;
}