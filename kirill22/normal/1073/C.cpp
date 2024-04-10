#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x,y,o,p;
    cin >> x >> y;
    int x1=abs(x),y1=abs(y);
    if ((x1+y1)>n){
        cout << -1;
        return 0;
    }
    if ((x1+y1)%2!=n%2){
        cout << -1;
        return 0;
    }
    int L=-1,R=n;
    while(R-L>1){
        ll m=(L+R)/2;
        bool flag=false;
        for(int i=0;i<n-m+1;i++){

            if (i==0){
            o=0,p=0;
            for(int u=0;u<n;u++){
                if (u<i || u>i+m-1){
                    if (s[u]=='U'){
                        p++;
                    }
                    if (s[u]=='D'){
                        p--;
                    }
                    if (s[u]=='L'){
                        o--;
                    }
                    if (s[u]=='R'){
                        o++;
                    }
                }
            }
            }
            else{
                if (s[i-1]=='U'){
                        p++;
                }
                if (s[i-1]=='D'){
                        p--;
                }
                if (s[i-1]=='L'){
                        o--;
                }
                if (s[i-1]=='R'){
                        o++;
                }
                if (s[i+m-1]=='U'){
                        p--;
                }
                if (s[i+m-1]=='D'){
                        p++;
                }
                if (s[i+m-1]=='L'){
                        o++;
                }
                if (s[i+m-1]=='R'){
                        o--;
                }
            }
            int kol=abs(x-o)+abs(y-p);
            if (kol<=m){
                flag=true;
                break;
            }

        }
        if (flag){
            R=m;
        }
        else{
            L=m;
        }
    }
    cout <<  R;





    return 0;
}