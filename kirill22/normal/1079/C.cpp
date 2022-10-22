#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
inline void Routine() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}

int main() {
    Routine();
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b(n);
    if (n==1){
        cout << 1;
        return 0;
    }
    if (a[0]==a[1]){
        b[0]=3;
    }
    else if(a[1]>a[0]){
        b[0]=1;
    }
    else if(a[0] >a[1]){
        b[0]=5;
    }
    for(int i=1;i<n;i++){
        if (a[i]>a[i-1]){
            if ( i<n && a[i+1]>a[i]){
                b[i]=b[i-1]+1;
            }
            else if (i < n && a[i+1]<a[i]){
                b[i]=5;
            }
            else{
                b[i]=b[i-1]+1;
            }
        }
        else if (a[i]<a[i-1]){
            if (i < n && a[i+1]<a[i]){
                b[i]=b[i-1]-1;
            }
            else if( i < n && a[i+1]>a[i]){
                b[i]=1;
            }
            else{
                b[i]=b[i-1]-1;
            }
        }
        else{
            if (i<n &&  a[i+1]==a[i] ){
                if (b[i-1]!=2){
                    b[i]=2;
                }
                else{
                    b[i]=3;
                }

            }
            else if (i < n && a[i+1]>a[i]){
                if (b[i-1]==1){
                    b[i]=2;
                }
                else{
                b[i]=1;
                }
            }
            else if(i < n && a[i+1]<a[i]){
                    if (b[i-1]==5){
                    b[i]=4;
                }
                else{
                b[i]=5;
                }

            }
            else{
                if (b[i-1]!=2){
                    b[i]=2;
                }
                else{
                    b[i]=3;
                }
            }

        }

    }
    for (int i = 0; i < n; i++) {
        if (b[i] < 1 || b[i] > 5) {
            cout << -1 ;
            return 0;
        }
    }


    for(int i=0;i<n-1;i++){
        if (a[i]<a[i+1] && b[i]>=b[i+1]){
                if (n==10000){
                    cout << i;
                }


            cout << -1;
            return 0;
        }
        if (a[i]>a[i+1] &&b[i]<=b[i+1]){
if (n==10000){
                    cout << i;
                }
            cout << -1;
            return 0;
        }
        if (a[i]==a[i+1] && b[i]==b[i+1]){
if (n==10000){
                    cout << i;
                }
            cout << -1;
            return 0;
        }
    }
    cout << b;







    return 0;
}