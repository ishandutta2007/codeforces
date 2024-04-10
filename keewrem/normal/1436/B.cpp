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
int k = 769;
int main(){

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i==j)cout << "1 ";
                else if(i == (j+1)%N)cout << k - 4*N+7<<" ";
                else cout << "4 ";
            }
            cout << "\n";
        }

    }
    return 0;
}