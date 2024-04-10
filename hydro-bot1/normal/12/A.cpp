// Hydro submission #61fbeed1b3638e8f4bedc500@1643900626077
#include<bits/stdc++.h>
using namespace std;
char mat[10][10];
int main(){
    for(int i=1;i<=3;i++){
        cin >> (mat[i]+1);
    }
    /*
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            putchar(mat[i][j]);
        }
        putchar('\n');
    }*/
    bool ans=true;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(mat[i][j]!=mat[4-i][4-j])
                ans=false;
    cout << (ans?"YES":"NO");
    return 0;
}