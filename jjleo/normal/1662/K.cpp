#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
#define pi acos(-1.0L)
#define pb push_back
#define eps 1e-9
int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
double cmp(double a,double b){return sgn(a-b);}
double sqr(double x){return x*x;}
double inmid(double x,double l,double r){return sgn(x-l)>=0&&sgn(r-x)>=0;}
struct Point{
    double x,y;
    Point(){}
    Point(double xx,double yy){x=xx;y=yy;}
    void input(){scanf("%Lf %Lf",&x,&y);}
    void output(){printf("%.5Lf %.5Lf\n",x,y);}
    bool operator ==(const Point &p)const{return sgn(x-p.x)==0&&sgn(y-p.y)==0;}
    bool operator !=(const Point &p)const{return sgn(x-p.x)!=0||sgn(y-p.y)!=0;}
    bool operator < (const Point &p)const{
        return sgn(x-p.x)<0||(sgn(x-p.x)==0&&sgn(y-p.y)<0);
    }
    Point operator + (const Point &p)const{
        return {x+p.x,y+p.y};
    }
    Point operator - (const Point &p)const{
        return {x-p.x,y-p.y};
    }
    Point operator * (double k)const{
        return {x*k,y*k};
    }
    Point operator / (const double &k)const{
        //assert(k!=0);
        return {x/k,y/k};
    }
    double dot(Point p) const{return p.x*x+p.y*y;}
    double cross(Point p) const {return x * p.y - y * p.x;}
    double dis(Point p) const {return sqrt(sqr(x - p.x) + sqr(y - p.y));}
    double abs() const{return sqrt(sqr(x)+sqr(y));}
    double abs2() const{return sqr(x)+sqr(y);}
    Point rot(Point p,double a){
        //
        Point v = (*this) - p;
        double c = cos(a), s = sin(a);
        return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
    }
    Point rotLeft() const{return Point(-y,x);}
    Point rotRight() const{return Point(y,-x);}
    double getW() const{return atan2l(y,x);}
    Point unit()const{
        if(sgn(abs())==0)return (*this);
        else return {x/abs(),y/abs()};
    }
    Point trunc(double r)const{Point tmp=unit();return tmp*r;}
    double rad(Point a,Point b)const{
        Point k1=a-(*this),k2=b-(*this);
        return atan2l(k1.cross(k2), k1.dot(k2));
    }
};
double cross(Point p1,Point p2,Point p3){
    return (p2-p1).cross(p3-p1);
}
double dot(Point p1,Point p2,Point p3){
    return (p2-p1).dot(p3-p1);
}
struct Line{
    Point s,e;//
    double ang;
    Line(){}
    Line(Point ss,Point ee){s=ss;e=ee;}
    void input(){s.input();e.input();}
    bool operator ==(const Line &v)const{return s==v.s&&e==v.e;}
    double len(){return (e-s).abs();}
    void calcAng(){ang= atan2l(dir().y,dir().x);}
    Point dir(){return e-s;}
    int checkLP(Point p){
        /* s e p make a counterclockwise 1
         * s e p make a clockwise 2
         * p is on a line p s e 3
         * p is on a line s e p 4
         * p is on a seg s e 5
         * error 6 */
        int tmp = sgn(cross(s,p,e));
        if(tmp<0)return 1;
        if(tmp>0)return 2;
        int dt=sgn(dot(p,s,e));
        if(dt<=0)return 5;
        if(sgn(dot(s,p,e))>0)return 4;
        if(sgn(dot(s,p,e))<0)return 3;
        assert(0);
    }
    int checkLL(Line v){
        // 3 coincide 2 parallel 1 orthogonal 0 others
        int tmp = sgn((e-s).cross(v.e-v.s));
        if(tmp==0){
            if(v.checkLP(e)>2)return 3;
            return 2;
        }
        if(sgn((e-s).dot(v.e-v.s))==0)return 1;
        return 0;
    }
    int checkSS(Line v){
        // 2 not strict 1 strict 0 not ins
        if(checkLP(v.s)==5|| checkLP(v.e)==5)return 2;
        if(v.checkLP(s)==5||v.checkLP(e)==5)return 2;
        int tmp=sgn(cross(s,e,v.s)* cross(s,e,v.e));
        int tmp2=sgn(cross(v.s,v.e,s)* cross(v.s,v.e,e));
        if(tmp<0&&tmp2<0)return 1;
        return 0;
    }
    int checkLS(Line v){//untested 21
        int d1 = sgn((e-s).cross(v.s-s));
        int d2 = sgn((e-s).cross(v.e-s));
        if((d1^d2)==-2) return 2;
        return (d1==0||d2==0);
    }
    Point getLL(Line v){
        double tmp=(s-v.s).cross(v.e-v.s),tmp2=(v.e-v.s).cross(e-v.s);
        return (s*tmp2+e*tmp)/(tmp+tmp2);
    }
    Point proj(Point p){
        return s+(e-s).trunc(dot(s,p,e)/len());
    }
    Point ref(Point p){
        Point tmp= proj(p);
        return tmp+tmp-p;

    }
    double disLP(Point p){return p.dis(proj(p));}
    double disSP(Point p){
        if(checkLP(proj(p))!=5)return min(p.dis(s),p.dis(e));
        return disLP(p);
    }
    double disSS(Line v){
        if(checkSS(v))return 0.0;
        return min({disSP(v.s), disSP(v.e),v.disSP(s),v.disSP(e)});
    }
    Line trans(Point v,double d){
        Point tmp=v.trunc(d);
        return {s+tmp,e+tmp};
    }
    Line transLeft(double d){return trans((e-s).rotLeft(),d);}
    Line transRight(double d){return trans((e-s).rotRight(),d);}
};
bool onSeg(Point p,Point a,Point b){return Line(a,b).checkLP(p)==5;}
struct Circle{
    Point p;
    double r;
    Circle(){}
    Circle(Point pp,double rr){p=pp;r=rr;}
    bool operator == (const Circle &c)const{
        return (p==c.p)&&(sgn(r-c.r)==0);
    }
    Point point(double a){return p+Point(r*cos(a),r*sin(a));}
    void input(){p.input();scanf("%lf",&r);}
    int include(Point q){if(sgn(p.dis(q)-r)==0)return 1;if(sgn(p.dis(q)-r)<0)return 2;return 0;}
    int checkCC(Circle c){
        //0  1  2  3  4 
        double d=c.p.dis(p);
        if(sgn(d-r-c.r)>0)return 4;
        if(sgn(d-r-c.r)==0)return 3;
        if(sgn(d- fabs(r-c.r))==0)return 1;
        if(sgn(d- fabs(r-c.r))<0)return 0;
        return 2;
    }
    int checkCL(Line l){
        //2  1 0 
        if(sgn(l.disLP(p)-r)==0)return 1;
        if(sgn(l.disLP(p)-r)<0)return 2;
        return 0;
    }
    vector<Point> getCL(Line v){
        //
        if(checkCL(v)==0)return {};
        vector<Point> tmp;
        double d=v.disLP(p);
        double x=sqrt(r*r-d*d);
        if(sgn(d-r)==0){
            tmp.pb(v.proj(p));
            tmp.pb(v.proj(p));
        }else{
            tmp.pb(v.proj(p)-(v.e-v.s).trunc(x));
            tmp.pb(v.proj(p)+(v.e-v.s).trunc(x));
            //v
        }
        return tmp;
    }
    double circ(){return 2*pi*r;}
    double area(){return pi*r*r;}
    vector<Point> getCC(Circle c){//,
        if(checkCC(c)==0|| checkCC(c)==4)return {};
        double b=p.dis(c.p),cosA=(r*r+b*b-c.r*c.r)/(2*r*b);
        double tmp=r*cosA,h=sqrt(r*r-tmp*tmp);
        Point v=(c.p-p).trunc(tmp).rotLeft().trunc(h);
        Point ini=p+(c.p-p).trunc(tmp);
        return {ini-v,ini+v};
    }
    vector<Point> TangentCP(Point q){
        if(include(q)==2)return {};
        if(include(q)==1)return {q,q};
        double cosA=r/p.dis(q),h=sqrt(sqr(r)- sqr(r*cosA));
        Point ini=(q-p).trunc(r*cosA),v=ini.rotLeft().trunc(h);
        return {p+ini-v,p+ini+v};
    }
    Point getPoint(double t){
        return p+Point(r* cos(t),r* sin(t));
    }
    double insCC(Circle c){
        if(checkCC(c)<2)return pi*sqr(min(r,c.r));
        if(checkCC(c)>2)return 0.0;
        double d=(p-c.p).abs();
        double x=(d*d+r*r-c.r*c.r)/(2*d);
        double t1= acos(x/r),t2= acos((d-x)/c.r);
        return sqr(r)*t1+sqr(c.r)*t2-d*r* sin(t1);
    }
    double insCT(Point a,Point b){
        auto tmp= getCL({a,b});
        if(tmp.empty())return r*r*p.rad(a,b)/2.0;
        int i1= include(a),i2= include(b);
        if(i1==0&&i2==0){
            if(sgn((a-p-tmp[0]).dot((b-p-tmp[0])))<=0&&
               sgn((a-p-tmp[1]).dot((b-p-tmp[1])))<=0
                    ){
                return (sqr(r)*(p.rad(a,b)-p.rad(tmp[0],tmp[1]))+(tmp[0]-p).cross(tmp[1]-p))/2.0;
            }else return sqr(r)*p.rad(a,b)/2.0;
        }else if(i1==0){
            return (sqr(r)*p.rad(a,tmp[0])+(tmp[0]-p).cross(b-p))/2.0;
        }else if(i2==0){
            return (sqr(r)*p.rad(tmp[1],b)+(a-p).cross(tmp[1]-p))/2.0;
        }else return (a-p).cross(b-p)/2.0;
    }
    double insCP(const vector<Point> &poly){
        int sz=poly.size();
        double ans=0.0;
        for(int i=0;i<sz;i++){
            int j=(i+1)%sz;
            ans+= insCT(poly[i],poly[j]);
        }
        return fabs(ans);
    }
    double Green_Circle(double t1,double t2){
        return r*(r*(t2-t1)+p.x*(sin(t2)-sin(t1))-p.y*(cos(t2)-cos(t1)));
    }
};
Circle outTri(Point a,Point b,Point c){//
    Line l={(a+b)/2.0,(a+b)/2.0+((a-b)/2.0).rotLeft()};
    Line r={(c+b)/2.0,(c+b)/2.0+((c-b)/2.0).rotLeft()};
    return {l.getLL(r),a.dis(l.getLL(r))};
}
Circle inTri(Point a,Point b,Point c){
    double d1=((a-c).getW()+(b-c).getW())/2,d2=((c-a).getW()+(b-a).getW())/2;
    Line tmp={c,c+Point(cos(d1), sin(d1))},tmp2={a,a+Point(cos(d2), sin(d2))};
    return {tmp.getLL(tmp2),Line(a,b).disLP(tmp.getLL(tmp2))};
}
vector<Line> TangentOutCC(Circle a,Circle b){
    if(a.checkCC(b)<2)return {};
    if(sgn(a.r-b.r)==0){
        return {{a.p+(b.p-a.p).trunc(a.r).rotLeft(),b.p+(a.p-b.p).trunc(b.r).rotRight()},
                {a.p+(b.p-a.p).trunc(a.r).rotRight(),b.p+(a.p-b.p).trunc(b.r).rotLeft()}};
    }
    int fl=sgn(a.r-b.r)>0?0:1;
    if(fl)swap(a,b);
    double alpha=acos((a.r-b.r)/(a.p.dis(b.p)));
    Point tmp=a.p+(b.p-a.p).rot({0,0},alpha).trunc(a.r),tmp2=a.p+(b.p-a.p).rot({0,0},-alpha).trunc(a.r);
    Point tmp3=b.p+(a.p-b.p).rot({0,0},-(pi-alpha)).trunc(b.r),tmp4=b.p+(a.p-b.p).rot({0,0},pi-alpha).trunc(b.r);
    if(fl)swap(tmp,tmp3), swap(tmp2,tmp4), swap(a,b);
    return {{tmp,tmp3},{tmp2,tmp4}};
}
vector<Line> TangentInCC(Circle a,Circle b){
    if(a.checkCC(b)==1|| a.checkCC(b)==3){
        Point tmp= a.getCC(b)[0];
        return {{tmp,tmp+(a.p-tmp).rotLeft()}};
    }else if(a.checkCC(b)!=4)return {};
    Point mid=a.p+(b.p-a.p)*(a.r/(a.r+b.r));
    auto l= a.TangentCP(mid),rr=b.TangentCP(mid);
    vector<Line> tmp;
    for(int i=0;i<l.size();i++){tmp.pb({l[i],rr[i]});}
    return tmp;
}
vector<Line> TangentCC(Circle a,Circle b){//TangentInCC
    auto inc = TangentInCC(a,b),outc= TangentOutCC(a,b);
    vector<Line> tmp;
    for(auto i:inc)tmp.push_back(i);for(auto i:outc)tmp.push_back(i);
    return tmp;
}

