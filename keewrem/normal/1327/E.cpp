#define fi first
#define se second
#define MOD 998244353
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll T,N;
ll p10[200010];

int main(){
    cin >> N;
    p10[0]=1;
    ll res = 0;
    for(int i = 1; i<=N;i++)p10[i]=(p10[i-1]*10)%MOD;
    for(int i = 1; i <= N; i++){
        res = 0;
        if(i < N-1)res=(((N-i-1)*10*81)%MOD)*p10[N-i-2];
        if(i < N)res+=10*18*p10[N-i-1];
        if(i == N)res = 10LL;
        res%=MOD;
        cout << res << " ";
    }
    return 0;
}