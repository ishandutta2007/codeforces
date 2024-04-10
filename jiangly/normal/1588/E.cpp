#include <bits/stdc++.h>

using i64 = long long;

using Point = std::complex<i64>;

constexpr long double Pi = std::atan2(0, -1);

#define x real
#define y imag

i64 dot(const Point &a, const Point &b) {
    return (std::conj(a) * b).x();
}

i64 cross(const Point &a, const Point &b) {
    return (std::conj(a) * b).y();
}

long double angle(const Point &a) {
    return std::atan2(a.y(), a.x());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, R;
    std::cin >> n >> R;
    
    std::vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        p[i] = {x, y};
    }
    
    std::vector ok(n, std::vector<bool>(n));
    
    for (int s = 0; s < n; s++) {
        long double l = 0, len = 2 * Pi;
        
        for (int i = 0; i < n; i++) {
            if (dot(p[i] - p[s], p[i] - p[s]) <= 1LL * R * R) {
                continue;
            }
            
            auto dist = std::sqrt(dot(p[i] - p[s], p[i] - p[s]));
            auto theta = std::asin(R / dist);
            auto ang = angle(p[i] - p[s]);
            long double L = ang - theta - l;
            long double R = ang + theta - l;
            
            if (len == 2 * Pi) {
                l = L;
                if (l < 0) {
                    l += 2 * Pi;
                }
                len = R - L;
                continue;
            }
            
            if (R < 0) {
                L += 2 * Pi;
                R += 2 * Pi;
            }
            
            if (L > len) {
                L -= 2 * Pi;
                R -= 2 * Pi;
            }
            
            L = std::max(0.0L, L);
            R = std::min(R, len);
            if (L > R) {
                len = -1;
                break;
            }
            
            len = R - L;
            l += L;
            if (l >= 2 * Pi) {
                l -= 2 * Pi;
            }
        }
        
        if (len < 0) {
            continue;
        }
        
        for (int i = 0; i < n; i++) {
            if (s == i) {
                continue;
            }
            
            auto ang = angle(p[i] - p[s]) - l;
            if (ang < 0) {
                ang += 2 * Pi;
            }
            if (0 <= ang && ang <= len) {
                ok[s][i] = true;
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ok[i][j] && ok[j][i]) {
                res++;
            }
        }
    }
    
    std::cout << res << "\n";
    
    return 0;
}