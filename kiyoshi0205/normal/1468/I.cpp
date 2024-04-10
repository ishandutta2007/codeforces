#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
vector<ll> sousa;
bool f1,f2;
pair<ll,ll> solve(ll a,ll b){
    for(auto x:sousa){
        if(x==0){
            swap(a,b);
        }else{
            b+=a*x;
        }
    }
    if(f1)a=-a;
    if(f2)b=-b;
    return make_pair(a,b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    if(A*D==B*C){
        cout<<"NO\n";
        return 0;
    }
    if(f1=(A<0)){
        A=-A;C=-C;
    }
    if(f2=(B<0)){
        B=-B;D=-D;
    }
    if(A==0){
        sousa.emplace_back(0);
        swap(A,B);
        swap(C,D);
    }
    if(B!=0){
        while(B!=0){
            if(A>B){
                sousa.emplace_back(0);
                swap(A, B);
                swap(C, D);
                continue;
            }
            sousa.emplace_back(B/A);
            B-=A*sousa.back();
            D-=C*sousa.back();
        }
        reverse(sousa.begin(),sousa.end());
    }
    D=abs(D);
    if(A*D!=N){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES"<<endl;
    rep(i,A)rep(j,D){
        --N;
        auto x=solve(i,j);
        cout<<x.first<<" "<<x.second<<endl;
        if(N==0)return 0;
    }
}