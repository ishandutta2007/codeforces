#include <bits/stdc++.h>
using namespace std;

char ch[1000005];
int moza[1000005];
int mozb[1000005];
long long ost[1000005];
long long niz[1000005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> ch;
    long long a, b, i, j, osta=0, ostb=0;
    cin >> a >> b;
    ost[0] = 1%b;
    for(i=1; i<=1000000; i++)ost[i] = (ost[i-1]*10)%b;
    long long n = strlen(ch);
    for(i=0; i<n; i++)niz[i] = ch[i]-'0';
    for(i=0; i<n-1; i++){
        osta = (osta*10+niz[i])%a;
        osta %= a;
        if(osta == 0)moza[i]++;
    }
    for(i=n-1; i>=1; i--){
        ostb = (ostb+niz[i]*ost[n-i-1])%b;
        ostb %= b;
        if(ostb == 0 && niz[i] != 0)mozb[i]++;
    }
    for(i=0; i<n-1; i++){
        if(moza[i] == 1 && mozb[i+1] == 1){
            cout << "YES\n";
            for(j=0; j<n; j++){
                cout << niz[j];
                if(j==i)cout << endl;
            }
            return 0;
        }
    }
    cout << "NO";
    return 0;
}