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
int pr[200010];
int ses[200010];
int cnt[200010];
int sus[200010];
int kek[200010];
int main(){
    pr[0]=1; pr[1]=1;
    for(int i = 0; i < 200010; i++){
        if(pr[i] == 0){
            for(int j = i; j<200010; j+=i){
                pr[j] = i;
            }
        }
        sus[i] = 10000; ses[i] = 10000;
    }
    cin >> N;
    vi sos(N); set<int> s; int k,c;
    for(int i = 0; i < N; i++)cin >> sos[i];
    for(int i = 0; i < N; i++){
        k = sos[i];
        while(k>1){
            kek[pr[k]]++;
            s.insert(pr[k]); k/=pr[k];
        }
        for(auto x: s)cnt[x]++;
        for(auto x: s){
            c = kek[x];
            if(c < ses[x]){
                sus[x] = ses[x];
                ses[x] = c;
            }else if(c < sus[x]){
                sus [x] =  c;
            }
            kek[x] = 0;
        }
        s.clear();
    }
    ll r = 1;
    for(int i = 2; i < 200010; i++){
        if(cnt[i] < N - 1)continue;
        if(cnt[i] == N)while(sus[i]--)r*=(ll)i;
        else while(ses[i]--)r*=(ll)i;
    }
    cout << r<<"\n";
    return 0;
}