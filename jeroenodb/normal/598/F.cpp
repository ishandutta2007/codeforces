#include "bits/stdc++.h"
//  #include "geodeb.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1;
const double oo = 1e20;
typedef complex<int> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
void read(pt& p) {
    double a,b; cin >> a >> b;
    p = {round(a*100),round(b*100)};
}

ll area(vector<pt> poly) {
    int n = poly.size();
    ll ans = 0;
    pt prev = poly.back();
    for(auto cur : poly) {
        ans+=(ll)(cur.Y+prev.Y)*(cur.X-prev.X);
        prev = cur;
    }
    return ans;
}
struct triangle {
    pt a[3]; // counterclockwise
    int inside(pt b) {
        return ccw(a[0],a[1],b)>=0 and
        ccw(a[1],a[2],b)>=0 and
        ccw(a[2],a[0], b) >=0;
    }
    pair<double,double> intersectline(pt c, pt d) { // returns a segment [mn,mx] where the triangle intersects the line. This is scaled by abs(c,d)
        array<ll,3> ccws = {ccw(c,d,a[0]), ccw(c,d,a[1]), ccw(c,d,a[2])};
        array<int,3> tmp;
        for(int i=0;i<3;++i) tmp[i] = sgn(ccws[i]);
        if(abs(tmp[0]+tmp[1]+tmp[2])>=2) return {0,0}; //check if triangle doesnt intersect line
        int j=2;
        double mn = oo, mx = -oo;
        for(int i=0;i<3;++i){
            double ans;
            if(tmp[i]==0) {
                ans = in(d-c,a[i]-c);

            }else if(tmp[j]!=0 and tmp[i]!=tmp[j]) {
                double ans1 = in(d-c,a[i]-c);
                double ans2 = in(d-c,a[j]-c);
                double denom = abs(ccws[i]) + abs(ccws[j]);
                ans = (ans2*abs(ccws[i]) + ans1*abs(ccws[j]))/denom;
            } else {
                j=i;
                continue;
            };
            j=i;
            mn = min(mn,ans);
            mx = max(mx,ans);
            
        }
        return {mn,mx};
    }
    void draw() {
        // // GD_POLYGON("black:salmon",
        //     for(int i=0;i<3;++i) {
        //         // GD_POLYPOINT(a[i].X,a[i].Y);
        //     }
        // );
    }
};
struct arraylist {
    vi nxt,prev;
    int head=-1, size=0;
    arraylist(int n) {
        nxt.assign(n,-1);
        prev.assign(n,-1);
    }
    void insert(int a) {
        size++;
        nxt[a] = head;
        if(head!=-1) {
            prev[head] = a;
        }
        head = a;
    }
    bool in(int a) {
        return a==head or prev[a]!=-1;
    }
    void remove(int a) {
        // only call on elements in the list
        size--;
        if(a==head) {
            head = nxt[a];
        } else{
            assert(prev[a]!=-1);
            nxt[prev[a]] = nxt[a];
        }
        if(nxt[a]!=-1) prev[nxt[a]] = prev[a];
        prev[a] = -1; 
    }

};
vector<triangle> earcutting(const vector<pt>& poly) {
    int n = poly.size();
    int left = n;
    vi nxt(n,0), prev(n,0);
    arraylist ear(n), concave(n);
    iota(all(nxt),1); nxt.back() = 0;
    iota(all(prev),-1); prev[0] = n-1;
    auto remove = [&](int at) {
        prev[nxt[at]] = prev[at];
        nxt[prev[at]] = nxt[at];
        left--;
    };
    for(int i=0;i<n;++i) {
        auto tmp = ccw(poly[prev[i]], poly[i],poly[nxt[i]]);
        if(tmp>0) {
            ear.insert(i);
        } else if(tmp<0) {
            concave.insert(i);
        } else {
            remove(i);
        }
    }

    auto isear = [&](int a) {
        triangle tr({poly[prev[a]],poly[a],poly[nxt[a]]});
        for(int i = concave.head;i!=-1;i = concave.nxt[i]) {
            if(i==prev[a] or i==nxt[a]) continue;
            if (tr.inside(poly[i])) {
                return false;
            }
        }
        return true;
    };
    int at = ear.head;
    while(at!=-1) {
        int to = ear.nxt[at];
        if(!isear(at)) {
            ear.remove(at);
        }
        at = to;  
    }

    auto update = [&](int i) {
        if(concave.in(i)) {
            if(ccw(poly[prev[i]], poly[i],poly[nxt[i]])>=0) {
                concave.remove(i);
            }
        }
        if(!concave.in(i)) {
            if(isear(i)) {
                if(!ear.in(i)) ear.insert(i);
            } else if(ear.in(i)) {
                ear.remove(i);
            }
        }
    };

    // Begin algorithm
    vector<triangle> ans;

    while((at = ear.head) != -1) {

        ans.push_back({{poly[prev[at]],poly[at],poly[nxt[at]]}});
        ans.back().draw();
        if(left==3) break;
        ear.remove(at);
        remove(at);
        update(nxt[at]);
        if(prev[at]!=nxt[at]) 
            update(prev[at]);
    }
    return ans;
}
int main() {
    // GD_INIT("ears.html");
    // GD_LOG_TO_STDERR(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<pt> poly(n);
    for(auto& p: poly) {
        read(p);
        // GD_POINT(p.X,p.Y);
    }
    if(area(poly)>0) {
        reverse(all(poly));
    }
    auto trs = earcutting(poly);
    for(int i=0;i<m;++i) {
        // GD_LAYER();
        pt a,b; read(a);read(b);
        struct event {
            double a;
            bool end;
            bool operator<(const event& o) const {
                return a<o.a or (a==o.a and end < o.end);
            }
        };
        vector<event> events;

        for(auto& tr : trs) {
            auto [mn,mx] = tr.intersectline(a,b);
            if(mn!=mx) {
                events.push_back({mn,false});
                events.push_back({mx,true});
            }
        }
        sort(all(events));
        double ans = 0;
        int cur = 0;
        double prev = 0;
        for(auto& e : events) {
            if(e.end) {
                if(--cur==0) {
                    ans+=e.a-prev;
                }
            } else {
                if(cur++==0) {
                    prev = e.a;
                }
            }
        }
        ans = 0.01* ans/sqrt(norm(b-a));
        // GD_LINE(a.X,a.Y,b.X,b.Y, "blue bold") << ans;
        cout << setprecision(12) << ans << '\n';
    }

}