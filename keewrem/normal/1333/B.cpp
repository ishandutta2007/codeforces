#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M,N,K,T,k,res;
vector<ll> a,b;
int main(){
    cin >> T;
    while(T--){
        a.clear(); b.clear();
        res = 0;
        cin >> N;
        int piu =1000000, meno = 1000000;
        for(int i = 0; i < N; i++){
            cin >> k;
            if(k > 0 && piu == 1000000)piu = i;
            if(k < 0 && meno == 1000000)meno = i;
            a.push_back(k);
        }
        for(int i = 0; i < N; i++){
            cin >> k;
            b.push_back(k);
        }
        //cout << "pm "<< piu << " "<<meno<<"\n";
        bool ses = 0;
        for(int i = N-1; i>=0; i--){
            if(a[i]==b[i])continue;
            if(a[i]<b[i]){
                if(piu >= i){
                    ses = 1;
                    cout <<"NO\n";
                    break;
                }
            }
            if(a[i]>b[i]){
                if(meno >= i){
                    ses = 1;
                    cout <<"NO\n";
                    break;
                }
            }
        }
        if(!ses)cout << "YES\n";
    }
    return 0;
}