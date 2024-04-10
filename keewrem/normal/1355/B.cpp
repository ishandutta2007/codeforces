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

int v[300010];
int T,a;
ll N;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i <= N; i++)v[i] = 0;
        for(int i = 0; i <N; i++){cin >> a; v[a]++;}
        int r = 0;
        for(int i = 1; i <= N; i++){r+=v[i]/i; v[i+1] += v[i]%i;}
        cout << r <<"\n";
    }
    return 0;
}