double polyArea(const vector<Point> &p){
    double ans=0;
    int sz=p.size();
    for(int i=0;i<sz;i++){
        ans+=(p[i].cross(p[(i+1)%sz]));
    }
    return fabs(ans)/2.0;
}
double polyCir(const vector<Point> &p){
    double ans=0;
    int sz=p.size();
    for(int i=0;i<sz;i++){
        ans+=(p[i].dis(p[(i+1)%sz]));
    }
    return ans;
}
bool isConvex(const vector<Point> &p,int flag=0){//0  1  counterclockwise
    int sz=p.size();
    for(int i=0;i<sz;i++){
        int x=Line(p[i],p[(i+1)%sz]).checkLP(p[(i+2)%sz]);
        if(x!=1){
            if(flag){if(x==2)return false;}
            else return false;
        }
    }
    return true;
}
int contain(vector<Point> ps, Point p){ //2:inside 1:onSeg 0:outside
    int n = ps.size(), ret = 0;
    for(int i=0;i<n;i++){
        Point u=ps[i],v=ps[(i+1)%n];
        if(onSeg(p,u,v)) return 1;
        if(cmp(u.y,v.y)<=0) swap(u,v);
        if(cmp(p.y,u.y) >0 || cmp(p.y,v.y) <= 0) continue;
        ret ^= sgn(cross(p,u,v)) > 0;
    }
    return ret*2;
}
vector<Point> convexCut(const vector<Point>&ps, Point q1, Point q2) {
    vector<Point> qs;
    int n = ps.size();
    for(int i=0;i<n;i++){
        Point p1 = ps[i], p2 = ps[(i+1)%n];
        int d1 = sgn(cross(q1,q2,p1)), d2 = sgn(cross(q1,q2,p2));
        if(d1 >= 0) qs.pb(p1);
        if(d1 * d2 < 0) qs.pb(Line(p1,p2).getLL({q1,q2}));
    }
    return qs;
}
double convexDiameter(vector<Point> ps){
    int n = ps.size(); if(n <= 1) return 0;
    int is = 0, js = 0;
    for(int k=0;k<n;k++)is=ps[k]<ps[is]?k:is, js = ps[js] < ps[k]?k:js;
    int i = is, j = js;
    double ret = ps[i].dis(ps[j]);
    do{
        if((ps[(i+1)%n]-ps[i]).cross(ps[(j+1)%n]-ps[j]) >= 0)
            (++j)%=n;
        else
            (++i)%=n;
        ret = max(ret,ps[i].dis(ps[j]));
    }while(i!=is || j!=js);
    return ret;
}

