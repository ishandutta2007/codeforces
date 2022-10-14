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
int pos[100010];
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int sas[N+1]; sas[N] = 0;
        for(int i = 0; i < N; i++){
            scanf("%d",&sas[i]);
            pos[sas[i]] = i;
        }
        bool k = 0;
        for(int i = 2; i <= N; i++){
            if(!(pos[i]==pos[i-1]+1||sas[pos[i-1]+1]<i)){
                k = 1;
            }
        }
        if(k)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}