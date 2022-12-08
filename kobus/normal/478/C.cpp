#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 112
#define int long long
#define INF LLONG_MAX/20
#define double long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007

int a,b,c;

bool test(int tot){
    int at=tot*3;
    at-=min(2*tot,a);
    at-=min(2*tot,b);
    at-=min(2*tot,c);
    return at<=0;
}

int bsearch(){
    int com=0,fim=INF,meio,best=0;
    while(com<=fim){
        meio=(com+fim)/2;
        if(test(meio)){
            best=meio;
            com=meio+1;
        }
        else fim=meio-1;
    }
    return best;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c;
    cout<<bsearch()<<endl;

    return 0;
}