vector<Point> convexHull(vector<Point>A, int flag = 1) { // flag=0  flag=1 
    int n = A.size(); vector<Point>ans(n * 2);
    if(n==1)return A;
    sort(A.begin(), A.end()); int now = -1;
    for (int i = 0; i < A.size(); i++) {
        while (now > 0 && sgn(cross(ans[now-1],ans[now],A[i]))<flag)now--;
        ans[++now] = A[i];
    } int pre = now;
    for (int i = n - 2; i >= 0; i--) {
        while (now > pre && sgn(cross(ans[now-1],ans[now],A[i]))<flag)now--;
        ans[++now] = A[i];
    } ans.resize(now); return ans;
}

vector<Point> norm(vector<Point> p,Point q){//
    sort(p.begin(),p.end(),[&](Point a,Point b){
        int d = sgn((a-q).cross(b-q));
        if(d == 0){
            return sgn(a.dis(q)-b.dis(q)) < 0;
        }
        return d > 0;
    });
    return p;
}

vector<Point> graHam(vector<Point> ps){
    auto mi=ps[0];
    for(auto i:ps)mi=min(mi,i);
    ps = norm(ps,mi);
    int n=ps.size();
    vector<Point> ans(n*2);
    int top = 0;
    if(n == 1){
        top = 1;
        ans[0] = ps[0];
    }else if(n == 2){
        top = 2;
        ans[0] = ps[0];
        ans[1] = ps[1];
        if(ans[0] == ans[1])top--;
    }else{
        ans[0] = ps[0];
        ans[1] = ps[1];
        top = 2;
        for (int i = 2; i < n; i++) {
            while (top > 1 &&
                   sgn((ans[top-1]-ans[top - 2]).cross(ps[i]-ans[top-2]))<=0)
                top--;
            ans[top++] = ps[i];
        }
        if (top== 2 && (ans[0] == ans[1]))top--;
    }
    ans.resize(top);return ans;
}
vector<Point> getHL(vector<Line> &L) {//calcAng ==2 !=1
    int n = L.size();
    sort(L.begin(), L.end(),[&](Line a,Line b){return sgn(a.ang-b.ang)<0;});
    int first, last;
    vector<Point> p(n);
    vector<Line> q(n);
    vector<Point> ans;
    q[first = last = 0] = L[0];
    for (int i = 1; i < n; i++) {
        while (first < last && L[i].checkLP(p[last - 1])==2)last--;
        while (first < last && L[i].checkLP(p[first])==2)first++;
        q[++last] = L[i];
        if (sgn((q[last].dir().cross(q[last - 1].dir())))==0) {
            last--;
            if (q[last].checkLP(L[i].s)==1) q[last] = L[i];
        }
        if (first < last) p[last - 1] = q[last - 1].getLL(q[last]);
    }
    while (first < last && q[first].checkLP(p[last - 1])==2) last--;
    if (last - first <= 1) return ans;
    p[last] = q[last].getLL(q[first]);
    for (int i = first; i <= last; i++)
        ans.push_back(p[i]);
    return ans;
}
Point getBarycentre(vector<Point> &p){
    Point ret(0,0);
    double area = 0;
    int n=p.size();
    for(int i = 1;i < n-1;i++){
        double tmp = (p[i]-p[0]).cross(p[i+1]-p[0]);
        if(sgn(tmp) == 0)continue;
        area += tmp;
        ret.x += (p[0].x+p[i].x+p[i+1].x)/3*tmp;
        ret.y += (p[0].y+p[i].y+p[i+1].y)/3*tmp;
    }
    if(sgn(area)) ret = ret/area;
    return ret;
}

