#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
//Square corners order: (x,y) (x+t,y) (x,y+t) (x+t,y+t)
const int INF=(int)1e9+7;
typedef pair<int,int> Point;
const Point dir[]={Point(0,1),Point(1,0),Point(0,-1),Point(-1,0)};
int canMove(const Point &sta,const Point &dir,const Point &fin) {
    if (dir.fi==0 && sta.fi!=fin.fi) return (INF);
    if (dir.se==0 && sta.se!=fin.se) return (INF);
    if (dir.fi!=0) return ((fin.fi-sta.fi)*dir.fi<0?INF:(fin.fi-sta.fi)/dir.fi);
    if (dir.se!=0) return ((fin.se-sta.se)*dir.se<0?INF:(fin.se-sta.se)/dir.se);
    assert(false);
}
int intersect(int x,const vector<int> &pos,const vector<int> &sign) {
    vector<pair<int,int> > range;
    REP(i,4) range.push_back(make_pair(pos[i],pos[i]+x*sign[i]));
    REP(i,4) if (range[i].fi>range[i].se) swap(range[i].fi,range[i].se);
    int L=range[0].fi;
    int R=range[0].se;
    FORE(it,range) {
        maximize(L,it->fi);
        minimize(R,it->se);
    }
    return (L>R?INF:R);
}
int unfixCase(const vector<int> &pos,const vector<int> &sign) {
    int L=0;
    int R=INF;
    while (true) {
        if (L==R) return (L);
        if (R-L==1) return (intersect(L,pos,sign)<INF?L:R);
        int M=(L+R)>>1;
        if (intersect(M,pos,sign)<INF) R=M; else L=M+1;
    }
}
pair<int,vector<Point> > solve(const vector<Point> &point,const vector<Point> &dir,const vector<int> &order) {
    int x=INF,y=INF,t=INF,xt=INF,yt=INF;
    REP(i,4) if (order[i]%2==0 && dir[i].fi==0) x=point[i].fi;
    REP(i,4) if (order[i]<2 && dir[i].se==0) y=point[i].se;
    REP(i,4) if (order[i]%2!=0 && dir[i].fi==0) xt=point[i].fi;
    REP(i,4) if (order[i]>=2 && dir[i].se==0) yt=point[i].se;
    if (x<INF && xt<INF) t=xt-x;
    if (y<INF && yt<INF) t=yt-y;
    if (t<INF && xt<INF) x=xt-t;
    if (t<INF && yt<INF) y=yt-t;
    assert(x<INF || y<INF);
    assert(t<INF);
    if (x<INF && y<INF) {
        vector<Point> fin;
        REP(i,4) {
            if (order[i]==0) fin.push_back(Point(x,y));
            if (order[i]==1) fin.push_back(Point(x+t,y));
            if (order[i]==2) fin.push_back(Point(x,y+t));
            if (order[i]==3) fin.push_back(Point(x+t,y+t));
        }
        int res=0;
        REP(i,4) maximize(res,canMove(point[i],dir[i],fin[i]));
        return (make_pair(res,fin));
    }
    vector<int> pos,sign;
    REP(i,4) sign.push_back(x>=INF?dir[i].fi:dir[i].se);
    REP(i,4) {
        if (x>=INF) pos.push_back(order[i]%2==0?point[i].fi:point[i].fi-t);
        else pos.push_back(order[i]<2?point[i].se:point[i].se-t);
    }
    int res=unfixCase(pos,sign);
//    printf("DATA: %d %d %d\n",x,y,t);
//    REP(i,4) printf("From %d %d via %d %d as %d\n",point[i].fi,point[i].se,
//                        dir[i].fi,dir[i].se,order[i]);
//    if (res>=INF) return (make_pair(INF,vector<Point>()));
    int val=intersect(res,pos,sign);
    vector<Point> fin;
    REP(i,4) {
        if (x>=INF) fin.push_back(order[i]%2==0?Point(val,point[i].se):Point(val+t,point[i].se));
        else fin.push_back(order[i]<2?Point(point[i].fi,val):Point(point[i].fi,val+t));
    }
    return (make_pair(res,fin));
}
bool checkSolution(const vector<Point> &sta,const vector<Point> &dir,const vector<Point> &fin,
    const vector<int> &order,int time) {
    if (time>=INF) return (false);
    REP(i,4) if (canMove(sta[i],dir[i],fin[i])>time) return (false);
    int x,y,t;
    REP(i,4) if (order[i]==0) {
        x=fin[i].fi;
        y=fin[i].se;
    }
    REP(i,4) if (order[i]==1) t=fin[i].fi-x;
    if (t==0) return (false);
    REP(i,4) {
        if (order[i]==0 && (fin[i].fi!=x || fin[i].se!=y)) return (false);
        if (order[i]==1 && (fin[i].fi!=x+t || fin[i].se!=y)) return (false);
        if (order[i]==2 && (fin[i].fi!=x || fin[i].se!=y+t)) return (false);
        if (order[i]==3 && (fin[i].fi!=x+t || fin[i].se!=y+t)) return (false);
    }
    return (true);
}
void process(void) {
    vector<Point> point;
    REP(i,4) {
        int x,y; scanf("%d%d",&x,&y);
        point.push_back(make_pair(x,y));
    }
    vector<int> order;
    REP(i,4) order.push_back(i);
    pair<int,vector<Point> > best(INF,vector<Point>());
    do {
        REP(i,4) REP(j,4) REP(k,4) REP(l,4) {
            vector<Point> curDir;
            curDir.push_back(dir[i]);
            curDir.push_back(dir[j]);
            curDir.push_back(dir[k]);
            curDir.push_back(dir[l]);
            pair<int,vector<Point> > sol=solve(point,curDir,order);
            if (checkSolution(point,curDir,sol.se,order,sol.fi)) {
//                printf("FIND SOLUTION with %d\n",sol.fi);
//                REP(i,4) printf("FROM %d %d via %d %d to %d %d\n",point[i].fi,point[i].se,
//                    curDir[i].fi,curDir[i].se,sol.se[i].fi,sol.se[i].se);
                minimize(best,sol);
            }
        }
    } while (next_permutation(ALL(order)));
    if (best.fi>=INF) printf("-1\n");
    else {
        printf("%d\n",best.fi);
        FORE(it,best.se) printf("%d %d\n",it->fi,it->se);
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    int t; scanf("%d",&t);
    REP(love,t) process();
    return 0;
}