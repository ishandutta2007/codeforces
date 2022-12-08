#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
//#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234
typedef long double num;
#define eps 1e-8


num sq(num a){
    return a*a;
}

struct Vector{
    num x,y;
    Vector () : x(0), y(0) {} Vector (num a, num b) : x(a), y(b) {}
    Vector operator + (Vector q) const{
        return {x + q.x, y + q.y };
    };
    Vector operator - (Vector q) const{
        return {x - q.x, y - q.y };
    };
    Vector operator * (int t) const{
        return {t * x, t * y };
    };
    num operator * (Vector q) const{
        return {x*q.x + y*q.y };
    };
    num operator ^ (Vector q) const{
        return {x*q.y - y*q.x };
    };
    num sqsize () {
        return sq(x) + sq(y) ;
    }
    long double size () {
        return sqrt( sq(x) + sq(y) ) ;
    }

};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    Vector c,l;

    double r;
    cin>>r>>c.x>>c.y>>l.x>>l.y;

    if((l-c).size()>=r){
        cout<<c.x<<" "<<c.y<<" "<<r<<endl;
        return 0;
    }

    long double d1=(l-c).size();

    if(d1<=eps){
        cout<<(c.x-(r/2))<<" "<<c.y<<" "<<r/2<<endl;
        return 0;
    }

    double p1=(c.x-l.x)/d1;
    double p2=(c.y-l.y)/d1;

    Vector po;
    po.x=c.x+(r*p1);
    po.y=c.y+(r*p2);

    //cout<<po.x<<" "<<po.y<<endl;

    Vector resp;
    resp.x=(po.x+l.x)/2;
    resp.y=(po.y+l.y)/2;

    cout<<resp.x<<" "<<resp.y<<" "<<((l-c).size()+r)/2<<endl;










    return 0;

}