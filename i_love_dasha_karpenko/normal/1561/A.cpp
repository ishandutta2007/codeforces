//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
const ld eps = 1e-6;
struct dot{
    ld x,y;
    dot(ld x1 = 0,ld y1 = 0){
        x = x1;
        y = y1;
    }
    void read(){
        cin>>x>>y;
    }
};
struct line{
    ld a,b,c;
    
    line(ld a1 = 0,ld b1 = 0,ld c1 = 0){
        a = a1,b = b1,c = c1;
    }
    void by_dots(dot d1,dot d2){
        a = d2.y-d1.y;
        b = d1.x-d2.x;
        c = -(a*d1.x+b*d1.y);
    }
    int check(dot d){
        return abs(a*d.x+b*d.y+c)<eps;
    }
    ld dist(dot d){
        return abs(a*d.x+b*d.y+c)/sqrt(a*a+b*b);
    }
    int rel(dot d){
        if (abs(b)<eps)
            return d.x<ld(-c)/a;
        return d.y>(a*d.x+b*d.y+c);
    }
    void read(){
        cin>>a>>b>>c;
    }

};

const ld INF = 1E18;
const ld SUP = INF*INF;
const dot inf_dots = dot(SUP,SUP);
const dot no_dot = dot(-SUP,-SUP);

const bool operator == (const dot &a,const dot &b){
    return a.x==b.x && a.y==b.y;
}
dot intersect(line a,line b){
    ll a1 = a.a,a2 = b.a;
    ld div = ld(a.b*a2-b.b*a1);
    ld mult = ld(b.c*a1-a.c*a2);
    if (abs(div)<eps){
        if (abs(mult)<eps)
            return inf_dots;
        else
            return no_dot;
    }
    ld y = mult/div;
    if (abs(a.a)<eps)
        swap(a,b);
    ld x = -ld(a.c+a.b*y)/a.a;
    return dot(x,y);
}
void print(dot a){
    if (a==inf_dots)
        cout<<"2\n";
    else if (a==no_dot)
        cout<<"0\n";
    else cout<<"1 "<<fixed<<setprecision(8)<<a.x<<' '<<a.y<<endl;
}
void print(ld a){
    cout<<fixed<<setprecision(8)<<a<<endl;
}
ld dist(dot a,dot b){
    ld dx = a.x-b.x,dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

ld cos_ang(dot a,dot b,dot c){
    ld dx1 = a.x-b.x,dx2 = c.x-b.x,dy1 = a.y-b.y,dy2 = c.y-b.y;
    return dx1*dx2+dy2*dy1;
}
int sign(ld x){
    if (abs(x)<eps)
        return 0;
    return x<0?-1:1;
}
int eq(ld a,ld b){
    return abs(a-b)<eps;
}
struct segm{
    line L;
    ld x_l,x_r,y_l,y_r;
    dot dot_l,dot_r;
    segm (dot d1 = no_dot,dot d2 = no_dot,int beam = 0){
        x_l = d1.x,x_r = d2.x*(beam==1?d1.x<d2.x?INF:-INF:1);
        y_l = d1.y,y_r = d2.y*(beam==1?d1.y<d2.y?INF:-INF:1);
        dot_l = dot(x_l,y_l),dot_r = dot(x_r,y_r);
        if (x_l>x_r)
            swap(x_l,x_r);
        if (y_l>y_r)
            swap(y_l,y_r);
        L.by_dots(d1,d2);
    }
    int check(dot d){
        if (!L.check(d))
            return 0;
        if (abs(L.b)<eps)
            return y_l<=d.y && d.y<=y_r;
        return (x_l<d.x || eq(x_l,d.x)) && (d.x<x_r || eq(x_r,d.x));
    }

    ld dist(dot d){
        line rev;
        rev.a = -L.b;
        rev.b = L.a;
        rev.c = -(rev.a*d.x+rev.b*d.y);
        dot nts = intersect(rev,L);
        if (check(nts))
            return L.dist(d);
        int a1 = sign(cos_ang(d,dot_l,dot_r)),a2 = sign(cos_ang(d,dot_r,dot_l));
        if (a1>=0 && a2>=0)
            return L.dist(d);
        return min(::dist(d,dot_l),::dist(d,dot_r));
    }
};
const int N = 1e3+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    int cnt = 0;
    while(1){
        int flag = 0;
        for(int i = 1;i<n;++i){
            if (A[i]>A[i+1]){
                flag = 1;
                break;
            }
        }
        if (!flag)
            break;
        ++cnt;
        for(int i = 1+(1-cnt%2);i<n;i+=2){
            if (A[i]>A[i+1])
                swap(A[i],A[i+1]);
        }

    }
    cout<<cnt<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}