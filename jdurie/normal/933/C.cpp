//Geometry
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef complex<ld> pt;
struct line {
	pt P, D; bool S = false;
	line(pt p, pt q, bool b = false) : P(p), D(q - p), S(b) {}
	line(pt p, ld th) : P(p), D(polar((ld)1, th)) {}
};
struct circ { pt C; ld R; };

/**
 * builtin pt operations:
 * +, -: usual vector addition/subtraction
 * *, /: scalar multiplication/division (also complex multiplication / division if that's ever useful)
 * abs(p): vector length
 * norm(p): squared vector length
 * arg(p): angle p forms with positive x axis
 * polar(r, th): vector with length r pointing in direction th
 * conj(p): reflects p over x axis
 */

#define X real()
#define Y imag()
#define CRS(a, b) (conj(a) * (b)).Y //scalar cross product
#define DOT(a, b) (conj(a) * (b)).X //dot product
#define U(p) ((p) / abs(p)) //unit vector in direction of p (don't use if Z(p) == true)
#define Z(x) (abs(x) < EPS)
#define A(a) (a).begin(), (a).end() //shortens sort(), upper_bound(), etc. for vectors

//constants (INF and EPS may need to be modified)
ld PI = acosl(-1), INF = 1e20, EPS = 1e-12;
pt I = {0, 1};

namespace std {
	//lexicographical comparison
	bool operator<(pt a, pt b) { return Z(a.X - b.X) ? a.Y < b.Y : a.X < b.X; }
}

/**
 * GENERAL GEOMETRY FUNCTIONS
 */

//true if d1 and d2 parallel (zero vectors considered parallel to everything)
bool parallel(pt d1, pt d2) { return Z(d1) || Z(d2) || Z(CRS(U(d1), U(d2))); }

//"above" here means if l & p are rotated such that l.D points in the +x direction, then p is above l
bool above_line(pt p, line l) { return CRS(p - l.P, l.D) > 0; }

//true if p is on line l
bool on_line(pt p, line l) { return parallel(l.P - p, l.D) && (!l.S || DOT(l.P - p, l.P + l.D - p) <= EPS); }

//returns 0 for no intersection, 2 for infinite intersections, 1 otherwise. p holds intersection pt
ll intsct(line l1, line l2, pt& p) {
	if(parallel(l1.D, l2.D)) return on_line(l1.P, l2) ? 2 : 0;
	pt q = l1.P + l1.D * CRS(l2.D, l2.P - l1.P) / CRS(l2.D, l1.D);
	if(on_line(q, l1) && on_line(q, l2)) { p = q; return 1; }
	return 0;
}

//closest pt on l to p
pt cl_pt_on_l(pt p, line l) {
	pt q = l.P + DOT(U(l.D), p - l.P) * U(l.D);
	if(on_line(q, l)) return q;
	return abs(p - l.P) < abs(p - l.P - l.D) ? l.P : l.P + l.D;
}

//distance from p to l
ld dist_to(pt p, line l) { return abs(p - cl_pt_on_l(p, l)); }

//p reflected over l
pt refl_pt(pt p, line l) { return conj((p - l.P) / U(l.D)) * U(l.D) + l.P; }

//ray r reflected off l (if no intersection, returns original ray)
line reflect_line(line r, line l) {
	pt p; if(intsct(r, l, p) - 1) return r;
	return line(p, p + INF * (p - refl_pt(r.P, l)), 1);
}

/**
 * TRIANGLE CENTERS
 */

//altitude from p to l
line alt(pt p, line l) { l.S = 0; return line(p, cl_pt_on_l(p, l)); }

//angle bisector of angle abc
line ang_bis(pt a, pt b, pt c) { return line(b, b + INF * (U(a - b) + U(c - b)), 1); }

//perpendicular bisector of l (assumes l.S == 1)
line perp_bis(line l) { return line(l.P + l.D / (ld)2, arg(l.D * I)); }

//orthocenter of triangle abc
pt orthocent(pt a, pt b, pt c) { pt p; intsct(alt(a, line(b, c)), alt(b, line(a, c)), p); return p; }

//incircle of triangle abc
circ incirc(pt a, pt b, pt c) {
	pt cent; intsct(ang_bis(a, b, c), ang_bis(b, a, c), cent);
	return {cent, dist_to(cent, line(a, b))};
}

//circumcircle of triangle abc
circ circumcirc(pt a, pt b, pt c) {
	pt cent; intsct(perp_bis(line(a, b, 1)), perp_bis(line(a, c, 1)), cent);
	return {cent, abs(cent - a)};
}

