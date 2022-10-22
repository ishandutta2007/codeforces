#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int p[4] = {0, 1, 2, 3};

char maze[55][55];

int main() {
    int r, c, n=0, sr, sc, cr, cc;
    cin >> r >> c;
    string s;
    for(int a=0; a<=r+1; a++) {
        if(a!=0 && a!=r+1) cin >> s;
        for(int b=0; b<=c+1; b++) {
            if(a==0 || b==0 || a==r+1 || b==c+1) maze[a][b]='#';
            else {
                maze[a][b]=s.at(b-1);
                if(s.at(b-1)=='S') {
                    sr = a;
                    sc = b;
                }
            }
        }
    }
    //for(int a=0; a<r+2; a++) {
    //    for(int b=0; b<c+2; b++) {
    //        cout << maze[a][b];
    //    }
    //    cout << '\n';
    //}
    cin >> s;
    do {
        cr = sr;
        cc = sc;
        for(int a=0; a<s.size(); a++) {
           //cout << a;
           cc+=dx[p[(int)s.at(a)-'0']];
           cr+=dy[p[(int)s.at(a)-'0']];
           if(maze[cr][cc]=='#') break;
           else if(maze[cr][cc]=='E') {
                n++;
                //for(int a=0; a<4; a++) {
                //    cout << p[a] << ' ';
                //}
                break;
           }
        }
        //cout << '\n';
    } while(next_permutation(p, p+4));
    cout << n;
}