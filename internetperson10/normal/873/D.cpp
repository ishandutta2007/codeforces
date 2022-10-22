#include <bits/stdc++.h>

using namespace std;

bool divider[100010];
int arr[100010];

void divide(int l, int r, int &n) {
    //cout << "yay! " << l << ' ' << r << ' ' << n << '\n';
    if(n==0) return;
    if(l+2>r) return;
    n-=2;
    int mid = (l+r)/2;
    divider[mid]=true;
    divide(l, mid, n);
    divide(mid, r, n);
}
int main() {
    int s, n;
    cin >> s >> n;
    if(n%2==0 || n>=(2*s)) cout << "-1";
    else {
        //cout << "yay!\n";
        for(int a=0; a<s; a++) {
            arr[a]=s-a;
        }
        n--;
        //cout << "yay!\n";
        divide(0, s, n);
        divider[s]=true;
        int prevterm=0, nextterm=0;
        //cout << "yay!\n";
        for(int a=0; a<=s; a++) {
            if(divider[a]) {
                prevterm=nextterm;
                nextterm=a;
                //cout << "divide! " << prevterm << ' ' << nextterm << '\n';
                sort(arr+prevterm, arr+(nextterm));
            }
        }
        for(int a=0; a<s; a++) {
            cout << arr[a] << ' ';
        }
    }
}