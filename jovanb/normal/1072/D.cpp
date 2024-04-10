#include <bits/stdc++.h>
using namespace std;

bool moze[2005][2005];
int mink[2005][2005];
char mat[2005][2005];

int main(){

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=n; j++) mat[i][j] = s[j-1];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            mink[i][j] = 5000000;
        }
    }
    string res = "";
    moze[1][0] = 1;
    moze[0][1] = 1;
    mink[0][1] = 0;
    mink[1][0] = 0;
    for(int i1=1; i1<=n; i1++){
        char minc = 'z';
        int i=i1, j=1;
        while(i>=1 && j<=n){
            if(moze[i-1][j] || moze[i][j-1]) minc = min(minc, mat[i][j]);
            if(moze[i-1][j] && mink[i-1][j] < k) minc = 'a';
            if(moze[i][j-1] && mink[i][j-1] < k) minc = 'a';
            i--;
            j++;
        }
        res += minc;
        i=i1, j=1;
        while(i>=1 && j<=n){
            char c = mat[i][j];
            if(moze[i-1][j] && mink[i-1][j] < k) c = 'a';
            if(moze[i][j-1] && mink[i][j-1] < k) c = 'a';
            if(c == minc && (moze[i-1][j] || moze[i][j-1])){
                moze[i][j] = 1;
                if(mat[i][j] == minc){
                    if(moze[i-1][j]) mink[i][j] = min(mink[i-1][j], mink[i][j]);
                    if(moze[i][j-1]) mink[i][j] = min(mink[i][j-1], mink[i][j]);
                }
                else{
                    if(moze[i-1][j]) mink[i][j] = min(mink[i-1][j]+1, mink[i][j]);
                    if(moze[i][j-1]) mink[i][j] = min(mink[i][j-1]+1, mink[i][j]);
                }
            }
            i--;
            j++;
        }
    }
    for(int i1=2; i1<=n; i1++){
        char minc = 'z';
        int i=n, j=i1;
        while(i>=1 && j<=n){
            if(moze[i-1][j] || moze[i][j-1]) minc = min(minc, mat[i][j]);
            if(moze[i-1][j] && mink[i-1][j] < k) minc = 'a';
            if(moze[i][j-1] && mink[i][j-1] < k) minc = 'a';
            i--;
            j++;
        }
        res += minc;
        i=n, j=i1;
        while(i>=1 && j<=n){
            char c = mat[i][j];
            if(moze[i-1][j] && mink[i-1][j] < k) c = 'a';
            if(moze[i][j-1] && mink[i][j-1] < k) c = 'a';
            if(c == minc && (moze[i-1][j] || moze[i][j-1])){
                moze[i][j] = 1;
                if(mat[i][j] == minc){
                    if(moze[i-1][j]) mink[i][j] = min(mink[i-1][j], mink[i][j]);
                    if(moze[i][j-1]) mink[i][j] = min(mink[i][j-1], mink[i][j]);
                }
                else{
                    if(moze[i-1][j]) mink[i][j] = min(mink[i-1][j]+1, mink[i][j]);
                    if(moze[i][j-1]) mink[i][j] = min(mink[i][j-1]+1, mink[i][j]);
                }
            }
            i--;
            j++;
        }
    }
    cout << res;
    return 0;
}