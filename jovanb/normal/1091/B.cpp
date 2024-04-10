#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

map <pair <int, int>, bool> ima;

int x[100005];
int y[100005];
int cx[100005];
int cy[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++){
        cin >> cx[i] >> cy[i];
        ima[{cx[i], cy[i]}] = 1;
    }
    if(n == 1){
        cout << x[1]+cx[1] << " " << y[1]+cy[1];
        return 0;
    }
    for(int i=1; i<=n; i++){
        int xx = x[1]+cx[i];
        int yy = y[1]+cy[i];
        for(int j=2; j<=n; j++){
            if(!ima[{xx-x[j], yy-y[j]}]) break;
            if(j == n){cout << xx << " " << yy; return 0;}
        }
    }
    return 0;
}