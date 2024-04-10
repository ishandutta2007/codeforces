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
int N,a;
int p[200010];
int pp[200010];
int cnt[200010];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a; p[a] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> a;
        if(p[a]<=i)cnt[i-p[a]]++;
        else cnt[N-p[a]+i]++;
    }
    int m = 0;
    for(int i = 0; i < 200010; i++)m = max(m,cnt[i]);
    cout << m << "\n";
    return 0;
}