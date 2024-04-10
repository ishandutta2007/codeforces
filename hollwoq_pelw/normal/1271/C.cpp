#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,sx,sy;
    cin >> n >> sx >> sy;
    int c[4] = {0,0,0,0};// left, right, up, down(from school)
    long x,y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (x < sx) c[0]++; // left
        if (x > sx) c[1]++; // right
        if (y > sy) c[2]++; // up
        if (y < sy) c[3]++; // down
    }
    int s = *max_element(c,c+4);
    if (s == c[0]){cout << s << endl << sx-1 << ' ' << sy; return 0;} // left
    if (s == c[1]){cout << s << endl << sx+1 << ' ' << sy; return 0;} // right
    if (s == c[2]){cout << s << endl << sx << ' ' << sy+1; return 0;} // up
    if (s == c[3]){cout << s << endl << sx << ' ' << sy-1; return 0;} // down
}