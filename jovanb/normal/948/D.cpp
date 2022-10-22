#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2[30];
int trenind = 1;
int sled[2][10000000];
int ima[10000000];
int niz[300005];

void contrie(int node, int h, int broj){
    if(node != 0) ima[node]++;
    if(h == 30) return;
    int b = ((broj & pow2[29-h]));
    if(b != 0) b = 1;
    if(sled[b][node] == 0) sled[b][node] = trenind++;
    contrie(sled[b][node], h+1, broj);
}

int nadjen = 0;

void findtrie(int node, int h, int broj){
    if(node != 0){
        ima[node]--;
    }
    if(h == 30) return;
    int b = ((broj & pow2[29-h]));
    if(b != 0) b = 1;
    if(ima[sled[b][node]] <= 0) b = 1-b;
    nadjen += pow2[29-h]*b;
    findtrie(sled[b][node], h+1, broj);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    pow2[0] = 1;
    for(int i=1; i<=29; i++) pow2[i] = pow2[i-1]*2;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        contrie(0, 0, x);
    }
    for(int i=0; i<n; i++){
        nadjen = 0;
        findtrie(0, 0, niz[i]);
        cout << (niz[i] ^ nadjen) << " ";
    }
    return 0;
}