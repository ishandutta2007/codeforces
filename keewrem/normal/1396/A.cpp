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

ll N;
int main(){
    cin >> N;
    vll v(N);
    for(auto &x: v)cin >> x;
    cout << 1 <<" " << N<< "\n";
    for(auto &x: v){
        if(N<3){cout << "0\n"; continue;}
        cout << (x%(N-1))*(-N)<<" ";
        x-=(x%(N-1))*N;
    }
    cout << "\n";
    if(N > 2){
        cout << 1 << " "<<N-1<<"\n";
        for(int i = 0; i < N-1; i++){cout << -v[i]<<" "; v[i]=0;}
        cout << "\n";
    }else{
        cout << "1 1\n"<<-v[0]<<"\n"; v[0]=0;
    }
    cout << N << " "<<N<<"\n"<<-v[N-1]<<"\n";
    return 0;
}