#include<bits/stdc++.h>
#define maxn 1010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n, a[maxn], mk[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++)
        mk[a[i]] = 1;

    int ans1 = 0;
    a[0] = 1;
    a[n+1] = 1;
    ii last;
    int eve=0, odd=0;
    priority_queue<int> p1, p2;
    for(int i=1; i<=n; i+=2)
        if( !mk[i] ) odd++;
    for(int i=2; i<=n; i+=2)
        if( !mk[i] ) eve++;
    for(int i=0; i<=n+1; i++){
        if( a[i] != 0 ){
            bool f = 1;
            if( i != 0 ){
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 0 ){
                    p2.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 1 ){
                    p1.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( f ) ans1++;
            }
            last = {a[i],i};
        }
    }
    while( !p1.empty() ){
        int u = p1.top();
        p1.pop();
        odd -= (-u);
        if( odd < 0 ) ans1 += 2;
    }
    while( !p2.empty() ){
        int u = p2.top();
        p2.pop();
        eve -= (-u);
        if( eve < 0 ) ans1 += 2;
    }

    int ans2 = 0;
    a[0] = 1;
    a[n+1] = 2;
    //ii last;
    eve=0, odd=0;
    //p1.clear(); p2.clear();
    for(int i=1; i<=n; i+=2)
        if( !mk[i] ) odd++;
    for(int i=2; i<=n; i+=2)
        if( !mk[i] ) eve++;
    for(int i=0; i<=n+1; i++){
        if( a[i] != 0 ){
            bool f = 1;
            if( i != 0 ){
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 0 ){
                    p2.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 1 ){
                    p1.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( f ) ans2++;
            }
            last = {a[i],i};
        }
    }
    while( !p1.empty() ){
        int u = p1.top();
        p1.pop();
        odd -= (-u);
        if( odd < 0 ) ans2 += 2;
    }
    while( !p2.empty() ){
        int u = p2.top();
        p2.pop();
        eve -= (-u);
        if( eve < 0 ) ans2 += 2;
    }

    int ans3 = 0;
    a[0] = 2;
    a[n+1] = 1;
    //ii last;
    eve=0, odd=0;
    //p1.clear(); p2.clear();
    for(int i=1; i<=n; i+=2)
        if( !mk[i] ) odd++;
    for(int i=2; i<=n; i+=2)
        if( !mk[i] ) eve++;
    for(int i=0; i<=n+1; i++){
        if( a[i] != 0 ){
            bool f = 1;
            if( i != 0 ){
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 0 ){
                    p2.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 1 ){
                    p1.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( f ) ans3++;
            }
            last = {a[i],i};
        }
    }
    while( !p1.empty() ){
        int u = p1.top();
        p1.pop();
        odd -= (-u);
        if( odd < 0 ) ans3 += 2;
    }
    while( !p2.empty() ){
        int u = p2.top();
        p2.pop();
        eve -= (-u);
        if( eve < 0 ) ans3 += 2;
    }

    int ans4 = 0;
    a[0] = 2;
    a[n+1] = 2;
    //ii last;
    eve=0, odd=0;
    //p1.clear(); p2.clear();
    for(int i=1; i<=n; i+=2)
        if( !mk[i] ) odd++;
    for(int i=2; i<=n; i+=2)
        if( !mk[i] ) eve++;
    for(int i=0; i<=n+1; i++){
        if( a[i] != 0 ){
            bool f = 1;
            if( i != 0 ){
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 0 ){
                    p2.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( a[i] % 2 == last.f % 2 && a[i] % 2 == 1 ){
                    p1.push(-1*(i-last.s-1));
                    f = 0;
                }
                if( f ) ans4++;
            }
            last = {a[i],i};
        }
    }
    while( !p1.empty() ){
        int u = p1.top();
        p1.pop();
        odd -= (-u);
        if( odd < 0 ) ans4 += 2;
    }
    while( !p2.empty() ){
        int u = p2.top();
        p2.pop();
        eve -= (-u);
        if( eve < 0 ) ans4 += 2;
    }

    cout << min( min( ans1, ans2) , min( ans3, ans4) ) << '\n';

    return 0;
}