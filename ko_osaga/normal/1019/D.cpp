#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
 
struct pnt{
    int x, y, idx;
    bool operator<(const pnt &p)const{
        return pi(x, y) < pi(p.x, p.y);
    }
}a[2005];
 
struct line{
    int dx, dy, i1, i2;
};
 
vector<line> v;
int n, rev[2005];
lint p, q;
 
lint ccw(pnt a, pnt b, pnt c){
    int dx1 = b.x - a.x;
    int dy1 = b.y - a.y;
    int dx2 = c.x - a.x;
    int dy2 = c.y - a.y;
    return abs(1ll * dx1 * dy2 - 1ll * dy1 * dx2);
}

void report(int x, int y, int z){
	puts("Yes");
	for(auto &i : {x, y, z}){
	printf("%d %d\n", a[i].x, a[i].y);
	}
	exit(0);
}

void solve(int c1, int c2, lint l){
    int s = c2, e = n-1;
    while(s != e){
        int m = (s+e+1)/2;
        if(ccw(a[c1], a[c2], a[m]) <= l) s = m;
        else e = m-1;
    }
    if(ccw(a[c1], a[c2], a[s]) == l){
    	report(c1, c2, s);
	}
    s = 0, e = c1;
    while(s != e){
        int m = (s+e)/2;
        if(ccw(a[c1], a[c2], a[m]) <= l) e = m;
        else s = m+1;
    }
    if(ccw(a[c1], a[c2], a[s]) == l){
    	report(c1, c2, s);
	}
}
 
int main(){
    cin >> n >> p;
    p <<= 1;
    for(int i=0; i<n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        a[i].idx = i;
        rev[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            v.push_back({a[j].x - a[i].x, a[j].y - a[i].y, a[i].idx, a[j].idx});
        }
    }
    sort(v.begin(), v.end(), [&](const line &a, const line &b){
        lint cw = 1ll * a.dx * b.dy - 1ll * b.dx * a.dy;
        if(cw != 0) return cw > 0;
        return pi(a.i1, a.i2) < pi(b.i1, b.i2);
    });
    lint ret = 0;
    for(int i=0; i<v.size(); i++){
        int c1 = rev[v[i].i1], c2 = rev[v[i].i2];
        if(c1 > c2) swap(c1, c2);
        solve(c1, c2, p); 
        swap(a[c1], a[c2]);
        swap(rev[v[i].i1], rev[v[i].i2]);
    }
    cout << "No" << endl;
}