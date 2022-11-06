#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(int a, int b, int c, int d){
    if(a%2==c%2&&b%2==d%2){
        return true;
    }
    return false;
}
int n;
bool ff(int x){
    if(x==1||x==n)return true;
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        int x,y;
        cin >> x >> y;
        set<int>s;
        int g = a^c^e;
        int h = b^d^f;
        pair<int,int>p;
        pair<int,int>p2;
        //cout << g << " " << h << "\n";
        if(a!=g&&b!=h){
            p = {c,d};
            p2 = {e,f};
        }
        else if(c!=g&&d!=h){
            p = {a,b};
            p2 = {e,f};
        }
        else{
            p = {a,b};
            p2 = {c,d};
        }
        bool flag = true;
        if(!check(a,b,x,y)&&!check(c,d,x,y)&&!check(e,f,x,y)){
            flag = false;
        }
        //cout << p.first << " " << p.second << "\n";
        if((ff(p.first)&&ff(p2.second))||(ff(p.second)&&ff(p2.first))){
            //cout << x << " " << y << "\n";
            if(g>=a&&g>=c&&g>=e){
                if(h>=b&&h>=d&&h>=f){
                    if(x>=g&&y>=h){
                        flag = false;
                    }
                }
                else{
                    if(x>=g&&y<=h){
                        flag = false;
                    }
                }
            }
            else{
                if(h>=b&&h>=d&&h>=f){
                    if(x<=g&&y>=h){
                        flag = false;  
                    }
                }
                else{
                    if(x<=g&&y<=h){
                        flag = false;
                    }
                }
            }
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}