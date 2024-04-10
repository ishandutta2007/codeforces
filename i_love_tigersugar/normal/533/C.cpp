#include<bits/stdc++.h>
#define MAX   75
using namespace std;
const string win="Polycarp";
const string lose="Vasiliy";
int isWin[75][75][75][75][2];
int winState(int x1,int y1,int x2,int y2,int i) {
    if (isWin[x1][y1][x2][y2][i]>=0) return (isWin[x1][y1][x2][y2][i]);
    int &res=isWin[x1][y1][x2][y2][i];
    if (x1==0 && y1==0) return (res=true);
    if (x2==0 && y2==0) return (res=false);
    if (i==0) {
        if (x1>0 && (x1-1!=x2 || y1!=y2)) {
            if (winState(x1-1,y1,x2,y2,1)) return (res=true);
        }
        if (y1>0 && (x1!=x2 || y1-1!=y2)) {
            if (winState(x1,y1-1,x2,y2,1)) return (res=true);
        }
        return (res=false);
    } else {
        if (x2>0 && (x1!=x2-1 || y1!=y2)) {
            if (!winState(x1,y1,x2-1,y2,0)) return (res=false);
        }
        if (y2>0 && (x1!=x2 || y1!=y2-1)) {
            if (!winState(x1,y1,x2,y2-1,0)) return (res=false);
        }
        if (x2>0 && y2>0 && (x1!=x2-1 || y1!=y2-1)) {
            if (!winState(x1,y1,x2-1,y2-1,0)) return (res=false);
        }
        return (res=true);
    }
}
bool guess(int x1,int y1,int x2,int y2) {
    if (x1<=x2 && y1<=y2) return (true);
    if (x1>=x2 && y1>=y2) return (false);
    if (y1==1 && y2==0 && x2>x1) return (true);
    if (x1==1 && x2==0 && y2>y1) return (true);
    if (x2-x1>y1-1) return (true);
    if (y2-y1>x1-1) return (true);
    return (false);
}
int main(void) {
    memset(isWin,-1,sizeof isWin);
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if (x1<MAX && y1<MAX && x2<MAX && y2<MAX) cout<<(winState(x1,y1,x2,y2,0)?win:lose)<<endl;
    else cout<<(guess(x1,y1,x2,y2)?win:lose);
    return 0;
}