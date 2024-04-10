#include<iostream>
#include<cstring>

using namespace std;

int n, maxv, maxn;
int l[5005];
int p[5005];
int sol[5005];

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l[i];
    }
    for (int i=0; i<n; i++) {
        memset(p, 0, sizeof p);
        maxv=maxn=0;
        for (int j=i; j<n; j++) {
            p[l[j]]++;
            if (p[l[j]]==maxv) {
                if (l[j]<maxn) {
                    sol[l[j]]++;
                    maxn=l[j];
                } else {
                    sol[maxn]++;
                }
            } else if (p[l[j]]>maxv) {
                sol[l[j]]++;
                maxv=p[l[j]];
                maxn=l[j];
            } else {
                sol[maxn]++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}