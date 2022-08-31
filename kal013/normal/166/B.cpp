/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
istream& operator >> (istream &is, T_container &v) { 
   for(T &x : v) is >> x; return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
   return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator << (ostream &os, const T_container &v) { 
   os << '{'; string sep; 
   for (const T &x : v) os << sep << x, sep = ", "; 
   return os << '}'; 
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{"; string sep;
    while(!U.empty()){
        out << sep << U.front(); sep = ", "; U.pop();
    }
    return (out << "}");
}


#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
         int count_open = 0, len = 1;
         for(int k = 1; ; ++k){
            char cur = *(names + k);
            count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));
            if (cur == ',' && count_open == 0){
               const char* comma = names + k;
               cerr.write(names, len) << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
    }
#else
    #define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------------Code begins----------------------------------/*/



namespace Geometry{
	template<typename T>
	inline typename enable_if<!is_floating_point<T>::value, bool>::type less_compare(const T& a, const T& b){
		return a < b;
	}
	template<typename T>
	inline typename enable_if<!is_floating_point<T>::value, bool>::type equal_compare(const T& a, const T& b){
		return a == b;
	}
	template<typename T>
	inline typename enable_if<!is_floating_point<T>::value, bool>::type greater_compare(const T& a, const T& b){
		return a > b;
	}

	constexpr long double eps = 1e-10;
	template<typename T>
	inline typename enable_if<is_floating_point<T>::value, bool>::type less_compare(const T& a, const T& b){
		return a + eps < b;
	}
	template<typename T>
	inline typename enable_if<is_floating_point<T>::value, bool>::type equal_compare(const T& a, const T& b){
		return fabs(a - b) < eps;
	}
	template<typename T>
	inline typename enable_if<is_floating_point<T>::value, bool>::type greater_compare(const T& a, const T& b){
		return a > b + eps;
	}

	template<typename T>
	struct point{
    public:
		T x, y;
		point(T _x = T{}, T _y = T{}): x(_x), y(_y) {}
		point(const initializer_list<T>& _a): x(*_a.begin()), y(*(_a.begin() + 1)) { 
            assert (_a.size() == 2);
        }

        template<typename U>
        explicit operator point<U>() const { // [-MIN, MAX] 
            return point<U>(static_cast<U>(x), static_cast<U>(y));
        }
        void swap(point& other) {  std::swap(x, other.x); std::swap(y, other.y); }
		point& operator += (const point& p) {
			x += p.x; y += p.y; return *this;
		}
		point& operator -= (const point& p){
			x -= p.x; y -= p.y; return *this;
		}
		point operator + (const point& p) const {
			return point(x + p.x, y + p.y);
		}
		point operator - (const point& p) const {
			return point(x - p.x, y - p.y);
		}
		template<typename U>
		point operator * (const U& c) const {
			return point(x * c, y * c);
		}
		template<typename U>
		point& operator *= (const U& c) {
			x *= c; y *= c; return *this;
		}
		template<typename U>
		point operator / (const U& c) const {
			return point(x / c, y / c);
		}
		template<typename U>
		point& operator /= (const U& c) {
			x /= c; y /= c; return *this;
		}
        point rotateCCW90() const {
            return point(-y, x);
        }
        point rotateCW90() const {
            return point(y, -x);
        } 
        template<typename U, typename Q>
        point<U> rotateCCW(const Q& _angle) {
            Q cosine = cos(_angle), sine = sin(_angle);
            return point<U>(static_cast<U>(x * cosine - y * sine), static_cast<U>(x * sine + y * cosine));
        }
        template<typename U>
        inline typename enable_if<is_floating_point<U>::value, U>::type norm() const {
            return sqrtl(static_cast<U>(x) * static_cast<U>(x) + static_cast<U>(y) * static_cast<U>(y));
        }
        template<typename U>
        inline U abs() const {
            return (static_cast<U>(x) * static_cast<U>(x) + static_cast<U>(y) * static_cast<U>(y));
        }
        template<typename U>
        inline U dist2(const point& p) const {
            return (static_cast<U>(p.x - x) * static_cast<U>(p.x - x) + static_cast<U>(p.y - y) * static_cast<U>(p.y - y));
        }
        template<typename U>
        inline U dist(const point& p) const {
            return sqrtl(this -> dist2(p));
        }
		template<typename U>
		inline U dot(const point& p) const {
			return static_cast<U>(x) * static_cast<U>(p.x) + static_cast<U>(y) * static_cast<U>(p.y); 
		}
		template<typename U>
		inline U cross(const point<T>& p) const {
			return static_cast<U>(x) * static_cast<U>(p.y) - static_cast<U>(p.x) * static_cast<U>(y); 
		}
		inline bool operator < (const point &p) const { 
			return less_compare<T>(x, p.x) || (equal_compare<T>(x, p.x) && less_compare<T>(y, p.y));
		}
		inline bool operator == (const point &p) const { 
			return equal_compare<T>(x, p.x) && equal_compare<T>(y, p.y);
		}
        inline bool operator != (const point &p) const { 
            return !equal_compare<T>(x, p.x) || !equal_compare<T>(y, p.y);
        }
		inline bool operator > (const point &p) const { 
			return greater_compare<T>(x, p.x) || (equal_compare<T>(x, p.x) && greater_compare<T>(y, p.y));
		}
		inline bool operator <= (const point &p) const { 
			return !(*this > p);
		}
		inline bool operator >= (const point& p) const {
			return !(*this < p);
		}
		friend istream& operator >> (istream& is, point& p){
			return is >> p.x >> p.y;
		}
		friend ostream& operator << (ostream& os, const point& p) {
			return os << "(" << p.x << ", " << p.y << ")";
		}


	};

    // returns 1 if p to q is counterclock wise (wrt origin). 0 if collinear, -1 otherwise.
    template<typename U>
    inline typename enable_if<is_floating_point<U>::value, int32_t>::type ccw(const point<U>& p, const point<U>& q) {
        U cross_prod = p. template cross<U>(q);
        return less_compare<U>(cross_prod, 0) ? -1 : (equal_compare<U>(cross_prod, 0) ? 0 : 1);                
    }
    inline int32_t ccw(const point<int32_t>& p, const point<int32_t>& q){
        int64_t cross_prod = p. template cross<int64_t>(q);
        return (cross_prod < 0 ? -1 : (cross_prod == 0 ? 0 : 1));
    }
    inline int32_t ccw(const point<int64_t>& p, const point<int64_t>& q){
        #ifdef __SIZEOF_INT128__
            __int128_t _cross_prod = p. template cross<__int128_t>(q);
            return (_cross_prod < 0 ? -1 : (_cross_prod == 0 ? 0 : 1));
        #else
            long double double_value =  p.x * (long double) q.y -  q.x * (long double) p.y;
            if (abs(double_value) > 1e18){
                return double_value > 0 ? 1 : -1;
            }
            uint64_t uint64_value = p.x * (uint64_t) q.y -  q.x * (uint64_t) p.y;
            if (uint64_value == 0)
                return 0;
            return uint64_value >> 63 ? -1: 1;
        #endif
    }
    template<typename U>
    inline int32_t ccw(const point<U>& p, const point<U>& q, const point<U>& origin) {
        return ccw(p - origin, q - origin);
    }
    template<typename T>
    struct Line{
        point<T> a, ab;
    };


    template<typename T>
    struct Polygon{
    public:
        vector<point<T>> a;
        Polygon(const vector<point<T>>& _a): a(_a) {}
        Polygon(int n = 0): a(n) {}
        Polygon(const initializer_list<point<T>>& _a): a(_a) {}

        const size_t size() const {
            return a.size();
        }
        inline auto begin() const {
            return a.begin();
        }
        inline auto end() const {
            return a.end();
        }
        // int winding_number(const point<T>& q) {
        //       // int n = static_cast<int>(a.size()), windingNumber = 0;
              

        //       // for (int i = 0; i < n; ++i) {
        //       //   if (point == poly[i]) return 0;
        //       //   int j = (i + 1  == n ? 0 : i + 1);
                
        //       //   if (poly[i].y == point.y && poly[j].y == point.y) {
        //       //     if (min(poly[i].x, poly[j].x) <= point.x &&
        //       //         point.x <= max(poly[i].x, poly[j].x)) return 0;
        //       //   } else {
        //       //     bool below = poly[i].y < point.y;
        //       //     if (below != (poly[j].y < point.y)) {
        //       //       auto orientation = ccw(point, poly[j], poly[i]);
        //       //       if (orientation == 0) return 0;
        //       //       if (below == (orientation > 0)) windingNumber += below ? 1 : -1;
        //       //     }
        //       //   }
        //       // }
        //       // return windingNumber == 0 ? 1 : -1;
        // }

        friend istream& operator >> (istream& is, Polygon& p){
            return is >> p.a;
        }
        friend ostream& operator << (ostream& os, const Polygon& p){
            return os << p.a;
        }
            
        template<typename U>
        U doubled_signed_area() const {
            U ans = 0;
            const int n = static_cast<int>(a.size());
            for(int i = 0; i < n; ++i){
                int j = (i == n - 1 ? 0 : i + 1);
                ans += a[i]. template cross<U>(a[j]);
            }
            return ans;
        }

        template<typename U>
        inline U signed_area() const {
            return doubled_signed_area<U>() / 2;
        }

        template<typename U>
        inline U doubled_area() const {
            U ans = doubled_signed_area<U>();
            return (ans < 0 ? -ans : ans);
        }

        template<typename U>
        inline U area() const {
            return doubled_area<U>() / 2;
        }

        // True if orientation of a simple polygon is counter-clockwise or n <= 2.
        bool is_ccw() const {
          int n = static_cast<int>(a.size());
          int i = static_cast<int>(min_element(a.begin(), a.end()) - a.begin());
          int orient = ccw(a[(i == 0 ? n - 1 : i - 1)], a[(i + 1 == n ? 0 : i + 1)], a[i]);
          assert (n <= 2 || orient != 0);
          return (n <= 2 || orient < 0);
        }


    };

    template<typename T>
    struct ConvexPolygon: public Polygon<T>{
        private:

        inline void setup(bool is_sorted) {
            const int n = this -> a.size();
            if (n <= 1){
                top = 0;
                return;
            }

            if (!is_sorted) {
                sort(this -> a.begin(), this -> a.end());
            }
            vector<point<T>> hull; hull.reserve(n);

            for(int phase = 0; phase < 2; ++phase){
                size_t original = hull.size();
                for(const auto& pt: this -> a){
                    while (hull.size() >= original + 2 && ccw(hull[hull.size() - 2], hull.back(), pt) <= 0)
                        hull.pop_back();
                    hull.push_back(pt);
                }
                assert (hull.size() >= original + 2);
                if (phase == 0){
                    top = static_cast<int>(hull.size()) - 1;
                    reverse(this -> a.begin(), this -> a.end());
                }
                hull.pop_back();
            }
            if (hull[0] == hull.back()){
                assert (hull.size() == 2);
                hull.pop_back();
                top = 0;
            }
            assert (hull[top] == *max_element(hull.begin(), hull.end()));
            swap(this -> a, hull);
        }

        public:
        int top;

        ConvexPolygon(const vector<point<T>>& _a, const bool is_sorted = false):  Polygon<T>(_a) { setup(is_sorted); }
        ConvexPolygon(int n = 0): Polygon<T>(n) {}
        ConvexPolygon(const initializer_list<point<T>>& _a, const bool is_sorted = false):  Polygon<T>(_a) {setup(is_sorted);}
        ConvexPolygon(const Polygon<T>& _a, const bool is_sorted = false): Polygon<T>(_a) {setup(is_sorted);}

        // //1 for outside and 0 for on/ -1 inside
        int pointInConvexPolygon(const point<T>& point) {
            if (point < this -> a[0] || point > this -> a[top]) return 1;
            int orient = ccw(point, this -> a[top], this -> a[0]);
            if (orient == 0){
                if (point == this -> a[top] || point == this -> a[0]){
                    return 0;
                }
                return (top <= 1 || (top + 1 == this -> a.size())) ? 0 : -1;
            }
            else if (orient > 0) { // below a[0] --- a[top].
                auto itDown = lower_bound(this -> a.begin() + 1, this -> a.begin() + top, point);
                return ccw(point, itDown[0], itDown[-1]);
            }
            else{
                auto itUp = upper_bound(this -> a.rbegin(), this -> a.rend() - top - 1, point);
                return ccw(itUp[0], point, (itUp == this -> a.rbegin() ? this -> a[0] : itUp[-1]));
            }
        }

        template <class U>
        inline U rotatingCalipers_squared() const { // UNTESTED
            const int n = static_cast<int>(this -> a.size());
            U ans = 0;
            for(int i = 0, j = top; i < j; ++i){
                while (true){
                    ans = max(ans, this -> a[i]. template dist2<U>(this -> a[j]));
                    int nx_j = (j + 1 == n ? 0 : j + 1);
                    if (ccw(this -> a[i + 1] - this -> a[i], this -> a[nx_j] - this -> a[j]) >= 0) 
                        break;
                    j = nx_j;
                }
            }
            return ans;
        }

        friend istream& operator >> (istream& is, ConvexPolygon& p){
            is >> p.a;
            p.setup(false);
            return is;
        }

        bool is_ccw() const {
            return (this -> a.size() <= 2 || ccw(this -> a[0], this -> a[2], this -> a[1]) < 0);
        }

        vector<point<T>> minkowski_sum_vec(const vector<point<T>>& other) const {
            int i = 0, j = 0;

            const int n = this -> size(), m = other.size();

            vector<point<T>> ans; ans.reserve(n + m);
            int crossed = 0;
            while (crossed < 2){
                ans.push_back(this -> a[i] + other[j]);
                int next_i = (i + 1 == n ? 0 : i + 1), next_j = (j + 1 == m ? 0 : j + 1);
                int orient = ccw(this -> a[next_i] - this -> a[i], other[next_j] - other[j]);
                if (orient >= 0){
                    crossed += (next_i < i);
                    i = next_i;
                }
                if (orient <= 0){
                    crossed += (next_j < j);
                    j = next_j;
                }
            }
            return ans;
        }

        inline ConvexPolygon<T> minkowski_sum(const ConvexPolygon<T>& other) const {
            ConvexPolygon<T> final;
            final.a = minkowski_sum_vec(other.a);
            final.top = static_cast<int>(max_element(final.a.begin(), final.a.end()) - final.a.begin());
            return final;
        }
//         emplate <class F>
// F maxDist2(const Polygon<F>& poly) {
//   int n = static_cast<int>(poly.size());
//   F res = F(0);
//   for (int i = 0, j = n < 2 ? 0 : 1; i < j; ++i)
//     for (;; j = next(j, n)) {
//       res = max(res, dist2(poly[i], poly[j]));
//       if (ccw(poly[i+1] - poly[i], poly[next(j, n)] - poly[j]) >= 0) break;
//     }
//   return res;
// }
    };
};


// // project point c onto line (not segment) through a and b assuming a != b
// pt ProjectPointLine(pt a, pt b, pt c) {
//     return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}
// // project point c onto line segment through a and b (closest point on line segment)
// pt ProjectPointSegment(pt a, pt b, pt c) {
//     ld r = dot(b-a,b-a); if (eq(r,0)) return a;//a and b are same
//     r = dot(c-a, b-a)/r;if (lt(r,0)) return a;//c on left of a
//     if (gt(r,1)) return b; return a + (b-a)*r;}
// // compute distance from c to segment between a and b
// ld DistancePointSegment(pt a, pt b, pt c) {
//     return sqrt(dist2(c, ProjectPointSegment(a, b, c)));}
// // compute distance from c to line between a and b
// ld DistancePointLine(pt a, pt b, pt c) {
//     return sqrt(dist2(c, ProjectPointLine(a, b, c)));}
// // determine if lines from a to b and c to d are parallel or collinear
// bool LinesParallel(pt a, pt b, pt c, pt d) { 
//     return eq(cross(b-a, c-d),0); }
// bool LinesCollinear(pt a, pt b, pt c, pt d) { 
//     return LinesParallel(a, b, c, d) && eq(cross(a-b, a-c),0) && eq(cross(c-d, c-a),0);}
// // determine if line segment from a to b intersects with line segment from c to d
// bool SegmentsIntersect(pt a, pt b, pt c, pt d) {
//     if (LinesCollinear(a, b, c, d)) {
//         //a->b and c->d are collinear and have one point common
//         if(eq(dist2(a,c),0)||eq(dist2(a,d),0)||eq(dist2(b,c),0)||eq(dist2(b,d),0)) return true;
//         if(gt(dot(c-a,c-b),0)&&gt(dot(d-a,d-b),0)&&gt(dot(c-b,d-b),0)) return false;
//         return true;}
//     if(gt(cross(d-a,b-a)*cross(c-a,b-a),0)) return false;//c,d on same side of a,b
//     if(gt(cross(a-c,d-c)*cross(b-c,d-c),0)) return false;//a,b on same side of c,d
//     return true;}
// // compute intersection of line passing through a and b
// // with line passing through c and d,assuming that **unique** intersection exists;
// //*for segment intersection,check if segments intersect first
// pt ComputeLineIntersection(pt a,pt b,pt c,pt d){
//     b=b-a;d=c-d;c=c-a;//lines must not be collinear
//     assert(gt(dot(b, b),0)&&gt(dot(d, d),0));
//     return a + b*cross(c, d)/cross(b, d);}
// //returns true if point a,b,c are collinear and b lies between a and c
// bool between(pt a,pt b,pt c){
//     if(!eq(cross(b-a,c-b),0))return 0;//not collinear
//     return le(dot(b-a,b-c),0); }
// //compute intersection of line segment a-b and c-d
// pt ComputeSegmentIntersection(pt a,pt b,pt c,pt d){
//     if(!SegmentsIntersect(a,b,c,d))return {INF,INF};//don't intersect
//     //if collinear then infinite intersection points, this returns any one
//     if(LinesCollinear(a,b,c,d)){if(between(a,c,b))return c;if(between(c,a,d))return a;return b;}
//     return ComputeLineIntersection(a,b,c,d); }
// // compute center of circle given three points - *a,b,c shouldn't be collinear
// pt ComputeCircleCenter(pt a,pt b,pt c){
//     b=(a+b)/2;c=(a+c)/2;
//     return ComputeLineIntersection(b,b+RotateCW90(a-b),c,c+RotateCW90(a-c));}
// //point in polygon using winding number -> returns 0 if point is outside
// //winding number>0 if point is inside and equal to 0 if outside
// //draw a ray to the right and add 1 if side goes from up to down and -1 otherwise
// bool PointInPolygon(const vector<pt> &p,pt q){
//     int n=p.size(),windingNumber=0;
//     for(int i=0;i<n;++i){
//         if(eq(dist2(q,p[i]),0)) return 1;//q is a vertex
//         int j=(i+1)%n;
//         if(eq(p[i].y,q.y)&&eq(p[j].y,q.y)) {//i,i+1 vertex is vertical
//             if(le(min(p[i].x,p[j].x),q.x)&&le(q.x,max(p[i].x, p[j].x))) return 1;}//q lies on boundary
//         else {
//             bool below=lt(p[i].y,q.y);
//             if(below!=lt(p[j].y,q.y)) {
//                 auto orientation=orient(q,p[j],p[i]);
//                 if(orientation==0) return 1;//q lies on boundary i->j
//                 if(below==(orientation>0)) windingNumber+=below?1:-1;}}}
//     return windingNumber==0?0:1;
// }
// // determine if point is on the boundary of a polygon
// bool PointOnPolygon(const vector<pt> &p,pt q) {
//     for (int i = 0; i < p.size(); i++) 
//         if (eq(dist2(ProjectPointSegment(p[i],p[(i+1)%p.size()],q),q),0)) return true;
//     return false;}
// // Compute area or centroid of any polygon (coordinates must be listed in cw/ccw
// //fashion.The centroid is often known as center of gravity/mass
// ld ComputeSignedArea(const vector<pt> &p) {
//     ld ans=0; for(int i = 0; i < p.size(); i++) {
//         int j = (i+1) % p.size();ans+=cross(p[i],p[j]);
//     } return ans / 2.0;}
// ld ComputeArea(const vector<pt> &p) {
//     return fabs(ComputeSignedArea(p)); }
// // compute intersection of line through points a and b with
// // circle centered at c with radius r > 0
// vector<pt> CircleLineIntersection(pt a, pt b, pt c, ld r) {
//     vector<pt> ret; b = b-a;a = a-c;
//     ld A = dot(b, b),B = dot(a, b),C = dot(a, a) - r*r,D = B*B - A*C;
//     if (lt(D,0)) return ret;    //don't intersect
//     ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
//     if (gt(D,0)) ret.push_back(c+a+b*(-B-sqrt(D))/A);
//     return ret;}
// // compute intersection of circle centered at a with radius r
// // with circle centered at b with radius R
// vector<pt> CircleCircleIntersection(pt a, pt b, ld r, ld R) {
//     vector<pt> ret;
//     ld d = sqrt(dist2(a, b)),d1=dist2(a,b);
//     pt inf(INF,INF);
//     if(eq(d1,0)&&eq(r,R)){ret.pb(inf);return ret;}//circles are same return (INF,INF) 
//     if(gt(d,r+R) || lt(d+min(r, R),max(r, R)) ) return ret; 
//     ld x = (d*d-R*R+r*r)/(2*d),y = sqrt(r*r-x*x);
//     pt v = (b-a)/d;
//     ret.push_back(a+v*x + RotateCCW90(v)*y);
//     if (gt(y,0)) ret.push_back(a+v*x - RotateCCW90(v)*y);
//     return ret;}
// ld CircleCircleIntersectionArea(pt c1,ld r1,pt c2,ld r2){
//     if(lt(r1,r2))swap(c1,c2),swap(r1,r2);
//     ld d=dist2(c1,c2),d1=dist(c1,c2);
//     if(le(r1+r2,d1))return 0;
//     if(ge(r1-r2,d1))return PI*r2*r2;
//     ld alfa=acos((d+r1*r1-r2*r2)/(2*d1*r1));
//     ld beta=acos((d+r2*r2-r1*r1)/(2*d1*r2));
//     return alfa*r1*r1+beta*r2*r2-sin(2*alfa)*r1*r1/2-sin(2*beta)*r2*r2/2;}
// //compute centroid of simple polygon by dividing it into disjoint triangles
// //and taking weighted mean of their centroids (Jerome)
// pt ComputeCentroid(const vector<pt> &p) {
//     pt c(0,0),inf(INF,INF);
//     ld scale = 6.0 * ComputeSignedArea(p);
//     if(p.empty())return inf;//empty vector
//     if(eq(scale,0))return inf;//all points on straight line
//     for (int i = 0; i < p.size(); i++){
//         int j = (i+1) % p.size();
//         c = c + (p[i]+p[j])*cross(p[i],p[j]);}
//     return c / scale;}
// // tests whether or not a given polygon (in CW or CCW order) is simple
// bool IsSimple(const vector<pt> &p) {
//     for (int i = 0; i < p.size(); i++) {
//         for (int k = i+1; k < p.size(); k++) {
//             int j=(i+1)%p.size();int l=(k+1)% p.size();
//             if (i == l || j == k) continue;
//             if (SegmentsIntersect(p[i], p[j], p[k], p[l])) 
//                 return false;}}
//     return true;}
// /*point in convex polygon
// ****bottom left point must be at index 0 and top is the index of upper right vertex
// ****and counter clockwise if not call make_hull once*/
// int pointinConvexPolygon(vector<pt>& poly,pt point, int top) {
//     if (point < poly[0] || point > poly[top]) return 1;//1 for outside and 0 for on/ -1 inside
//     auto orientation = orient(point, poly[top], poly[0]);
    
//     if (orientation == 0) {
//         if (point == poly[0] || point == poly[top]) return 0;
//         return top == 1 || top + 1 == poly.size() ? 0 : -1;//checks if point lies on boundary when
//         //bottom and top points are adjacent
//     } else if (orientation < 0) {
//         auto itRight = lower_bound(poly.begin() + 1, poly.begin() + top, point);
//         return orient(itRight[0], point, itRight[-1]);
//         } else {
//         auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
//         return (orient(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
//         }
// }

//Line polygon intersection: check if given line intersects any side of polygon
//if yes then line intersects. If no, then check if its midpoint is inside polygon
//if midpoint is inside then line is inside else outside


using namespace Geometry;


//point in polygon using winding number -> returns 0 if point is outside
//winding number>0 if point is inside and equal to 0 if outside
//draw a ray to the right and add 1 if side goes from up to down and -1 otherwise
// bool PointInPolygon(const vector<pt> &p,pt q){
//     int n=p.size(),windingNumber=0;
//     for(int i=0;i<n;++i){
//         if(eq(dist2(q,p[i]),0)) return 1;//q is a vertex
//         int j=(i+1)%n;
//         if(eq(p[i].y,q.y)&&eq(p[j].y,q.y)) {//i,i+1 vertex is vertical
//             if(le(min(p[i].x,p[j].x),q.x)&&le(q.x,max(p[i].x, p[j].x))) return 1;}//q lies on boundary
//         else {
//             bool below=lt(p[i].y,q.y);
//             if(below!=lt(p[j].y,q.y)) {
//                 auto orientation=orient(q,p[j],p[i]);
//                 if(orientation==0) return 1;//q lies on boundary i->j
//                 if(below==(orientation>0)) windingNumber+=below?1:-1;}}}
//     return windingNumber==0?0:1;
// }

void solve(){
    int n, m;
    cin >> n;
    ConvexPolygon<long long> a(n);
    cin >> a;
    cin >> m;
    Polygon<long long> b(m);
    cin >> b;

    for(auto x: b){
        int y = a.pointInConvexPolygon(x);
        if (y >= 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

	// point<double> a(1,0);
 //    point<double> b(0, 1);
 //    trace(ccw(a, b));
 //    trace(b);
 //    // trace(a - b);
	// // trace(a < b);
	// // a *= 2;
	// // a += 3;
	// // trace(a);
 //    int n;
 //    cin >> n;
 //    Polygon<int> _q(n);
 //    cin >> _q;
 //    ConvexPolygon<int> q(_q);
 //    cin >> q;
 //    trace(q, _q.is_ccw(), _q);
 //    trace(q.area<int>());
 //    trace(q.rotatingCalipers_squared<long long>());

 //    assert (q.is_ccw());
 //    ConvexPolygon t = q;
    // ConvexPolygon<int> z = {{4, 5}, {2, 3}};
    // trace(q, q.top);
    // trace(z, z.top);
 //    // trace(z.double_signed_area<double>());
 //    trace(z);
 //    trace(a.cross<int>(b));
}  

int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}