namespace fastCHTangent{//log
    vector<Point> c;
    int n,m;
    Point O;
    const int nnum=1e5+10;
    double f[nnum<<1];
    void init(vector<Point> p){//pcp
        c= convexHull(p);
        n=c.size();m=0;
        int i;
        for(O=c[0],i=0;i<n;i++){c[i]=c[i]-O;}
        for(i=0;i<n;i++)if(sgn(c[i].x-c[m].x)>=0)m=i;
        for(i=0;i<n;i++)c.push_back(c[i]);
        for(i=0;i<n+n;i++){
            f[i]=c[i].cross(c[(i+1)%n]);if(i)f[i]+=f[i-1];
        }
    }
    int askl(int l, int r, Point p) {
        int t = l++, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (sgn((c[mid] - p).cross(c[(mid-1+n)%n]-c[mid]))<=0)l = (t = mid) + 1;
            else r = mid - 1;
        }
        return t;
    }
    int askr(int l, int r,Point p) {
        int t = r--, mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(sgn((c[mid]-p).cross(c[(mid+1)%n]-c[mid]))>=0)r=(t=mid)-1;
            else l=mid+1;
        }
        return t;
    }
    vector<int> tangentPP(Point q){
        Point p=q-O;
        if(n<2)return {0,0};
        if(n==2)return {0,1};//n=2
        if(onSeg(p,c[0],c[n-1]))return {0,n-1};
        int o=0;
        if(sgn(p.x)>0){
            int l=1,r=n-1,mid;
            while(l<=r)if(sgn(c[mid=(l+r)>>1].cross(p))>=0)l=(o=mid)+1;else r=mid-1;
        }else if(sgn(p.y)>0)o=n-1;
        if(sgn(p.x)>=0&&sgn((p-c[o]).cross(c[o+1]-p))<0)return {};
        if(sgn(p.x)>=0&& onSeg(p,c[o],c[o+1]))return {o,o+1};
        int l,r;
        if(sgn(p.x)>0)l= askl(0,o,p),r= askr(o,n,p);else l= askl(m,n,p),r= askr(0,m,p);
        if(l>r)r+=n;
        return {l,r};
    }
    double getArea(int l,int r,Point p){
        return f[n-1]+c[l].cross(p)+p.cross(c[r])-f[r-1]+f[l-1];
    }
}

