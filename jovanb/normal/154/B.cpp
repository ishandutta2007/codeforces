#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int on[100005];
int used[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    while(m--){
        char c;
        int x;
        cin >> c >> x;
        if(c == '+'){
            if(on[x]){cout << "Already on\n"; continue;}
            bool moze=1;
            for(int j=2; j*j<=x; j++){
                if(x%j == 0){
                    if(used[j]){cout << "Conflict with " << used[j] << "\n"; moze = 0; break;}
                    if(used[x/j]){cout << "Conflict with " << used[x/j] << "\n"; moze = 0; break;}
                }
            }
            if(used[x] && x > 1 && moze){cout << "Conflict with " << used[x] << "\n"; moze = 0;}
            if(moze){
                cout << "Success\n";
                on[x] = 1;
                for(int j=2; j*j<=x; j++){
                    if(x%j == 0){
                        used[j] = x;
                        used[x/j] = x;
                    }
                }
                used[x] = x;
            }
        }
        else{
            if(!on[x]){cout << "Already off\n"; continue;}
            cout << "Success\n";
            on[x] = 0;
            for(int i=2; i*i<=x; i++){
                if(x%i == 0){
                    used[i] = 0;
                    used[x/i] = 0;
                }
            }
            used[x] = 0;
        }
    }
    return 0;
}