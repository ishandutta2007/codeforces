#include <bits/stdc++.h>
using namespace std;
long long niz[200000];
map <long long, long long> mapa;
int main(){
    long long b1,q,l,m;
    cin >> b1 >> q >> l >> m;
    for(long i = 0; i < m; i++){
        cin >> niz[i];
        mapa[niz[i]] = 1;
    }
    if(abs(b1)>l){cout<<0;return 0;}
    if(q == 0){
        if(mapa[b1] == 1){
            if(mapa[0] == 1){
                cout << 0 << endl;
            }
            else{
                cout << "inf" << endl;
            }

        }
        else{
            if(mapa[0] == 1){
                cout << 1 << endl;
            }
            else cout << "inf" << endl;
        }
        return 0;
    }
    if(q == 1){
        if(mapa[b1] == 1){
            cout<< 0 << endl;
        }
        else cout<<"inf";
        return 0;
    }
    if(q==-1){
        if(mapa[b1]==0 || mapa[-b1]==0){cout<<"inf";return 0;}
        else cout<<0;
        return 0;
    }
    if(b1==0){
        if(mapa[0]==0){cout<<"inf";}
        else cout<<0;
        return 0;
    }
    long long b = b1;
    long long br = 0;
    for(int voja=0; voja<100000; voja++){
        if(abs(b) > l){
           cout << br << endl;
           return 0;
        }
        if(mapa[b] != 1){
           br++;
        }
        b *= q;
    }
    cout<<br;
    return 0;
}