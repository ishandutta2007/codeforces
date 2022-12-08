#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define mp make_pair
#define ld long double
#define MAXN 2123456
#define int long long

typedef int cood;

const double pi = acos(-1.);
template<typename T> inline T sq(T x) { return x*x; }

struct vec {
    cood x, y;
    vec () : x(0), y(0) {} vec (cood a, cood b) : x(a), y(b) {}
    inline vec operator - (vec o) { return {x - o.x, y - o.y}; }
    inline vec operator + (vec o) { return {x + o.x, y + o.y}; }
    inline vec operator * (cood o) { return {x * o, y * o}; }
    inline vec operator / (cood o) { return {x / o, y / o}; }
    inline cood operator ^ (vec o) { return x * o.y - y * o.x; }
    inline cood operator * (vec o) { return x * o.x + y * o.y; }
    inline cood cross (vec a, vec b) { return ((*this)-a) ^ ((*this)-b); } // |(this)a||(this)b|sen(angle)
    inline cood inner (vec a, vec b) { return ((*this)-a) * ((*this)-b); } // |(this)a||(this)b|cos(angle)
    inline double angle (vec a, vec b) { return atan2(cross(a,b),inner(a,b)); } // ccw angle from (this)a to (this)b in range [-pi,pi]
    inline int ccw (vec a, vec b) { cood o = cross(a,b); return (eps < o) - (o < -eps); } // this is to the (1 left, 0 over, -1 right) of ab
    inline int dir (vec a, vec b) { cood o = inner(a,b); return (eps < o) - (o < -eps); } // a(this) is to the (1 same, 0 none, -1 opposite) direction of ab
    inline cood sq (vec o = vec()) { return inner(o,o); }
    inline double nr (vec o = vec()) { return sqrt(sq(o)); } //$
    inline vec operator ~ () { return (*this)/nr(); }
    inline vec proj (vec a, vec b) { return a + (b-a)*(a.inner((*this),b) / a.sq(b)); } // projects this onto line ab
    inline vec rotate (double a) { return vec(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); } // ccw by a radians
    inline vec rot90 () { return vec(-y,x); } // rotate(pi/2)$
    bool in_seg (vec a, vec b) { return ccw(a,b) == 0 && dir(a,b) <= 0; } // tips included
    double dist2_lin (vec a, vec b) { return a.sq(b) <= eps ? sq(a) : double(::sq(cross(a,b)))/a.sq(b); } // see cir.has_inter_lin
    double dist2_seg (vec a, vec b) { return a.dir((*this),b) == (b.dir((*this),a)) ? dist2_lin(a,b) : min(sq(a),sq(b)); }
    inline bool operator == (const vec & o) const { return abs(x-o.x) <= eps && abs(y-o.y) <= eps; }
    inline bool operator < (const vec & o) const { return (abs(x-o.x)>eps)?(x < o.x):(y > o.y); } // lex compare (inc x, dec y)
}; //$

vec global;

bool compare (vec a, vec b) { 
        if ((global < a) != (global < b)) return global < b;
        int o = global.ccw(a,b); return o?o>0:((a == global && !(a == b)) || a.dir(global,b) < 0);
}

bool compare2 (vec a,vec b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

vector<vec> ori;

vector<vec> par;

void trans(vec a){
    par.clear();
    for(vec x:ori){
        if(!(x==a)&&compare2(a,x))par.pb(vec(x.x,x.y));
    }
    global=a;
    sort(par.begin(),par.end(),compare);
}

        
int32_t main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ori.pb(vec(a,b));
    }
    int colin=0;
    for(int i=0;i<n;i++){
        trans(ori[i]);
        int total=par.size()*(par.size()-1)/2;
        int iguais=1;
        //cout<<ori[i].x<<" e "<<ori[i].y<<endl;
        for(vec x:par){
            //cout<<x.x<<" "<<x.y<<endl;
        }
        for(int j=1;j<par.size();j++){
            if(abs(ori[i].cross(par[j],par[j-1]))==0){
                //cout<<"paralelo "<<ori[i].x<<" "<<ori[i].y<<"  "<<par[j].x<<" "<<par[j].y<<"  "<<par[j-1].x<<" "<<par[j-1].y<<endl;
                iguais++;
            }
            else{
                colin+=iguais*(iguais-1)/2;
                iguais=1;
            }
        }
        colin+=iguais*(iguais-1)/2;
        //cout<<colin<<endl;
    }
    colin=colin;
    int tot=n*(n-1)*(n-2)/6;
    //cout<<tot<<" "<<colin<<endl;
    cout<<tot-colin<<endl;

    return 0;
}