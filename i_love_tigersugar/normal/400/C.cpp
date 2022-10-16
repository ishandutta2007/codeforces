#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
struct shape {
    int m,n,x,y;
    shape() {
        m=0;n=0;x=0;y=0;
    }
    void input(int m,int n) {
        this->m=m;
        this->n=n;
        scanf("%d%d",&x,&y);
    }
    shape rotate(void) const {
        shape res;
        res.m=n;
        res.n=m;
        res.x=y;
        res.y=m-x+1;
        return (res);
    }
    shape flip(void) const {
        shape res;
        res.m=m;
        res.n=n;
        res.x=x;
        res.y=n-y+1;
        return (res);
    }
};
void process(void) {
    int m,n,x,y,z,p;
    scanf("%d%d%d%d%d%d",&m,&n,&x,&y,&z,&p);
    REP(zz,p) {
        shape t;
        t.input(m,n);
        REP(i,x%4) t=t.rotate();
        REP(i,y%2) t=t.flip();
        REP(i,z%4*3) t=t.rotate();
        printf("%d %d\n",t.x,t.y);
    }
}
int main(void) {
    process();
    return 0;
}