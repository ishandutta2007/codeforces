#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[10], r[10];
int n;

int pw3[10];
vector<int> msk;

double go(int price, int m) {
    int mm = m;
    int nl=0, ne=0, ng=0;
    double tp = 1;
    FO(i,0,n) {
        int choice = mm%3;
        mm /= 3;

        if (choice == 0) {
            nl++;
            tp *= max(min(price,r[i]+1)-l[i],0) / 1. / (r[i]-l[i]+1);
        } else if (choice == 1) {
            ne++;
            if (l[i] <= price && price <= r[i]) tp *= 1. / (r[i]-l[i]+1);
            else tp = 0;
        } else {
            ng++;
            tp *= max(r[i]-max(price,l[i]-1),0) / 1. / (r[i]-l[i]+1);
        }
    }
    if (ng == 1 && ne != 0) return tp;
    else if (ng == 0 && ne > 1) return tp;
    else return -1e4;
}

int main() {
    scanf("%d", &n);
    pw3[0] = 1;
    for (int i = 1; i < 10; i++) {
        pw3[i] = pw3[i-1]*3;
    }
    FO(i,0,n) scanf("%d %d", l+i, r+i);
    double res = 0;
    for (int price = 1; price <= 10000; price++) {
        double prob = 0;
        if (msk.empty()) {
            FO(m,0,pw3[n]) {
                double tp = go(price, m);
                if (tp > -1) {
                    prob += tp;
                    msk.push_back(m);
                }
            }
        } else {
            for (int m : msk) {
                double tp = go(price, m);
                if (tp > -1) {
                    prob += tp;
                }
            }
        }
        res += prob * price;
    }
    printf("%.12lf\n", res);
}