/**
 * CONVEX HULL
 */

//returns true if p is contained in the convex hull given by hu / hd
bool in_hull(pt p, pair<vector<pt>, vector<pt>>& h) {
	if(Z(p - *h.first.begin()) || Z(p - *h.second.begin())) return false; //change to true if border counts as inside
	if(p < *h.first.begin() || *h.second.begin() < p) return false;
	auto u = upper_bound(A(h.first), p);
	auto d = lower_bound(h.second.rbegin(), h.second.rend(), p);
	return CRS(*u - p, *(u - 1) - p) > EPS && CRS(*(d - 1) - p, *d - p) > EPS; //change to > -EPS if border counts as "inside"
}

//helper function for get_hull
void do_hull(vector<pt>& pts, vector<pt>& h) {
	for(pt p : pts) {
		while(h.size() > 1 && CRS(h.back() - p, h[h.size() - 2] - p) <= EPS)
			h.pop_back();
		h.push_back(p);
	}
}

//returns upper convex hull / lower convex hull of pts
pair<vector<pt>, vector<pt>> get_hull(vector<pt>& pts) {
	vector<pt> hu, hd;
	sort(A(pts)), do_hull(pts, hu);
	reverse(A(pts)), do_hull(pts, hd);
	return {hu, hd};
}

//returns convex hull of pts as a vector of pts in cw order
vector<pt> full_hull(vector<pt>& pts) {
	auto h = get_hull(pts);
	h.first.pop_back(), h.second.pop_back();
	for(pt p : h.second) h.first.push_back(p);
	return h.first;
}

/**
 * DYNAMIC CONVEX HULL
 */

//helper function for dyn_in_hull
bool dyn_in(pt p, set<pt>& h) {
	if(h.empty() || p < *h.begin() || *h.rbegin() < p) return false;
	auto i = h.upper_bound(p), j = i--;
	return CRS(*j - p, *i - p) > EPS; //change to > -EPS if border counts as "inside"
}

//returns true if p contained in dynamic hull hu / hd
bool dyn_in_hull(pt p, pair<set<pt>, set<pt>>& h) { return dyn_in(p, h.first) && dyn_in(-p, h.second); }

//helper function for dyn_add
void fix_bad(set<pt>::iterator i, set<pt>&h, bool l) {
	if(i == --h.begin() || i == h.end()) return;
	pt p = *i; h.erase(p);
	if(!dyn_in(p, h)) h.insert(p);
	else fix_bad(l ? --h.lower_bound(p) : h.upper_bound(p), h, l);
}

//helper function for dyn_add_to_hull
void dyn_add(pt p, set<pt>& h) {
	if(dyn_in(p, h)) return;
	h.insert(p);
	fix_bad(--h.lower_bound(p), h, true);
	fix_bad(h.upper_bound(p), h, false);
}

//adds p to dynamic hull hu / hd
void dyn_add_to_hull(pt p, pair<set<pt>, set<pt>>& h) { dyn_add(p, h.first), dyn_add(-p, h.second); }

//turns dynamic hull h into vector of pts (h is destroyed)
vector<pt> dyn_full_hull(pair<set<pt>, set<pt>>& h) {
	vector<pt> poly;
	h.first.erase(h.first.begin());
	for(pt p : h.first) poly.push_back(p);
	h.second.erase(h.second.begin());
	for(pt p : h.second) poly.push_back(-p);
	return poly;
}

/**
 * GENERAL POLYGONS
 */

//is pt p inside the (not necessarily convex) polygon given by poly
bool in_poly(pt p, vector<pt>& poly) {
	line l = line(p, {INF, INF * PI}, 1);
	bool ans = false;
	pt lst = poly.back(), tmp;
	for(pt q : poly) {
		line s = line(q, lst, 1); lst = q;
		if(on_line(p, s)) return false; //change if border not included
		else if(intsct(l, s, tmp)) ans = !ans;
	}
	return ans;
}

//area of polygon, vertices in order (cw or ccw)
ld area(vector<pt>& poly) {
	ld ans = 0;
	pt lst = poly.back();
	for(pt p : poly) ans += CRS(lst, p), lst = p;
	return abs(ans / 2);
}

//perimeter of polygon, vertices in order (cw or ccw)
ld perim(vector<pt>& poly) {
	ld ans = 0;
	pt lst = poly.back();
	for(pt p : poly) ans += abs(lst - p), lst = p;
	return ans;
}

