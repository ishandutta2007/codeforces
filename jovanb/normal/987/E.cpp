#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll br=0;
int niz[1000005];
int temp[1000005];
 
void merges(int l1, int r1, int l2, int r2){
    int n = r1-l1+r2-l2+2;
    int i1 = l1;
    int i2 = l2;
    int i = 1;
 
    while(i1 <= r1 && i2 <= r2){
        if(niz[i1] < niz[i2]){temp[i++] = niz[i1++];}
        else{
            br += r1-i1+1;
            temp[i++] = niz[i2++];
        }
    }
    while(i1 <= r1) temp[i++] = niz[i1++];
    while(i2 <= r2) temp[i++] = niz[i2++];
    for(int i=1; i<=n; i++) niz[l1+i-1] = temp[i];
}
 
void mergesort(int l, int r){
    if(l >= r) return;
    int mid = (l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    merges(l, mid, mid+1, r);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;
 
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    mergesort(1, n);
    if(!((n+br)%2)) cout << "Petr";
    else cout << "Um_nik";
    return 0;
}