namespace fastIsCHLine{//untested
    const int N = 1e5+10;
    double arc[N],sum[N];
    vector<Point> vec;
    int nn;
    void init(vector<Point>& ps){
        for(auto i:ps)vec.push_back(i);
        for(auto i:ps)vec.push_back(i);
        vec.push_back(ps[0]);
        int n=ps.size();
        nn=n;
        for(int i=0;i<n+n;i++){
            sum[i+1]=sum[i]+(vec[i].cross(vec[i+1]));
        }
        for(int i=0;i<n+n;i++){
            int j=(i+1)%n;
            arc[i]= atan2l(vec[j].y-vec[i].y,vec[j].x-vec[i].x);
            if(i&&sgn(arc[i]-arc[i-1])<0){
                arc[i]+=pi+pi;
            }
        }
    }
    int getseg(Point p,Point v,int l,int r){
        l--;
        while(l<r){
            int mid=l+r+1>>1;
            if(sgn(v.cross(vec[mid]-p))<0){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
    void work(Point a,Point b){
        if(b<a)swap(a,b);
        double al= atan2l(b.y-a.y,b.x-a.x);
        if(sgn(al-arc[0])<0)al+=pi+pi;
        int Left=(lower_bound(arc,arc+nn,al)-arc)%nn;
        double ar=atan2l(a.y-b.y,a.x-b.x);
        if(sgn(ar-arc[0])<0)ar+=pi+pi;
        int Right= lower_bound(arc,arc+nn,ar)-arc;
        int down=getseg(a,b-a,Left,Right);
        int up= getseg(b,a-b,Right,Left+nn);
        if(down<Left||up<Right){
            puts("0.0000000");
        }else{
            Point d=Line(a,b-a).getLL({vec[down],vec[down+1]-vec[down]});
            Point u=Line(b,a-b).getLL({vec[up],vec[up+1]-vec[up]});
            double area=(d.cross(vec[down+1]))+(sum[up]-sum[down+1])+(vec[up].cross(u))+u.cross(d);
            printf("%.6f\n" , min(sum[nn] - area , area) / 2);
        }
    }
}

pair <double,Point> areaCs(vector<Circle> &cs){//  kcnt=1ret/2-ans[i+1]
    double ret=0;
    Point pret;
    int n=cs.size();
    for(int i=0;i<n;i++){
        vector<pair<double,int>> vec;
        vec.push_back({0,0});vec.push_back({pi*2,0});
        int cnt=1;
        for(int j=0;j<n;j++){
            double d=cs[i].p.dis(cs[j].p);
            if(!sgn(d) && !sgn(cs[i].r-cs[j].r)){
                if(i<j)cnt++;
                continue;
            }
            if(cs[i].checkCC(cs[j])>=3)continue;
            if(sgn(d+cs[j].r-cs[i].r)<=0)continue;
            if(sgn(d+cs[i].r-cs[j].r)<=0){cnt++;continue;}
            double angle=(cs[j].p-cs[i].p).getW();
            double p = (sqr(cs[i].r) + sqr(d) - sqr(cs[j].r)) / (2 * cs[i].r * d);
            p= acos(max(-1.0L,min(1.0L,p)));
            double l=angle-p,r=angle+p;
            if(sgn(l)<0)l+=2*pi;
            if(sgn(r)<0)r+=2*pi;
            if(sgn(l-2*pi)>=0)l-=2*pi;
            if(sgn(r-2*pi)>=0)r-=2*pi;
            vec.push_back({l,1});vec.push_back({r,-1});
            if(sgn(l-r)>=0)cnt++;
        }
        sort(vec.begin(),vec.end());
        int sz=vec.size();
        for(int j=0;j<sz-1;j++){
            cnt+=vec[j].second;
            if(cnt==1){
                double delta=vec[j+1].first-vec[j].first;
                if(sgn(delta)<=0)continue;
                double s= sin(delta/2.0);
                Point ct=Point(4 * cs[i].r * s * s * s / (3 * (delta - sin(delta))), 0);
                ct = ct.rot({0,0},(vec[j].first + vec[j + 1].first) / 2) + cs[i].p;
                double area = sqr(cs[i].r) * (delta - sin(delta));
                pret = pret + ct * area;
                ret += area;
                Point p1 = cs[i].point(vec[j].first), p2 = cs[i].point(vec[j + 1].first);
                area = p1.cross(p2);
                pret = pret + (p1 + p2) * area / 3;
                ret += area;
            }
        }
    }
    return {ret / 2, pret / ret};
}
Point ps[10];

double getMax(Point a,Point b,Point c){
    return max({fabs(a.rad(b,c)),fabs(b.rad(a,c)),fabs(c.rad(b,a))});
}

Circle getSteiC(Point a,Point b,Point c){
    double d=a.dis(b);
    double r=d/sqrt(3.0);
    double tmp=cross(a,b,c);
    if(sgn(tmp)>0){
        Point tmpp=a.rot(b,pi/6);
        Point cp=b+(tmpp-b).trunc(r);
        return {cp,r};
    }else{
        Point tmpp=b.rot(a,pi/6);
        Point cp=a+(tmpp-a).trunc(r);
        return {cp,r};
    }
}

double getStei(Point a,Point b,Point c){
    Circle lc= getSteiC(a,b,c);
    Circle rc= getSteiC(a,c,b);
    auto ins=lc.getCC(rc);
    if(ins.empty()){
        exit(-3);
    }
    double res=1e20;
    for(auto i:ins){
        if(sgn(res-i.dis(a)-i.dis(b)-i.dis(c))>0)res=i.dis(a)+i.dis(b)+i.dis(c);
    }
    return res;
}

double getDis(Point a,Point b,Point c){
    return min({a.dis(b)+c.dis(b),a.dis(c)+b.dis(c),b.dis(a)+c.dis(a)});
}

const double stei=pi*2/3;
double calc(double x,double y){
    Point tmp={x,y};
    double dd=0;
    for(int i=1;i<=3;i++){
        int j=i+1;
        if(j>3)j-=3;
        double al= getMax(tmp,ps[i],ps[j]);
        if(sgn(al)<=0){
            dd=max(dd,ps[i].dis(ps[j]));
        }else if(sgn(al-stei)<=0){
            dd=max(dd, getStei(tmp,ps[i],ps[j]));
        }else{
            dd=max(dd,getDis(tmp,ps[i],ps[j]));
        }
    }
    return dd;
}




double calcY(double x){
    double ly=1e5,ry=-1e5;
    Line tmpl={{x,ly},{x,ry}};
    for(int i=1;i<=3;i++){
        int j=i+1;
        if(j>3)j-=3;
        if(inmid(x,min(ps[i].x,ps[j].x),max(ps[i].x,ps[j].x))){
            Point tmppp=tmpl.getLL({Line{ps[i],ps[j]}});
            ly=min(ly,tmppp.y);
            ry=max(ry,tmppp.y);
        }
    }
    for(int i=1;i<=60;i++){
        double lmid=(ly+ry)/2,rmid=(lmid+ry)/2;
        double ansl= calc(x,lmid),ansr=calc(x,rmid);
        if(sgn(ansl-ansr)>0){
            ly=lmid;
        }else{
            ry=rmid;
        }
    }
    return calc(x,ry);
}


double calcX(){
    double l=min({ps[1].x,ps[2].x,ps[3].x});
    double r=max({ps[1].x,ps[2].x,ps[3].x});
    for(int i=1;i<=60;i++){
        double lmid=(l+r)/2,rmid=(lmid+r)/2;
        double ansl= calcY(lmid),ansr=calcY(rmid);
        if(sgn(ansl-ansr)>0){
            l=lmid;
        }else{
            r=rmid;
        }
    }
    return calcY(r);
}

int main(){
    Point ini={0,0};
    for(int i=1;i<=3;i++){
        ps[i].input();
        ps[i]=ps[i].rot(ini,0.00001);
    }
    double ans=calcX();
    printf("%.12Lf\n",ans);
    return 0;
}