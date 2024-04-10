#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::cout << "1 1" << std::endl;
    
    int x = 1, y = 1;
    
    int x1 = 1, y1 = 1, x2 = 8, y2 = 8;
    
    std::string move;
    
    while (true) {
        std::cin >> move;
        
        if (move == "Done") {
            return;
        }
        
        if (move.find("Right") != std::string::npos) {
            y1++;
            y2++;
        }
        
        if (move.find("Left") != std::string::npos) {
            y1--;
            y2--;
        }
        
        if (move.find("Up") != std::string::npos) {
            x1--;
            x2--;
        }
        
        if (move.find("Down") != std::string::npos) {
            x1++;
            x2++;
        }
        
        x1 = std::max(x1, 1);
        x2 = std::min(x2, 8);
        y1 = std::max(y1, 1);
        y2 = std::min(y2, 8);
        
        assert(x1 >= x);
        
        if (x1 == x) {
            x1++;
        }
        
        if (y1 == y) {
            y1++;
        }
        
        if (y2 == y) {
            y2--;
        }
        
        assert(x1 <= x2);
        assert(y1 <= y2);
        
        int nx = x, ny = y;
        
        if (x != x1 - 1) {
            nx = x + 1;
        } else if (y1 > 1 && y1 - 1 != y) {
            ny = y1 - 1;
        } else if (y2 < 8 && y2 + 1 != y) {
            ny = y2 + 1;
        } else if (y2 - y1 == 6) {
            ny = 2;
        } else {
            ny = 1;
        }
        
        x = nx;
        y = ny;
        
        std::cout << x << " " << y << std::endl;
    }
}

int main() {
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}