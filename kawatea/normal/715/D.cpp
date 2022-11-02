#include <cstdio>
#include <vector>

using namespace std;

int a[5] = {0, 1, 3, 6, 10};
int b[5] = {0, 1, 4, 10, 20};
vector <pair<pair<int, int>, pair<int, int> > > v;

void down(int x, int y) {
    if (x + 1 <= 50 && y <= 50) v.push_back(make_pair(make_pair(x, y), make_pair(x + 1, y)));
}

void right(int x, int y) {
    if (x <= 50 && y + 1 <= 50) v.push_back(make_pair(make_pair(x, y), make_pair(x, y + 1)));
}

int main() {
    int n = 50, m = 50, i, j;
    long long t;
    
    scanf("%I64d", &t);
    
    for (i = 0; i < 9; i++) {
        int c = i * 5;
        
        for (j = 1; j <= 4; j++) down(c + 5, c + j);
        for (j = 2; j <= 5; j++) right(c + j, c + 5);
        down(c + 6, c + 5);
        if (i > 0) right(c + 1, c + 5);
        
        for (j = 1; j <= 4; j++) down(c + 5, c + 5 + j);
        for (j = 2; j <= 5; j++) right(c + j, c + 10);
        
        for (j = 1; j <= 5; j++) right(c + j, c + 11);
    }
    
    for (i = 1; i < 10; i++) {
        int c = i * 5;
        
        down(c + 3, c + 1);
        right(c + 1, c + 4);
    }
    
    for (i = 0; i < 10; i++) {
        int x = (t >> ((9 - i) * 6)) & 63, y;
        int cx = max(i - 1, 0) * 5, cy = i * 5;
        
        if (x == 0) {
            down(cx + 5, cy + 5);
        } else if (x <= 1) {
            for (j = 1; j <= 4; j++) down(cx + 1, cy + j);
        } else if (x <= 5) {
            for (j = 1; j <= 3; j++) down(cx + 1, cy + j);
            if (x <= 4) down(cx + x, cy + 4);
        } else if (x <= 15) {
            for (j = 1; j <= 2; j++) down(cx + 1, cy + j);
            
            y = 15 - x;
            
            for (j = 4; j >= 1; j--) {
                if (y >= j) {
                    right(cx + 6 - j, cy + 3);
                    y -= j;
                }
            }
        } else if (x <= 35) {
            for (j = 1; j <= 1; j++) down(cx + 1, cy + j);
            
            y = 35 - x;
            
            for (j = 4; j >= 1; j--) {
                if (y >= a[j]) {
                    right(cx + 6 - j, cy + 2);
                    y -= a[j];
                }
            }
            
            if (y > 0) down(cx + 1, cy + 5);
        } else {
            y = 70 - x;
            
            if (y >= 20) {
                for (j = 4; j >= 2; j--) {
                    if (y >= b[j]) {
                        right(cx + 6 - j, cy + 1);
                        y -= b[j];
                    }
                }
                
                if (y == 3) {
                    right(cx + 2, cy + 4);
                } else {
                    for (j = 2; j >= 1; j--) {
                        if (y >= b[j]) {
                            down(cx + 1, cy + 6 - j);
                            y -= b[j];
                        }
                    }
                    
                    if (y > 0) right(cx + 5, cy + 1);
                }
            } else {
                if (y % 10 == 3 || y % 10 == 7) {
                    down(cx + 1, cy + 4);
                    right(cx + 2, cy + 4);
                    y -= 7;
                }
                
                for (j = 4; j >= 2; j--) {
                    if (y >= b[j]) {
                        right(cx + 6 - j, cy + 1);
                        y -= b[j];
                    }
                }
                
                for (j = 2; j >= 1; j--) {
                    if (y >= b[j]) {
                        down(cx + 1, cy + 6 - j);
                        y -= b[j];
                    }
                }
                
                if (y > 0) right(cx + 5, cy + 1);
            }
        }
    }
    
    printf("%d %d\n", n, m);
    printf("%d\n", v.size());
    for (i = 0; i < v.size(); i++) printf("%d %d %d %d\n", v[i].first.first, v[i].first.second, v[i].second.first, v[i].second.second);
    
    return 0;
}