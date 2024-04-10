#include<iostream>
#include<cstring>

using namespace std;

int n;
int l[505];
int bio[505] [505];
int inf=1000000000;

int f (int x, int y) {
    if (bio[x] [y]!=inf) return bio[x] [y];
    if (x==y) return 1;
    if (x+1==y) if (l[x]==l[y]) return 1; else return 2;
    if (l[x]==l[y]) bio[x] [y]=f(x+1, y-1);
    for (int i=x; i<y; i++) {
        bio[x] [y]=min(bio[x] [y], f(x, i)+f(i+1, y));
    }
    return bio[x] [y];
}

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l[i];
        for (int j=0; j<n; j++) {
            bio[i] [j]=inf;
        }
    }
    cout << f(0, n-1);
    return 0;
}