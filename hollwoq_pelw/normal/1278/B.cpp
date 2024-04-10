#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long a,b;
        cin >> a >> b;
        long d = abs(a-b);
        int res = sqrt(d*2);
        while ((res*(res+1)/2-d)<0 || (res*(res+1)/2-d)%2!=0) res++;
        cout << res << endl;
    }
}