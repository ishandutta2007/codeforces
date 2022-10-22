#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mat1[1000][1000];
int mat2[1000][1000];
int mat3[1000][1000];
int mat4[1000][1000];
int n;
int matv[1000][1000];
ll mini = 1000000000;

void probaj(){
    ll treba = 0;
    ll bilo = 0;
    ll b;
    for(int i=1; i<=2*n; i++){
        if(bilo == 0) bilo = 1;
        else bilo = 0;
        b = bilo;
        for(int j=1; j<=2*n; j++){
            if(matv[i][j] != b) treba++;
            b = 1-b;
        }
    }
    mini = min(mini, treba);
    treba = 0;
    bilo = 1;
    for(int i=1; i<=2*n; i++){
        if(bilo == 0) bilo = 1;
        else bilo = 0;
        b = bilo;
        for(int j=1; j<=2*n; j++){
            if(matv[i][j] != b) treba++;
            b = 1-b;
        }
    }
    mini = min(mini, treba);
}

void kombinuj(int mat11[1000][1000], int mat22[1000][1000], int mat33[1000][1000], int mat44[1000][1000]){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            matv[i][j] = mat11[i][j];
            matv[i+n][j] = mat33[i][j];
            matv[i][j+n] = mat22[i][j];
            matv[i+n][j+n] = mat44[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    string str;
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0') mat1[i][j+1] = 0;
            else mat1[i][j+1] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0') mat2[i][j+1] = 0;
            else mat2[i][j+1] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0') mat3[i][j+1] = 0;
            else mat3[i][j+1] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0') mat4[i][j+1] = 0;
            else mat4[i][j+1] = 1;
        }
    }
    kombinuj(mat1, mat2, mat3, mat4);
    probaj();
    kombinuj(mat1, mat2, mat4, mat3);
    probaj();
    kombinuj(mat1, mat3, mat2, mat4);
    probaj();
    kombinuj(mat1, mat3, mat4, mat2);
    probaj();
    kombinuj(mat1, mat4, mat2, mat3);
    probaj();
    kombinuj(mat1, mat4, mat3, mat2);
    probaj();

    kombinuj(mat2, mat1, mat3, mat4);
    probaj();
    kombinuj(mat2, mat1, mat4, mat3);
    probaj();
    kombinuj(mat2, mat3, mat1, mat4);
    probaj();
    kombinuj(mat2, mat3, mat4, mat1);
    probaj();
    kombinuj(mat2, mat4, mat1, mat3);
    probaj();
    kombinuj(mat2, mat4, mat3, mat1);
    probaj();

    kombinuj(mat3, mat2, mat1, mat4);
    probaj();
    kombinuj(mat3, mat2, mat4, mat1);
    probaj();
    kombinuj(mat3, mat1, mat2, mat4);
    probaj();
    kombinuj(mat3, mat1, mat4, mat2);
    probaj();
    kombinuj(mat3, mat4, mat2, mat1);
    probaj();
    kombinuj(mat3, mat4, mat1, mat2);
    probaj();

    kombinuj(mat4, mat2, mat3, mat1);
    probaj();
    kombinuj(mat4, mat2, mat1, mat3);
    probaj();
    kombinuj(mat4, mat3, mat2, mat1);
    probaj();
    kombinuj(mat4, mat3, mat1, mat2);
    probaj();
    kombinuj(mat4, mat1, mat2, mat3);
    probaj();
    kombinuj(mat4, mat1, mat3, mat2);
    probaj();

    cout << mini;
    return 0;
}