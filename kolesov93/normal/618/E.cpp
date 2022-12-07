#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 300333;

struct matrix {
    double a[3][3];


    void unit() {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 3; ++i) {
            a[i][i] = 1;
        }
    }

    matrix operator*(const matrix& another) const {
        matrix ans;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans.a[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    ans.a[i][j] += a[i][k] * another.a[k][j];
                }
            }
        }
        return ans;
    }
};



struct cell {
    matrix a;
    bool lazy;
    int l, r;
} a[N * 4];

void build(int x, int l, int r) {
    a[x].a.unit();
    a[x].l = l; a[x].r = r;
    a[x].lazy = false;
    if (l != r) {
        build(x + x, l, (l + r) >> 1);
        build(x + x + 1, ((l + r) >> 1) + 1, r);
    }
}

void push(int x) {
    if (a[x].lazy) {
        a[x + x].a = a[x].a * a[x + x].a;
        a[x + x].lazy = true;

        a[x + x + 1].a = a[x].a * a[x + x + 1].a;
        a[x + x + 1].lazy = true;

        a[x].a.unit();
        a[x].lazy = false;
    }
}

void modify(int x, int l, int r, const matrix& mod) {
    if (r < a[x].l || l > a[x].r) return;
    if (l <= a[x].l && a[x].r <= r) {
        a[x].a = mod * a[x].a;
        a[x].lazy = true;
        return;
    }

    push(x); 

    modify(x + x, l, r, mod);
    modify(x + x + 1, l, r, mod);
}

matrix cans;
void get(int x, int pos) {
    if (a[x].l > pos || a[x].r < pos) {
        return;
    }

    if (a[x].l == pos && a[x].r == pos) {
        cans = a[x].a;
        return;
    }

    push(x);

    get(x + x, pos);
    get(x + x + 1, pos);
}

void get_point(int pos, double& x, double& y) {
    get(1, pos);
    x = double(pos) * cans.a[0][0] + cans.a[0][2];
    y = double(pos) * cans.a[1][0] + cans.a[1][2];
}

matrix translate(double dx, double dy) {
    matrix ans;
    ans.unit();
    ans.a[0][2] = dx;
    ans.a[1][2] = dy;
    return ans;
}
matrix rotate(double grad) {
    double rad = grad / 180. * PI;

    matrix ans;
    ans.unit();
    ans.a[0][0] = cos(rad);
    ans.a[0][1] = sin(rad);
    ans.a[1][0] = -sin(rad);
    ans.a[1][1] = cos(rad);
    return ans;

}

void print(int n) {
    for (int i = 1; i <= n; ++i) {
        double x, y;
        get_point(i, x, y);
        printf("%.15lf %.15lf\n", x, y);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    build(1, 0, n);

    matrix trans;
    while (m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);

        if (x == 1) {
            double x1, y1, x2, y2;
            get_point(y - 1, x1, y1);
            get_point(y, x2, y2);

            double dx = (x2 - x1);
            double dy = (y2 - y1);
            double d = sqrt(dx * dx + dy * dy);
            dx /= d;
            dy /= d;
            
            modify(1, y, n, translate(dx * z, dy * z));
        } else {
            double dx, dy; 
            get_point(y - 1, dx, dy);

            trans = translate(dx, dy) * rotate(z) * translate(-dx, -dy);
            modify(1, y, n, trans);
        }

        double X, Y;
        get_point(n, X, Y);
        printf("%.15lf %.15lf\n", X, Y);
        //print(n);
    }

    

    return 0;
}