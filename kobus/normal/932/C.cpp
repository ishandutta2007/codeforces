#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX

int32_t main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.precision(11);
    //cout.setf(ios::fixed);
    int n,a,b;
    cin>>n>>a>>b;


    int na=0,nb;
    while(na*a<=n){
        nb=(n-(na*a))/b;
        if(na*a+nb*b==n)break;
        na++;
    }

    if(na*a+nb*b!=n){
        cout<<-1<<endl;
        return 0;
    }
    int coiso=1;
    for(int i=0;i<na;i++){
        int com=coiso;
        int fim=coiso+a-1;
        for(int j=com;j<=fim;j++){
            if(j!=fim)cout<<j+1<<" ";
            else cout<<com<<" ";
        }
        coiso+=a;
    }
    for(int i=0;i<nb;i++){
        //cout<<coiso<<endl;
        int com=coiso;
        int fim=coiso+b-1;
        //cout<<com<<" "<<fim<<endl;
        for(int j=com;j<=fim;j++){
            if(j!=fim)cout<<j+1<<" ";
            else cout<<com<<" ";
        }
        coiso+=b;
    }
    cout<<endl;

    return 0;
}