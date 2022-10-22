#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int ima[200005][2];

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    for(int i=1; i<=l; i++){
        int x;
        cin >> x;
        ima[x][0]++;
    }
    for(int i=1; i<=r; i++){
        int x;
        cin >> x;
        if(ima[x][0]) ima[x][0]--;
        else ima[x][1]++;
    }
    int res = 0;
    int leve = 0, desne = 0;
    for(int x=1; x<=n; x++){
        leve += ima[x][0];
        desne += ima[x][1];
        /*if(ima[x][0]){
            res += ima[x][0]/2;
            ima[x][0] %= 2;
            if(ima[x][0]) leve++;
            ima[x][0] = 0;
        }
        if(ima[x][1]){
            //res += ima[x][1]/2;
            //ima[x][1] %= 2;
            //if(ima[x][1]) desne++;
            //ima[x][1] = 0;
        }*/
    }
    //cout << leve << " b " << desne << endl;
    for(int x=1; x<=n; x++){
        while(desne > leve && ima[x][1] >= 2){
            desne -= 2;
            ima[x][1] -= 2;
            res++;
        }
        while(leve > desne && ima[x][0] >= 2){
            leve -= 2;
            ima[x][0] -= 2;
            res++;
        }
        ima[x][0] = ima[x][1] = 0;
        //cout << leve << " a " << desne << endl;
    }
    //cout << leve << " " << desne << endl;
    cout << res + (leve+desne)/2 + (abs(desne-leve))/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
	cout.precision(10);
	cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}