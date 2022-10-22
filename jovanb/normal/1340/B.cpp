#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000000;

string cifra[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int treba(string &a, int x){
    int cnt = 0;
    for(int i=0; i<7; i++){
        if(a[i] == '1' && cifra[x][i] == '0') return INF;
        cnt += cifra[x][i] - a[i];
    }
    return cnt;
}

string s[2005];
int moze[2005][2005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    moze[n+1][0] = 1;
    for(int i=n; i>=1; i--){
        for(int l=0; l<=9; l++){
            int g = treba(s[i], l);
            for(int j=0; j<=k; j++){
                if(j < g) continue;
                moze[i][j] |= moze[i+1][j-g];
            }
        }
    }
    if(!moze[1][k]){
        cout << -1;
        return 0;
    }
    int tren = k;
    for(int i=1; i<=n; i++){
        for(int l=9; l>=0; l--){
            int g = treba(s[i], l);
            if(tren < g) continue;
            //cout << i << " " << l << " " << g << endl;
            if(moze[i+1][tren-g]){
                cout << l;
                tren -= g;
                break;
            }
        }
    }
    return 0;
}