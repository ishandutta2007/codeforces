#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 112345
#define MAXM 1123456
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX
#define kada cout<<"karadola"<<endl;

int n;

bool test(int k){
    int v=0,p=0,r=n;
    while(r>0){
        //cout<<r<<" ";
        v+=min(k,r);
        r-=min(k,r);
        p+=r/10;
        r-=r/10;
        //cout<<v<<" "<<p<<endl;
    }
    return v>=p;
}

int bs(){
    int com=1,fim=1000000000000000000,meio,best=1;
    while(com<=fim){
        //cout<<meio<<endl;
        meio=com+(fim-com)/2;
        if(test(meio)){
            best=meio;
            fim=meio-1;
        }
        else com=meio+1;
    }
    return best;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    cin>>n;
    cout<<bs()<<endl;

    return 0;
}