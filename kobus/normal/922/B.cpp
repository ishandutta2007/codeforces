#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    set<long long> s;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            int c=a^b;
            if(c!=0 && c<=n){
                if(c<a+b && a<b+c && b<a+c){
                    int a2=a,b2=b,c2=c;
                    if(a2>b2)swap(a2,b2);
                    if(a2>c2)swap(a2,c2);
                    if(b2>c2)swap(b2,c2);
                    s.insert(2501*2501*a2+2501*b2+c2);
                }
            }
        }
    }

    cout<<s.size()<<endl;


    return 0;

}