//centroid of polygon, vertices in order (cw or ccw)
pt centroid(vector<pt>& poly) {
	ld area = 0;
	pt lst = poly.back(), ans = {0, 0};
	for(pt p : poly) {
		area += CRS(lst, p);
		ans += CRS(lst, p) * (lst + p) / (ld)3;
		lst = p;
	}
	return ans / area;
}

/**
 * CIRCLE FUNCTIONS
 */

//vector of intersection pts of two circs (up to 2) (if circles same, returns empty vector)
vector<pt> intsctCC(circ c1, circ c2) {
    pt d = c2.C - c1.C;
    ld d2 = norm(d);
    if(Z(d)) return {}; //concentric
    ld pd = (d2 + c1.R * c1.R - c2.R * c2.R) / 2;
    ld h2 = c1.R * c1.R - pd * pd / d2;
    if(h2 < 0) return {};
    pt p = c1.C + d * pd / d2, h = d * I * sqrtl(h2 / d2);
    if(Z(h)) return {p};
    return {p - h, p + h};
}

//vector of intersection pts of a line and a circ (up to 2)
vector<pt> intsctCL(circ c, line l) {
    vector<pt> v, ans;
    if(Z(dist_to(c.C, line(l.P, l.P + l.D, 0)))) v = {c.C + c.R * U(l.D), c.C - c.R * U(l.D)};
    else v = intsctCC(c, circ{refl_pt(c.C, l), c.R});
	for(pt p : v) if(on_line(p, l)) ans.push_back(p);
    return ans;
}

//external tangents of two circles (negate c2.R for internal tangents)
vector<line> circTangents(circ c1, circ c2) {
	pt d = c2.C - c1.C;
	ld dr = c1.R - c2.R, d2 = norm(d), h2 = d2 - dr * dr;
	if(Z(d2) || h2 < 0) return {};
	vector<line> ans;
	for(ld sg : {-1, 1}) {
		pt u = (d * dr + d * I * sqrt(h2) * sg) / d2;
		ans.push_back(line(c1.C + u * c1.R, c2.C + u * c2.R, 1));
	}
	if(Z(h2)) ans.pop_back();
	return ans;
}

ll type(circ a, circ b){
    if (abs(a.C - b.C) > a.R + b.R + EPS) return 1;
    if (Z(abs(a.C - b.C) - a.R - b.R)) return 5;
    if (abs(a.C - b.C) + min(a.R, b.R) < max(a.R,b.R) - EPS) return 3;
    if (Z(abs(a.C - b.C) + min(a.R, b.R) - max(a.R,b.R))) return 4;
    return 2;
}

ll ints3(vector<circ> &a){
    vector<pt> temp = intsctCC(a[0], a[1]);
    ll ans = 0;
    for (auto x: temp){
        if (Z(abs(x-a[2].C) - a[2].R)) ans++;
    }
    return ans;
}

#define G(x) ld x; cin >> x;

int main(){
    vector<circ> a;
    ll n;
    cin >> n;

    if (n == 1){
        cout << 2 << endl;
        return 0;
    }
    else if (n==2){
        for (int i = 0; i < n; i++){
            G(x) G(y) ld r; cin >> r;
            pt p = {x,y};
            circ temp = {p, r};
            a.push_back(temp);
        }
        ll fuck = type(a[0],a[1]);
        if (fuck == 2) cout << 4 << endl;
        else cout << 3 << endl;
        return 0;
    }


    for (int i = 0; i < n; i++){
        G(x) G(y) ld r; cin >> r;
        pt p = {x,y};
        circ temp = {p, r};
        a.push_back(temp);
       // cout << temp.C.X << " " << temp.C.Y << " " << temp.R << endl;
    }

    vector<ll> sol;
    for (int i = 0; i < a.size(); i++) sol.push_back(type(a[i], a[(i+1)%3]));
    sort(A(sol));
    string s = "";
    for (auto x: sol) s += to_string(x);

    map<string, ll> ans;
    ll finalans = 4;
    /*
     * todo: joe bullshit
     *
     */

    vector<ll> fives = {112, 123, 124, 125, 233, 234, 235, 445, 555};
    vector<ll> sixes = {122, 223, 244, 245, 255};
    vector<ll> seven = {224, 225};
    ans["222"] = 8;

    for (auto x: fives) ans[to_string(x)] = 5;
    for (auto x: sixes) ans[to_string(x)] = 6;
    for (auto x: seven) ans[to_string(x)] = 7;

   // cout << s << " " << ints3(a) << endl;
    if (ans.count(s)) finalans = ans[s];

    //cout <<

    if(count(s.begin(), s.end(), '2') > 1) finalans -= ints3(a);
    
    cout << finalans << '\n';


}