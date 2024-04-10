#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, sol=100005;
int a[100005];
int b[100005];
pair <int, int> l[100005];
int bio[100005];

int f (int pos) {
    if (bio[pos]!=-1) return bio[pos];
    int x=lower_bound(a, a+n, a[pos]-b[pos])-a;
    bio[pos]=pos-x+f(x-1);
    return bio[pos];
}

int main () {
    memset (bio, -1, sizeof bio); bio[0]=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        l[i]=make_pair(a[i], b[i]);
    }
    sort(l, l+n);
    for (int i=0; i<n; i++) {
        a[i]=l[i].first;
        b[i]=l[i].second;
    }
    for (int i=0; i<n; i++) {
        int bla=f(i)+n-i-1;
        sol=min(sol, bla);
    }
    cout << sol;
    return 0;
}