#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int M,N,K,T,k,res;
string bb;
bitset<3001> sos;
vector<int> m[3000];
int main(){
    cin >> N >> K;
    cin >> bb;
    for(int i = 0; i < N; i++){
        sos[i]=(bb[i]=='R');
    }
    bool kk = 1;
    int lel = 0;
    while(kk){
        kk = 0;
        for(int i = 0; i < N-1; i++){
            if(sos[i]&& (!sos[i+1])){
                sos[i]=0; sos[++i]=1;
                kk = 1; res++;
                m[lel].push_back(i);
            }
        }
        if(kk)lel++;
    }
    vector<int> kwk;
    //cout << "lelres "<< lel << " "<<res <<"\n";
    if(lel>K||res<K){cout<<-1; return 0;}
    for(int i = 0; i < lel ; i++){
        for(auto x: m[i]){
            kwk.push_back(x);
            if(--K>lel-i-1){
                cout << "1 "<< kwk[0]<<"\n";
                kwk.clear();
            }
        }
        if(!kwk.empty()){
            cout << kwk.size();
            for(auto x: kwk){
                cout << " "<<x;
            }
            kwk.clear();
            cout << "\n";
        }
    }
}