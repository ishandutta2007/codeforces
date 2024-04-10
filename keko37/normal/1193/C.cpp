#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long double ld;
typedef pair <ld, ld> tocka;

const int MAXN = 4005;
const ld EPS = 1e-8;

int cnt, kraj = 2000;

struct shape {
    int br;
    tocka p[20];
    shape () {}
    shape (tocka a, tocka b, tocka c) {
        br = 3; p[0] = a; p[1] = b; p[2] = c;
    }
    shape (tocka a, tocka b, tocka c, tocka d) {
        br = 4; p[0] = a; p[1] = b; p[2] = c; p[3] = d;
    }
    shape (tocka a, tocka b, tocka c, tocka d, tocka e) {
        br = 5; p[0] = a; p[1] = b; p[2] = c; p[3] = d; p[4] = e;
    }
} sh[MAXN];

ld ccw (tocka a, tocka b, tocka c) {
    return a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y);
}

ld dist (tocka a, tocka b) {
    return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

shape input_shape () {
    shape s;
    cin >> s.br;
    for (int i=0; i<s.br; i++) {
        cin >> s.p[i].X >> s.p[i].Y;
    }
    return s;
}

void output_shape (shape s, ld dx, ld dy) {
    cout << s.br << " ";
    for (int i=0; i<s.br; i++) {
        cout << s.p[i].X + dx << " " << s.p[i].Y + dy << " ";
    }
    cout << endl;
}

vector <shape> trianguliraj (shape s) {
    vector <shape> res;
    if (s.br == 3) {
        res.push_back(s);
        return res;
    }
    for (int i=0; i<s.br; i++) {
        int a = i, b = (i + 1) % s.br, c = (i + 2) % s.br;
        if (ccw(s.p[a], s.p[b], s.p[c]) <= 0) continue;
        bool moze = 1;
        for (int j=0; j<s.br; j++) {
            if (j == a || j == b || j == c) continue;
            if (ccw(s.p[a], s.p[b], s.p[j]) <= 0) continue;
            if (ccw(s.p[b], s.p[c], s.p[j]) <= 0) continue;
            if (ccw(s.p[c], s.p[a], s.p[j]) <= 0) continue;
            moze = 0;
        }
        if (moze) {
            shape tmp;
            tmp.br = s.br - 1;
            int curr = 0;
            for (int j=0; j<s.br; j++) {
                if (j == b) continue;
                tmp.p[curr] = s.p[j]; curr++;
            }
            res = trianguliraj(tmp);
            res.push_back(shape(s.p[a], s.p[b], s.p[c]));
            break;
        }
    }
    return res;
}

int duplaj_x (int ind) {
    ld x = sh[ind].p[2].X, y = sh[ind].p[2].Y;

    sh[++cnt] = shape({0, 0}, {x, 0}, {x, y/2}, {0, y/2});
    sh[++cnt] = shape({0, y/2}, {x, y/2}, {x, y}, {0, y});

    cout << "scissors\n";
    cout << ind << " " << 2 << endl;
    output_shape(sh[cnt-1], 0, 0);
    output_shape(sh[cnt], 0, 0);

    sh[++cnt] = shape({0, 0}, {2*x, 0}, {2*x, y/2}, {0, y/2});

    cout << "tape\n";
    cout << 2 << " " << cnt-2 << " " << cnt-1 << endl;
    output_shape(sh[cnt-2], 0, 0);
    output_shape(sh[cnt-1], x, -y/2);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

int duplaj_y (int ind) {
    ld x = sh[ind].p[2].X, y = sh[ind].p[2].Y;

    sh[++cnt] = shape({0, 0}, {x/2, 0}, {x/2, y}, {0, y});
    sh[++cnt] = shape({x/2, 0}, {x, 0}, {x, y}, {x/2, y});

    cout << "scissors\n";
    cout << ind << " " << 2 << endl;
    output_shape(sh[cnt-1], 0, 0);
    output_shape(sh[cnt], 0, 0);

    sh[++cnt] = shape({0, 0}, {x/2, 0}, {x/2, y*2}, {0, y*2});

    cout << "tape\n";
    cout << 2 << " " << cnt-2 << " " << cnt-1 << endl;
    output_shape(sh[cnt-2], 0, 0);
    output_shape(sh[cnt-1], -x/2, y);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

int prav_u_prav (int a, int b) {
    while (sh[a].p[2].Y > sh[b].p[2].Y) a = duplaj_x(a);
    while (sh[a].p[2].Y < sh[b].p[2].Y / 2) a = duplaj_y(a);

    ld x1 = sh[a].p[2].X, y1 = sh[a].p[2].Y;
    ld x2 = sh[b].p[2].X, y2 = sh[b].p[2].Y;

    if (abs(x1 - x2) < EPS) return a;

    ld d1 = x1 * (y2 - y1) / y2;
    ld d2 = y2 * (x1 - x2) / x1;

    sh[++cnt] = shape({0, 0}, {x2, 0}, {x2, d2}, {d1, y1}, {0, y1});
    sh[++cnt] = shape({x2, 0}, {x1, 0}, {x2, d2});
    sh[++cnt] = shape({x1, 0}, {x1, y1}, {d1, y1});

    cout << "scissors\n";
    cout << a << " " << 3 << endl;
    output_shape(sh[cnt-2], 0, 0);
    output_shape(sh[cnt-1], 0, 0);
    output_shape(sh[cnt], 0, 0);

    sh[++cnt] = shape({0, 0}, {x2, 0}, {x2, y2}, {0, y2});

    cout << "tape\n";
    cout << 3 << " " << cnt-3 << " " << cnt-2 << " " << cnt-1 << endl;
    output_shape(sh[cnt-3], 0, 0);
    output_shape(sh[cnt-2], -x2, y1);
    output_shape(sh[cnt-1], -d1, y2 - y1);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

int nice_trokut (int ind) {
    ld a = dist(sh[ind].p[0], sh[ind].p[1]);
    ld b = dist(sh[ind].p[1], sh[ind].p[2]);
    ld c = dist(sh[ind].p[2], sh[ind].p[0]);

    if (a > b && a > c) {
        ld p = (a + (c*c - b*b)/a)/2;
        ld q = (a - (c*c - b*b)/a)/2;
        ld v = sqrt(c*c - p*p);
        sh[++cnt] = shape({0, 0}, {a, 0}, {p, v});
    } else if (b > a && b > c) {
        ld p = (b + (a*a - c*c)/b)/2;
        ld q = (b - (a*a - c*c)/b)/2;
        ld v = sqrt(a*a - p*p);
        sh[++cnt] = shape({p, v}, {0, 0}, {b, 0});
    } else {
        ld p = (c + (b*b - a*a)/c)/2;
        ld q = (c - (b*b - a*a)/c)/2;
        ld v = sqrt(b*b - p*p);
        sh[++cnt] = shape({c, 0}, {p, v}, {0, 0});
    }

    cout << "tape\n";
    cout << 1 << " " << ind << endl;
    output_shape(sh[cnt], 0, 0);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

void get_nice_trokut (shape t) {
    ld a = dist(t.p[0], t.p[1]);
    ld b = dist(t.p[1], t.p[2]);
    ld c = dist(t.p[2], t.p[0]);

    if (a > b && a > c) {
        ld p = (a + (c*c - b*b)/a)/2;
        ld q = (a - (c*c - b*b)/a)/2;
        ld v = sqrt(c*c - p*p);
        sh[kraj+2] = shape({0, 0}, {a, 0}, {p, v});
    } else if (b > a && b > c) {
        ld p = (b + (a*a - c*c)/b)/2;
        ld q = (b - (a*a - c*c)/b)/2;
        ld v = sqrt(a*a - p*p);
        sh[kraj+2] = shape({p, v}, {0, 0}, {b, 0});
    } else {
        ld p = (c + (b*b - a*a)/c)/2;
        ld q = (c - (b*b - a*a)/c)/2;
        ld v = sqrt(b*b - p*p);
        sh[kraj+2] = shape({c, 0}, {p, v}, {0, 0});
    }
}

int nice_prav (int ind) {
    ld a = dist(sh[ind].p[0], sh[ind].p[1]);
    ld b = dist(sh[ind].p[1], sh[ind].p[2]);

    sh[++cnt] = shape({0, 0}, {a, 0}, {a, b}, {0, b});

    cout << "tape\n";
    cout << 1 << " " << ind << endl;
    output_shape(sh[cnt], 0, 0);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

int nicetrokut_u_prav (int t) {
    ld a, p, q, v;
    if (sh[t].p[0] == make_pair((ld) 0, (ld) 0)) {a = sh[t].p[1].X; p = sh[t].p[2].X; v = sh[t].p[2].Y;}
    if (sh[t].p[1] == make_pair((ld) 0, (ld) 0)) {a = sh[t].p[2].X; p = sh[t].p[0].X; v = sh[t].p[0].Y;}
    if (sh[t].p[2] == make_pair((ld) 0, (ld) 0)) {a = sh[t].p[0].X; p = sh[t].p[1].X; v = sh[t].p[1].Y;}
    q = a - p;

    sh[++cnt] = shape({0, 0}, {a, 0}, {a - q/2, v/2}, {p/2, v/2});
    sh[++cnt] = shape({p/2, v/2}, {p, v/2}, {p, v});
    sh[++cnt] = shape({p, v/2}, {a - q/2, v/2}, {p, v});

    cout << "scissors\n";
    cout << t << " " << 3 << endl;
    output_shape(sh[cnt-2], 0, 0);
    output_shape(sh[cnt-1], 0, 0);
    output_shape(sh[cnt], 0, 0);

    sh[++cnt] = shape({0, 0}, {a, 0}, {a, v/2}, {0, v/2});

    cout << "tape\n";
    cout << 3 << " " << cnt-3 << " " << cnt-2 << " " << cnt-1 << endl;
    output_shape(sh[cnt-3], 0, 0);
    output_shape(shape({p/2, v/2}, {0, v/2}, {0, 0}), 0, 0);
    output_shape(shape({a, v/2}, {a - q/2, v/2}, {a, 0}), 0, 0);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

int niceprav_u_nicetro (int k, int t) {
    ld a, p, q, v;
    if (sh[t].p[0] == make_pair((ld) 0, (ld) 0)) {a = sh[t].p[1].X; p = sh[t].p[2].X; v = sh[t].p[2].Y;}
    if (sh[t].p[1] == make_pair((ld) 0, (ld) 0)) {a = sh[t].p[2].X; p = sh[t].p[0].X; v = sh[t].p[0].Y;}
    if (sh[t].p[2] == make_pair((ld) 0, (ld) 0)) {a = sh[t].p[0].X; p = sh[t].p[1].X; v = sh[t].p[1].Y;}
    q = a - p;

    sh[kraj+1] = shape({0, 0}, {a, 0}, {a, v/2}, {0, v/2});
    k = prav_u_prav(k, kraj + 1);

    sh[++cnt] = shape({0, 0}, {a, 0}, {a - q/2, v/2}, {p/2, v/2});
    sh[++cnt] = shape({p/2, v/2}, {0, v/2}, {0, 0});
    sh[++cnt] = shape({a, v/2}, {a - q/2, v/2}, {a, 0});

    cout << "scissors\n";
    cout << k << " " << 3 << endl;
    output_shape(sh[cnt-2], 0, 0);
    output_shape(sh[cnt-1], 0, 0);
    output_shape(sh[cnt], 0, 0);

    sh[++cnt] = sh[t];

    cout << "tape\n";
    cout << 3 << " " << cnt-3 << " " << cnt-2 << " " << cnt-1 << endl;
    output_shape(sh[cnt-3], 0, 0);
    output_shape(shape({p/2, v/2}, {p, v/2}, {p, v}), 0, 0);
    output_shape(shape({p, v/2}, {a - q/2, v/2}, {p, v}), 0, 0);
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

int polygon_u_prav (int ind) {
    vector <shape> tro = trianguliraj(sh[ind]);
    vector <int> koji, kvad;
    cout << "scissors\n";
    cout << ind << " " << sh[ind].br - 2 << endl;
    for (auto t : tro) {
        sh[++cnt] = t;
        koji.push_back(cnt);
        output_shape(t, 0, 0);
    }

    for (auto it : koji) {
        int curr = it;
        curr = nice_trokut(curr);
        curr = nicetrokut_u_prav(curr);
        ld b = 1e6, a = sh[curr].p[2].X * sh[curr].p[2].Y / (1e6);
        sh[kraj+1] = shape({0, 0}, {a, 0}, {a, b}, {0, b});
        kvad.push_back(prav_u_prav(curr, kraj+1));
    }

    cout << "tape\n";
    cout << kvad.size() << " ";
    for (auto k : kvad) cout << k << " ";
    cout << endl;
    ld ofs = 0;
    for (auto k : kvad) {
        output_shape(sh[k], ofs, 0);
        ofs += sh[k].p[2].X;
    }
    sh[++cnt] = shape({0, 0}, {ofs, 0}, {ofs, 1e6}, {0, 1e6});
    output_shape(sh[cnt], 0, 0);

    return cnt;
}

void prav_u_polygon (int ind) {
    vector <shape> tro = trianguliraj(sh[kraj]);
    vector <int> kvad, koji;

    cout << "scissors\n";
    cout << ind << " " << tro.size() << endl;
    ld ofs = 0;
    for (auto t : tro) {
        ld b = 1e6, a = ccw(t.p[0], t.p[1], t.p[2])/2 / (1e6);
        sh[++cnt] = shape({ofs, 0}, {ofs + a, 0}, {ofs + a, b}, {ofs, b});
        kvad.push_back(cnt);
        output_shape(sh[cnt], 0, 0);
        ofs += a;
    }

    for (int i = 0; i < tro.size(); i++) {
        shape t = tro[i];
        int k = kvad[i];
        k = nice_prav(k);
        get_nice_trokut(t);
        koji.push_back(niceprav_u_nicetro(k, kraj + 2));
    }

    cout << "tape\n";
    cout << koji.size() << " ";
    for (auto t : koji) cout << t << " ";
    cout << endl;
    for (auto t : tro) {
        output_shape(t, 0, 0);
    }
    output_shape(sh[kraj], 0, 0);
}

int main () {
    cout << fixed << setprecision(15);
    sh[0] = input_shape(); sh[kraj] = input_shape();
    int curr = polygon_u_prav(0);
    prav_u_polygon(curr);
    return 0;
}