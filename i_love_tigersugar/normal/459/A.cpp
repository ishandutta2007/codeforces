#include<bits/stdc++.h>
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    Point(int _x,int _y) {
        x=_x;y=_y;
    }
    void input(void) {
        scanf("%d%d",&x,&y);
    }
};
inline int Abs(int x) {
    return (x<0?-x:x);
}
int main(void) {
    Point a,b,c,d;
    a.input();
    b.input();
    if (a.x==b.x) {
        int t=Abs(a.y-b.y);
        c=Point(a.x+t,a.y);
        d=Point(b.x+t,b.y);
        printf("%d %d %d %d",c.x,c.y,d.x,d.y);
    }
    else if (a.y==b.y) {
        int t=Abs(a.x-b.x);
        c=Point(a.x,a.y+t);
        d=Point(b.x,b.y+t);
        printf("%d %d %d %d",c.x,c.y,d.x,d.y);
    }
    else {
        if (Abs(a.x-b.x)!=Abs(a.y-b.y)) {
            printf("-1");
            return 0;
        }
        c=Point(a.x,b.y);
        d=Point(b.x,a.y);
        printf("%d %d %d %d",c.x,c.y,d.x,d.y);
    }
    return 0;
}