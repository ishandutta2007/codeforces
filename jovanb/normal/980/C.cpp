#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fun[1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    for(int i=0; i<=255; i++) fun[i] = -1;
    int n, k;
    cin >> n >> k;
    int br=0;
    for(int i=1; i<=n; i++){
        cin >> br;
        if(fun[br] != -1){cout << fun[br] << " "; continue;}
        int x = br;
        int lim = max(0, br-k+1);
        while(1){
            if(x < lim){x++; break;}
            if(fun[x] != -1){
                if((br-fun[x]+1)<=k) break;
                else x++;
                break;
            }
            x--;
        }
        if(fun[x] == -1) fun[x] = x;
        for(int j=x; j<=br; j++) fun[j] = fun[x];
        cout << fun[br] << " ";
    }
    return 0;
}