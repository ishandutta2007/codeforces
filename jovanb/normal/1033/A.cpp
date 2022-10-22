#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int blocked[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int i1, j1;
    cin >> i1 >> j1;
    int i2, j2;
    int i3, j3;
    cin >> i2 >> j2;
    cin >> i3 >> j3;
    int s2, s3;
    if(i1 > i2){
        if(j1 < j2){
            if(i1-i2 < j2-j1) s2 = 1;
            else s2 = 2;
        }
        else{
            if(i1-i2 < j1-j2) s2 = 3;
            else s2 = 4;
        }
    }
    else{
        if(j1 < j2){
            if(i2-i1 < j2-j1) s2 = 5;
            else s2 = 6;
        }
        else{
            if(i2-i1 < j1-j2) s2 = 7;
            else s2 = 8;
        }
    }
    if(i1 > i3){
        if(j1 < j3){
            if(i1-i3 < j3-j1) s3 = 1;
            else s3 = 2;
        }
        else{
            if(i1-i3 < j1-j3) s3 = 3;
            else s3 = 4;
        }
    }
    else{
        if(j1 < j3){
            if(i3-i1 < j3-j1) s3 = 5;
            else s3 = 6;
        }
        else{
            if(i3-i1 < j1-j3) s3 = 7;
            else s3 = 8;
        }
    }
    if(s2 == s3 || (s2 == 1 && s3 == 2) || (s2 == 2 && s3 == 1) || (s2 == 3 && s3 == 4) || (s2 == 4 && s3 == 3) || (s2 == 5 && s3 == 6) || (s2 == 6 && s3 == 5) || (s2 == 7 && s3 == 8) || (s2 == 8 && s3 == 7)) cout << "YES";
    else cout << "NO";
    return 0;
}