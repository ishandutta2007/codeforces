#include <bits/stdc++.h>

using namespace std;

long long int choose[101][101];

int main() {
    for(int a=0; a<50; a++) {
        for(int b=0; b<=a; b++) {
            if(!b) choose[a][b]=1;
            else choose[a][b]=choose[a-1][b-1]+choose[a-1][b];
        }
    }
    long long int b, g, c, ans=0;
    cin >> b >> g >> c;
    b-=4;
    g--;
    c-=5;
    for(long long int x=max((long long int)(0), c-g); x<=min(c, b); x++) {
        ans+=((choose[b+4][x+4])*(choose[g+1][c-x+1]));
    }
    cout << ans << '\n';
}