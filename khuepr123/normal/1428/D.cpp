#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, m, k, temp1, temp2, temp3;
int a[maxN]; int b[maxN]; bool chk[maxN];

void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}

// featuring: n, m, k

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int val[maxN]; bool locked[maxN];
    if(a[n] > 1){ cout << -1; return 0;}
    m++; m = 0;
    temp1 = 0; temp2 = 0; temp3 = 0;
    for(int i = n; i > 0; i--){
        if(a[i] > 0){
            if(a[i] == 1) temp1++;
            else if(a[i] == 2){ temp1--; temp2++;}
            else if(a[i] == 3){
                if(temp3){
                }
                else if(temp2){
                    temp2--; temp3++;
                }
                else if(temp1){
                    temp1--; temp3++;
                }
            }
            if(temp1 < 0 || temp2 < 0 || temp3 < 0){
                cout << -1; return 0;
            }
        }
    }
    
    // no error
    int l[maxN]; // pair 1 store
    int lf; // pair 2 store
    
    
    int cnt = 0; bool x = 0;
    int lf2; int lastcnt = 0;
    temp1 = 0; temp2 = 0; temp3 = 0;
    for(int i = n - 1; i > 0; i--){
        if(a[i] == 0){ locked[i] = 1; continue;}
        if(a[i] == 1){lastcnt+=1;
            
        } // involved: cnt and l[cnt] and rf
        if(a[i] == 2){
            lastcnt += 1;
        }
        if(a[i] == 3){
            lastcnt += 2;
        }
    }
    
    temp1 = 0;
    if(a[n] == 0){ locked[n] = 1; cout << lastcnt << "\n";}
    else{
        lastcnt++; cout << lastcnt << "\n";
        cout << n << " " << n << "\n"; cnt = 1; l[1] = n;
        x = 1; temp1 = 1;
        lf = n;
        
    }
    
    
    temp2 = 0; temp3 = 0;
    for(int i = n - 1; i > 0; i--){
        if(a[i] == 0){ locked[i] = 1; continue;}
        else if(a[i] == 1){
            cnt++; l[cnt] = i;
            cout << i << " " << i << "\n";
            temp1++;
            
        } // involved: cnt and l[cnt] and rf
        else if(a[i] == 2){
            temp1--; temp2++;
            cout << l[cnt] << " " << i << "\n";
            locked[l[cnt]] = 1;
            cnt--; lf2 = i;
        }
        else if(a[i] == 3){
            if(temp3){
                cout << i << " " << i << "\n";
                cout << i << " " << lf << "\n"; lf = i;
                temp3++;
            }
            else if(temp2){
                temp2--; temp3++;
                cout << i << " " << i << "\n";
                cout << i << " " << lf2 << "\n"; lf = i;
                
            }
            else if(temp1){
                cout << i << " " << i << "\n";
                cout << i << " " << l[cnt] << "\n"; lf = i;
                temp3++;
                cnt--;
            }
        }
    }
    
    
}